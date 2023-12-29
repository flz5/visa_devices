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


#include "devices/dev_JT_JDS6600.h"
#include "generic_signal_generator_int.h"

void jds6600_init(VisaHandle* handle){

}

void jds6600_deinit(VisaHandle* handle){

}

void jds6600_set_waveform_type(VisaHandle* handle, uint32_t channel, signal_generator_waveform_type value){
    switch(value){
        case WAVEFORM_SINE:
        {
            if(channel == 1){
                viPrintf(handle->session, ":w21=0.\r\n", value);
            }else{
                viPrintf(handle->session, ":w22=0.\r\n", value);
            }
        }break;
        case WAVEFORM_RECT:{
            if(channel == 1){
                viPrintf(handle->session, ":w21=1.\r\n", value);
            }else{
                viPrintf(handle->session, ":w22=1.\r\n", value);
            }
        }
        default:{

        }
    }

}

void jds6600_set_waveform_data(VisaHandle* handle, uint32_t channel, bool relative, double *data){
    //TODO: Implementation
}

void jds6600_set_amplitude(VisaHandle* handle, uint32_t channel, double value){
    if(channel == 1){
        viPrintf(handle->session, ":w25=%i.\r\n", value);
    }else{
        viPrintf(handle->session, ":w26=%i.\r\n", value);
    }
}

void jds6600_set_offset(VisaHandle* handle, uint32_t channel, double value){
    //TODO: Implementation
    //Supported by device?
}

void jds6600_set_frequency(VisaHandle* handle, uint32_t channel, double value){

    //device specif size marker
    int dev_size = 0;
    int dev_value = 0.0;

    if(value > 0){
        dev_size = 4;
        dev_value = value * 100000000.0;
    }else if(value > 0.001){
        dev_size = 3;
        dev_value = value * 100000.0;
    }else if(value > 1){
        dev_size = 0;
        dev_value = value * 100;
    }else if(value > 1000.0){
        dev_size = 1;
        dev_value = value * 10;
    }else if(value > 25000){
        //TODO: Implementation
        //Supported by device but not in documentation
        //mode 2?
        //abort function here
        return;
    }else{
        //invalid value (e.g. negative)
        //abort function here
        return;
    }

    if(channel==1){
        viPrintf(handle->session, ":w23=%i,%i.\r\n", dev_value, dev_size);
    }else{
        viPrintf(handle->session, ":w24=%i,%i.\r\n", dev_value, dev_size);
    }
}

void jds6600_set_level(VisaHandle* handle, uint32_t channel, double min, double max){
    //TODO: Implementation
    //Supported by device?
}

void jds6600_set_output(VisaHandle* handle, uint32_t channel, bool value){
    int ch1 = 0;
    int ch2 = 0;
    //TODO: Implementation
    //Only both channels can be set together!
    //viPrintf(handle->session, ":w20=%i,%i\r\n", ch1,ch2);
}

const struct fnc_signal_generator jds6600_pointer = {
        .fnc_set_waveform_type = jds6600_set_waveform_type,
        .fnc_set_waveform_data = jds6600_set_waveform_data,
        .fnc_set_amplitude = jds6600_set_amplitude,
        .fnc_set_offset = jds6600_set_offset,
        .fnc_set_frequency = jds6600_set_frequency,
        .fnc_set_level = jds6600_set_level,
        .fnc_set_output = jds6600_set_output,
        .fnc_init = jds6600_init,
        .fnc_deinit = jds6600_deinit
};