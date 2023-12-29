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

#include "controller_sweeps.h"

/**
 * Sets the value on a device
 * @param device device to set
 * @param channel Channel at the device
 * @param value Value to set
 * @param mode Select what will be set
 */
void controller_set_step(const device_t& device, int channel, double value, char mode) {
	switch (device.type_id) {
        case TYPE_POWERSUPPLY:
        {
            controller_step_supply(device.handle, channel, value, mode);
        }break;
        case TYPE_ELECTRONIC_LOAD:
        {
            controller_step_electronic_load(device.handle, channel, value, mode);
        }break;
        case TYPE_SIGNALGENERATOR:
        case TYPE_MULTIMETER:
        case TYPE_OSCILLOSCOPE:
            break;
    }
}

/**
 * Sets the value on a power supply
 * @param handle handle for device to set
 * @param channel Channel at the device
 * @param value Value to set
 * @param mode Select what will be set
 */
void controller_step_supply(VisaHandle* handle, int channel, double value, char mode) {
	switch (mode) {
        case 'U': {
            power_supply_set_voltage(handle, channel, value);
        }break;
        case 'I': {
            power_supply_set_current(handle, channel, value);
        }break;
        default:
            break;
	}
}

/**
 * Sets the value on a electronic load
 * @param handle handle for device to set
 * @param channel Channel at the device
 * @param value Value to set
 * @param mode Select what will be set
 */
void controller_step_electronic_load(VisaHandle* handle, int channel, double value, char mode) {
	switch (mode) {
        case 'U': {
            electronic_load_set_voltage(handle, channel, value);
        }break;
        case 'I': {
            electronic_load_set_current(handle, channel, value);
        }break;
        case 'R':{
            electronic_load_set_resistance(handle,channel,value);
        }break;
        case 'P':{
            electronic_load_set_power(handle,channel,value);
        }break;
	}
}
