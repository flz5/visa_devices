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

#include <iostream> 
#include <iomanip>
#include "ui_devices.h"
#include "ui.h"

/**
 * Displays the display to add a new device
 * @return Device to add
 */
device_t ui_device_add() {
	device_t dev;

	int v_step = 0;
    char dev_mode = 'v';
	std::string addr;

	ui_clear();
	ui_set_color( CONSOLE_COLOR_STD);
	std::cout << "VisaDevices CurveTracer" << std::endl;
	std::cout << "====================================" << std::endl;
    std::cout << std::endl;
	std::cout << "Device - Add" << std::endl;
    std::cout << std::endl;
	std::cout << "Address:";
	std::cin >> addr;
	dev.address = addr;

	std::cout << "Device ID:";
	std::cin >> std::hex >> v_step;
	dev.device_id = v_step;

	std::cout << "Type:";
	std::cin >> dev_mode;
	dev.type_id = (device_type)dev_mode;
	
	return dev;
}

/**
 * Shows a list of devices
 * @param list List of devices
 */
void ui_device_list(std::vector<device_t> list) {
	ui_clear();
	ui_set_color( CONSOLE_COLOR_STD);
	std::cout << "VisaDevices CurveTracer" << std::endl;
	std::cout << "====================================" << std::endl;
    std::cout << std::endl;
	std::cout << "Device - List" << std::endl;
    std::cout << std::endl;
	std::cout << "Index\tDevice ID\tType\tAddress" << std::endl;

	for (int i = 0; i < list.size(); i++) {
		std::cout << i << "\t";
		std::cout << "0x" << std::hex << std::setw(8) << std::setfill('0') << list[i].device_id
        << "\t" << list[i].type_id << "\t" << list[i].address;
		std::cout << std::endl;
	}

	std::cout << std::endl;
	ui_set_color( CONSOLE_COLOR_STD);
	ui_wait_enter();
}

/**
 * Shows user interface to delete a device from the given list
 * @param list List to modify
 */
void ui_device_remove(std::vector<device_t>& list) {
	ui_clear();
	ui_set_color( CONSOLE_COLOR_STD);
	std::cout << "VisaDevices CurveTracer" << std::endl;
	std::cout << "====================================" << std::endl;
    std::cout << std::endl;
	std::cout << "Step - Remove" << std::endl;
    std::cout << std::endl;

	std::cout << "Index to remove:";
	int ind;
	std::cin >> ind;
    //Check if selected index is used in the table
    if(ind >= 0 && ind < list.size()){
        list.erase(list.begin() + ind);
    }
}