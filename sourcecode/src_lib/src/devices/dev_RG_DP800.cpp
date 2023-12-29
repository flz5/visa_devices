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
#include "devices/dev_RG_DP800.h"
#include "generic_power_supply_int.h"
#include "generic/generic_power_supply_id.h"

#include <cstdlib>
#include <string>
#include "system.h"

EXPORT void DP800_init(VisaHandle* handle) {

}

EXPORT void DP800_deinit(VisaHandle* handle) {

}

void DP800_set_current(VisaHandle* handle, uint32_t channel, double value) {
    viPrintf(handle->session, ":SOURce[%i]:CURRent %.4f\n", channel, value);
}

double DP800_get_current(VisaHandle* handle, uint32_t channel) {
    char text[100];
    double value;

    switch(channel){
        case 1:
        {
            viPrintf(handle->session, ":MEAS:CURR? CH1\n");
        }break;
        case 2:{
            viPrintf(handle->session, ":MEAS:CURR? CH2\n");
        }break;
        case 3:{
            viPrintf(handle->session, ":MEAS:CURR? CH3\n");
        }break;
    }

    sys_sleep(100);
    viScanf(handle->session, "%s", text);
    value = std::atof(text);

    return value;
}

double DP800_get_current_min(VisaHandle* handle, uint32_t channel) {
    //all types allow 0 amps current
    return 0.0;
}

double DP800_get_current_max(VisaHandle* handle, uint32_t channel) {

    if(handle->device_id == (DRIVER_PS_DP832A & 0xFFFF) || handle->device_id == (DRIVER_PS_DP832 & 0xFFFF)){
        return 3.0;
    }

    if(handle->device_id == (DRIVER_PS_DP831A & 0xFFFF) || handle->device_id == (DRIVER_PS_DP831 & 0xFFFF)){
        if(channel == 1){
            return 5.0;
        }else{
            return 2.0;
        }
    }

    if(handle->device_id == (DRIVER_PS_DP822A & 0xFFFF) || handle->device_id == (DRIVER_PS_DP822 & 0xFFFF)){
        if(channel == 1){
            return 5.0;
        }else{
            return 16.0;
        }
    }

    if(handle->device_id == (DRIVER_PS_DP821A & 0xFFFF) || handle->device_id == (DRIVER_PS_DP821 & 0xFFFF)){
        if(channel == 1){
            return 1.0;
        }else{
            return 10.0;
        }
    }

    if(handle->device_id == (DRIVER_PS_DP813A & 0xFFFF) || handle->device_id == (DRIVER_PS_DP813 & 0xFFFF)){
        return 20.0;
    }

    if(handle->device_id == (DRIVER_PS_DP811A & 0xFFFF) || handle->device_id == (DRIVER_PS_DP811 & 0xFFFF)){
        return 10.0;
    }

    //Combination not found -> invalid -> return 0
    return 0.0;
}

void DP800_set_voltage(VisaHandle* handle, uint32_t channel, double value) {
    viPrintf(handle->session, ":SOURce[%i]:VOLTage %.4f\n", channel, value);
}

double DP800_get_voltage(VisaHandle* handle, uint32_t channel) {
    char text[100];
    double value;

    switch(channel){
        case 1:
        {
            viPrintf(handle->session, ":MEAS? CH1\n");
        }break;
        case 2:{
            viPrintf(handle->session, ":MEAS? CH2\n");
        }break;
        case 3:{
            viPrintf(handle->session, ":MEAS? CH3\n");
        }break;
    }

    sys_sleep(100);
    viScanf(handle->session, "%s", text);
    value = std::atof(text);

    return value;
}

double DP800_get_voltage_min(VisaHandle* handle, uint32_t channel) {
    //only types which have an output below 0 are listed here
    if(handle->device_id == (DRIVER_PS_DP831A & 0xFFFF) || handle->device_id == (DRIVER_PS_DP831 & 0xFFFF)){
        if(channel == 3){
            return -30.0;
        }
    }

    //default for all other types
    return 0.0;
}

