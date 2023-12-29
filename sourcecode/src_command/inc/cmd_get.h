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

#ifndef COMMAND_CMD_GET_H
#define COMMAND_CMD_GET_H

#include "system/VisaDevice.h"
#include "system/VisaSession.h"
#include "device_types.h"

/**
 * Gets the value from device
 * @param handle Visa handle
 * @param type_id type of the device
 * @param channel Channel at device
 * @param value Value to set (not used)
 * @param type Type of the value
 */
double cmd_get_generic(VisaHandle* handle, device_type type_id, int channel, double value, char type);

/**
 * Gets the value from a power supply
 * @param handle Visa handle
 * @param channel Channel at device
 * @param value Value to set
 * @param type Type of the value
 */
double cmd_get_power_supply(VisaHandle* handle, int channel, double value, char type);

/**
 * Gets the value from a electronic load
 * @param handle Visa handle
 * @param channel Channel at device
 * @param value Value to set
 * @param type Type of the value
 */
double cmd_get_electronic_load(VisaHandle* handle, int channel, double value, char type);

/**
 * Gets the value from a signal generator
 * @param handle Visa handle
 * @param channel Channel at device
 * @param value Value to set
 * @param type Type of the value
 */
double cmd_get_signal_generator(VisaHandle* handle, int channel, double value, char type);

/**
 * Gets the value from a spectrum analyzer
 * @param handle Visa handle
 * @param channel Channel at device
 * @param value Value to set
 * @param type Type of the value
 */
double cmd_get_spectrum_analyzer(VisaHandle* handle, int channel, double value, char type);

/**
 * Gets the value from a network analyzer
 * @param handle Visa handle
 * @param channel Channel at device
 * @param value Value to set
 * @param type Type of the value
 */
double cmd_get_network_analyzer(VisaHandle* handle, int channel, double value, char type);

/**
 * Gets the value from a multimeter
 * @param handle Visa handle
 * @param channel Channel at device
 * @param value Value to set
 * @param type Type of the value
 */
double cmd_get_multimeter(VisaHandle* handle, int channel, double value, char type);

/**
 * Gets the value from an oscilloscope
 * @param handle Visa handle
 * @param channel Channel at device
 * @param value Value to set
 * @param type Type of the value
 */
double cmd_get_oscilloscope(VisaHandle* handle, int channel, double value, char type);

#endif //COMMAND_CMD_GET_H
