/*
 * This file is part of the VisaDevices library project.
 * Copyright (c) 2019-2023 Frank Zimdars.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "system/VisaSession.h"
#include "cmd_set.h"
#include "cmd_get.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "device_types.h"

/*
 * Limitations:
 * only value with single data can be read/write
 * datasets with multiple (like waveforms) cannot be read!
 */

/*
 * Arguments:
 * vd_command.exe <ADDR> <DEV_ID> <DEV_TYPE> <MODE> <CHANNEL> <UNIT> <VALUE>
 * Example:
 * vd_command.exe TCPIP0::192.168.10.26::inst0::INSTR 12345678 1 s 1 U 2.5
 */

int main(int argc, char *argv[])
{
    //check the given arguments
    if(argc != 8){
        std::cout << "vd-command" << std::endl;
        std::cout << "Error: Invalid arguments!" << std::endl;
        std::cout << "Required: <ADDR> <DRIVER_ID> <DEVICE_TYPE> <DIR> <CH> <UNIT> <VAL>" << std::endl;
        std::cout << std::endl;
        std::cout << "<ADDR>: Visa Address" << std::endl;
        std::cout << "<DRIVER_ID>: Driver id (see documentation)" << std::endl;
        std::cout << "<DEVICE_TYPE>: Type of the device (e.g.: 1 = power supply)" << std::endl;
        std::cout << "<DIR>: Direction (g=get, s=set)" << std::endl;
        std::cout << "<CH>: Channel at the device" << std::endl;
        std::cout << "<UNIT>: Parameter (u=voltage, i=current,...)" << std::endl;
        std::cout << "<VAL>: Value (ignored when dir=get)" << std::endl;
        return -1;
    }

    VisaSession* session = visa_session_open();
    VisaHandle* hDev = visa_device_connect(session,argv[1],0,0);

    //TODO: error handling on user inputs
    int dev_id = atoi(argv[2]);
    device_type dev_type = static_cast<device_type>(atoi(argv[3]));
    char mode = *argv[4];
    int channel = atoi(argv[5]);
    char unit = *argv[6];
    double value = atof(argv[7]);

    visa_device_set_driver(hDev,dev_id);

    if(mode == 's'){
        cmd_set_generic(hDev,  dev_type, channel, value, unit);
    }else{
        double ret = cmd_get_generic(hDev,  dev_type, channel, value, unit);
        printf("RET:%f",ret);
    }

}