double DP800_get_voltage_max(VisaHandle* handle, uint32_t channel) {
    if(handle->device_id == (DRIVER_PS_DP832A & 0xFFFF) || handle->device_id == (DRIVER_PS_DP832 & 0xFFFF)){
        if(channel == 1 || channel == 2){
            return 30.0;
        }else{
            return 5.0;
        }
    }

    if(handle->device_id == (DRIVER_PS_DP831A & 0xFFFF) || handle->device_id == (DRIVER_PS_DP831 & 0xFFFF)){
        if(channel == 1){
            return 8.0;
        }else if(channel == 2){
            return 30.0;
        }else if(channel == 3){
            return 0.0;
        }
    }

    if(handle->device_id == (DRIVER_PS_DP822A & 0xFFFF) || handle->device_id == (DRIVER_PS_DP822 & 0xFFFF)){
        if(channel == 1){
            return 20.0;
        }else{
            return 5.0;
        }
    }

    if(handle->device_id == (DRIVER_PS_DP821A & 0xFFFF) || handle->device_id == (DRIVER_PS_DP821 & 0xFFFF)){
        if(channel == 1){
            return 60.0;
        }else{
            return 8.0;
        }
    }

    if(handle->device_id == (DRIVER_PS_DP813A & 0xFFFF) || handle->device_id == (DRIVER_PS_DP813 & 0xFFFF)){
        return 20.0;
    }

    if(handle->device_id == (DRIVER_PS_DP811A & 0xFFFF) || handle->device_id == (DRIVER_PS_DP811 & 0xFFFF)){
        return 40.0;
    }

    //Combination not found -> invalid -> return 0
    return 0.0;
}

void DP800_set_ocp(VisaHandle* handle, uint32_t channel, double value) {
    //Function not supported by device
    viPrintf(handle->session, ":SOURce[%i]:CURRent:PROTection %.4f\n", channel, value);
}

double DP800_get_ocp(VisaHandle* handle, uint32_t channel) {

    char text[100];
    double value;

    viPrintf(handle->session, ":SOURce[%i]:CURRent:PROTection?\n", channel);

    sys_sleep(100);
    viScanf(handle->session, "%s", text);
    value = std::atof(text);

    return value;
}

double DP800_get_ocp_min(VisaHandle* handle, uint32_t channel) {
    //Function not supported by device
    return 0.0;
}

double DP800_get_ocp_max(VisaHandle* handle, uint32_t channel) {
    //Function not supported by device
    return 0.0;
}

void DP800_set_ovp(VisaHandle* handle, uint32_t channel, double value) {
    //Function not supported by device
    return;
}
double DP800_get_ovp(VisaHandle* handle, uint32_t channel) {
    //Function not supported by device
    return 0.0;
}
double DP800_get_ovp_min(VisaHandle* handle, uint32_t channel) {
    //Function not supported by device
    return 0.0;
}
double DP800_get_ovp_max(VisaHandle* handle, uint32_t channel) {
    //Function not supported by device
    return 0.0;
}

void DP800_clear_protection(VisaHandle* handle, uint32_t channel) {

    viPrintf(handle->session, ":SOURce[%i]:CURRent:PROTection:CLEar\n", channel);
    viPrintf(handle->session, ":SOURce[%i]:VOLTage:PROTection:CLEar\n", channel);

    return;

}
bool DP800_get_protection(VisaHandle* handle, uint32_t channel) {
    //TODO: Implementation
    return false;
}

void DP800_set_output(VisaHandle* handle, uint32_t channel, bool value) {
    const char *channel_text[4] = { "CH1","CH2","CH3" };
    //Exit function if the channel is invalid for the device
    if (channel > 3) {
        return;
    }

    if (value == true) {
        viPrintf(handle->session, ":OUTPut:STATe %s,ON\n", channel_text[channel]);
    }
    else {
        viPrintf(handle->session, "OUTPut:STATe %s,OFF\n", channel_text[channel]);
    }
}

const struct fnc_power_supply DP800_pointer = {
        .fnc_set_current = DP800_set_current,
        .fnc_get_current = DP800_get_current,
        .fnc_get_current_min = DP800_get_current_min,
        .fnc_get_current_max = DP800_get_current_max,

        .fnc_set_voltage = DP800_set_voltage,
        .fnc_get_voltage = DP800_get_voltage,
        .fnc_get_voltage_min = DP800_get_voltage_min,
        .fnc_get_voltage_max = DP800_get_voltage_max,

        .fnc_set_ocp = DP800_set_ocp,
        .fnc_get_ocp = DP800_get_ocp,
        .fnc_get_ocp_min = DP800_get_ocp_min,
        .fnc_get_ocp_max = DP800_get_ocp_max,

        .fnc_set_ovp = DP800_set_ovp,
        .fnc_get_ovp = DP800_get_ovp,
        .fnc_get_ovp_min = DP800_get_ovp_min,
        .fnc_get_ovp_max = DP800_get_ovp_max,

        .fnc_clear_protection = DP800_clear_protection,
        .fnc_get_protection = DP800_get_protection,

        .fnc_set_output = DP800_set_output,

        .fnc_init = DP800_init,
        .fnc_deinit = DP800_deinit

};
