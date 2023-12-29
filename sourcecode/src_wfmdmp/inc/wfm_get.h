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

#ifndef WFMDMP_GET_H
#define WFMDMP_GET_H

#include "system/VisaDevice.h"
#include "system/VisaSession.h"
#include "device_types.h"
#include <string>

/**
 * Gets the waveform from device
 * @param handle Visa handle
 * @param type_id type of the device
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_generic(VisaHandle* handle, device_type type_id, int channel, char type, const std::string& filename);

/**
 * Gets the waveform from a power supply
 * @param handle Visa handle
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_power_supply(VisaHandle* handle, int channel, char type, const std::string& filename);

/**
 * Gets the waveform from a electronic load
 * @param handle Visa handle
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_electronic_load(VisaHandle* handle, int channel, char type, const std::string& filename);

/**
 * Gets the waveform from a signal generator
 * @param handle Visa handle
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_signal_generator(VisaHandle* handle, int channel, char type, const std::string& filename);

/**
 * Gets the waveform from a spectrum analyzer
 * @param handle Visa handle
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_spectrum_analyzer(VisaHandle* handle, int channel, char type, const std::string& filename);

/**
 * Gets the waveform from a network analyzer
 * @param handle Visa handle
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_network_analyzer(VisaHandle* handle, int channel, char type, const std::string& filename);

/**
 * Gets the waveform from a multimeter
 * @param handle Visa handle
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_multimeter(VisaHandle* handle, int channel, char type, const std::string& filename);

/**
 * Gets the waveform from an oscilloscope
 * @param handle Visa handle
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_oscilloscope(VisaHandle* handle, int channel, char type, const std::string& filename);

#endif //WFMDMP_GET_H
