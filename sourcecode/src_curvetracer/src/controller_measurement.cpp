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

#include "controller_measurements.h"
#include "measurement_array.h"
#include <vector>
#include "controller_device_type.h"

/**
 * Builds an identifier string (for filenames) based on the current positions
 * @param size
 * @param pos
 * @return
 */
std::string buildIdentifier(uint32_t size, uint32_t *pos){
    std::string res;
    for(uint32_t i = 0;i<size;i++){
        res += std::to_string(pos[i]);
    }
    return res;
}

/**
 * Starts the measurement measurement. Results are stored in measurement array (with position) or in a separate file
 * @param devices Vector of devices
 * @param measurement Measurement to start
 * @param ma MeasrementArray (storage)
 * @param folder Path to a folder, where data can be stored
 * @param id Number of the measurement in the array/results
 */
void controller_measure(std::vector<device_t> &devices, const measurement_t& measurement, MeasurementArray &ma,
                        const std::string& folder, uint32_t *position, uint32_t id) {

	device_t dev = devices[measurement.device];
	VisaHandle* hh = dev.handle;

	switch (dev.type_id) {
	case TYPE_POWER_SUPPLY: {
		ma.insert(position, controller_measure_supply(hh, measurement.channel, measurement.mode));
	}break;
	case TYPE_OSCILLOSCOPE: {
		std::string file = folder + "\raw_osc_m" + std::to_string(id) + "_" + buildIdentifier(ma.getPositionLength(),position) + ".txt";
		ma.insert(position, controller_measure_oscilloscope(hh, measurement.channel, measurement.mode, file));
	}break;
	case TYPE_MULTIMETER: {
		ma.insert(position, controller_measure_multimeter(hh, measurement.channel, measurement.mode));
	}break;
	case TYPE_ELECTRONIC_LOAD: {
		ma.insert(position, controller_measure_electronic_load(hh, measurement.channel, measurement.mode));
	}break;
	}
}

/**
 * Starts the specific measurements for a power supply
 * @param handle Visa handle to the device
 * @param channel Device channel
 * @param type Type of the measurement
 * @return Measured value
 */
double controller_measure_supply(VisaHandle* handle, uint32_t channel, char type) {
	double retVal = 0.0;
	switch (type) {
	case 'U': {
		retVal = power_supply_get_voltage(handle,channel);
	}break;
	case 'I': {
		retVal = power_supply_get_current(handle, channel);
	}break;
	}
	return retVal; 
}

/**
 * Starts the specific measurements for an oscilloscope
 * @param handle Visa handle to the device
 * @param channel Device channel
 * @param type Type of the measurement
 * @param filename filename/path to store data, when they contain more than one value
 * @return Measured value
 */
double controller_measure_oscilloscope(VisaHandle* handle, uint32_t channel, char type, const std::string& filename) {
	//TODO: Implementation
	return 0.0;
}

/**
 * Starts the specific measurements for an electronic load
 * @param handle Visa handle to the device
 * @param channel Device channel
 * @param type Type of the measurement
 * @param filename filename/path to store data, when they contain more than one value
 * @return Measured value
 */
double controller_measure_electronic_load(VisaHandle* handle, uint32_t channel, char type) {
    double retVal = 0.0;
    switch (type) {
        case 'U': {
            retVal = electronic_load_get_voltage(handle,channel);
        }break;
        case 'I': {
            retVal = electronic_load_get_current(handle, channel);
        }break;
        case 'P':{
            retVal = electronic_load_get_power(handle, channel);
        }
        default:{
            retVal = 0.0;
        }
    }
    return retVal;
}

/**
 * Starts the specific measurements for a multimeter
 * @param handle Visa handle to the device
 * @param channel Device channel
 * @param type Type of the measurement
 * @return Measured value
 */
double controller_measure_multimeter(VisaHandle* handle, uint32_t channel, char type) {
	//TODO: Implementation
	return 0.0;
}
