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

#include "cmd_get.h"
#include "generic/generic_power_supply.h"
#include "generic/generic_electronic_load.h"
#include "generic/generic_signal_generator.h"
#include "generic/generic_multimeter.h"
#include "generic/generic_oscilloscope.h"
#include "generic/generic_network_analyzer.h"
#include "generic/generic_spectrum_analyzer.h"

/**
 * Gets the value from device
 * @param handle Visa handle
 * @param type_id type of the device
 * @param channel Channel at device
 * @param value Value to set (not used)
 * @param type Type of the value
 */
double cmd_get_generic(VisaHandle* handle, device_type type_id, int channel, double value, char type){
    switch(type_id){
        case PowerSupply:
        {
          return cmd_get_power_supply(handle,channel,value,type);
        }break;
        case Multimeter:{
            return cmd_get_multimeter(handle,channel,value, type);
        }break;
        case ElectronicLoad:{
            return cmd_get_electronic_load(handle,channel,value,type);
        }
        case SignalGenerator:{
            return cmd_get_signal_generator(handle,channel,value,type);
        }
        case SpectrumAnalyzer:{
            return cmd_get_spectrum_analyzer(handle,channel,value,type);
        }
        case NetworkAnalyzer:{
            return cmd_get_network_analyzer(handle,channel,value,type);
        }
        case Oscilloscope:{
            return cmd_get_oscilloscope(handle,channel,value,type);
        }
        default:{
            return 0.0;
        }
    }
}

/**
 * Gets the value from a power supply
 * @param handle Visa handle
 * @param channel Channel at device
 * @param value Value to set
 * @param type Type of the value
 */
double cmd_get_power_supply(VisaHandle* handle, int channel, double value, char type){
    double retVal = 0.0;
    switch (type) {
        case 'U': {
            retVal = power_supply_get_voltage(handle, channel);
        }break;
        case 'I': {
            retVal = power_supply_get_current(handle, channel);
        }break;
        default:{
            retVal = 0.0;
        }
    }
    return retVal;
}

/**
 * Gets the value from a electronic load
 * @param handle Visa handle
 * @param channel Channel at device
 * @param value Value to set
 * @param type Type of the value
 */
double cmd_get_electronic_load(VisaHandle* handle, int channel, double value, char type){
    double retVal = 0.0;
    switch (type) {
        case 'U': {
            retVal = electronic_load_get_voltage(handle, channel);
        }break;
        case 'I': {
            retVal = electronic_load_get_current(handle, channel);
        }break;
        default:{
            retVal = 0.0;
        }
    }
    return retVal;
}

/**
 * Gets the value from a signal generator
 * @param handle Visa handle
 * @param channel Channel at device
 * @param value Value to set
 * @param type Type of the value
 */
double cmd_get_signal_generator(VisaHandle* handle, int channel, double value, char type){
    //TODO: Implementation
    return 0.0;
}

/**
 * Gets the value from a spectrum analyzer
 * @param handle Visa handle
 * @param channel Channel at device
 * @param value Value to set
 * @param type Type of the value
 */
double cmd_get_spectrum_analyzer(VisaHandle* handle, int channel, double value, char type){
    //TODO: Implementation
    return 0.0;
}

/**
 * Gets the value from a network analyzer
 * @param handle Visa handle
 * @param channel Channel at device
 * @param value Value to set
 * @param type Type of the value
 */
double cmd_get_network_analyzer(VisaHandle* handle, int channel, double value, char type){
    //TODO: Implementation
    return 0.0;
}

/**
 * Gets the value from a multimeter
 * @param handle Visa handle
 * @param channel Channel at device
 * @param value Value to set
 * @param type Type of the value
 */
double cmd_get_multimeter(VisaHandle* handle, int channel, double value, char type){
    //TODO: Implementation
    //Always returns default measurement value
    return multimeter_get_measurement(handle,channel);
}

/**
 * Gets the value from an oscilloscope
 * @param handle Visa handle
 * @param channel Channel at device
 * @param value Value to set
 * @param type Type of the value
 */
double cmd_get_oscilloscope(VisaHandle* handle, int channel, double value, char type){
    //TODO: Implementation
    return 0.0;
}