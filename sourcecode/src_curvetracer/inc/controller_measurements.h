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

#ifndef CURVETRACER_CONTROLLER_MEASUREMENT_H
#define CURVETRACER_CONTROLLER_MEASUREMENT_H

#include "controller.h"
#include "generic/generic_power_supply.h"
#include "generic/generic_electronic_load.h"
#include "measurement_array.h"
#include <vector>
#include <cinttypes>

/**
 * Starts the measurement measurement. Results are stored in measurement array (with position) or in a separate file
 * @param devices Vector of devices
 * @param measurement Measurement to start
 * @param ma MeasrementArray (storage)
 * @param folder Path to a folder, where data can be stored
 * @param id Number of the measurement in the array/results
 */
void controller_measure(std::vector<device_t>& devices,
                        const measurement_t& measurement,
                        MeasurementArray& ma,
                        const std::string& folder,
                        uint32_t *position,
                        uint32_t id);

/**
 * Starts the specific measurements for a power supply
 * @param handle Visa handle to the device
 * @param channel Device channel
 * @param type Type of the measurement
 * @return Measured value
 */
double controller_measure_supply(VisaHandle* handle, uint32_t channel, char type);

/**
 * Starts the specific measurements for an oscilloscope
 * @param handle Visa handle to the device
 * @param channel Device channel
 * @param type Type of the measurement
 * @param filename filename/path to store data, when they contain more than one value
 * @return Measured value
 */
double controller_measure_oscilloscope(VisaHandle* handle, uint32_t channel, char type,
                                       const std::string& filename);

/**
 * Starts the specific measurements for an electronic load
 * @param handle Visa handle to the device
 * @param channel Device channel
 * @param type Type of the measurement
 * @param filename filename/path to store data, when they contain more than one value
 * @return Measured value
 */
double controller_measure_electronic_load(VisaHandle* handle, uint32_t channel, char type);

/**
 * Starts the specific measurements for a multimeter
 * @param handle Visa handle to the device
 * @param channel Device channel
 * @param type Type of the measurement
 * @return Measured value
 */
double controller_measure_multimeter(VisaHandle* handle, uint32_t channel, char type);

/**
 * Builds an identifier string (for filenames) based on the current positions
 * @param size
 * @param pos
 * @return
 */
std::string buildIdentifier(uint32_t size, uint32_t *pos);

#endif