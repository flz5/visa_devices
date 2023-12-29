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

#include "wfm_get.h"
#include "generic/generic_power_supply.h"
#include "generic/generic_electronic_load.h"
#include "generic/generic_signal_generator.h"
#include "generic/generic_multimeter.h"
#include "generic/generic_oscilloscope.h"
#include "generic/generic_network_analyzer.h"
#include "generic/generic_spectrum_analyzer.h"

/**
 * Gets the waveform from device
 * @param handle Visa handle
 * @param type_id type of the device
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_generic(VisaHandle* handle, device_type type_id, int channel, char type, const std::string& filename){
    switch(type_id){
        case PowerSupply:
        {
             wfm_get_power_supply(handle,channel,type, filename);
        }break;
        case Multimeter:{
             wfm_get_multimeter(handle,channel, type,filename);
        }break;
        case ElectronicLoad:{
             wfm_get_electronic_load(handle,channel,type,filename);
        }
        case SignalGenerator:{
             wfm_get_signal_generator(handle,channel,type,filename);
        }
        case SpectrumAnalyzer:{
             wfm_get_spectrum_analyzer(handle,channel,type,filename);
        }
        case NetworkAnalyzer:{
            wfm_get_network_analyzer(handle,channel,type,filename);
        }
        case Oscilloscope:{
             wfm_get_oscilloscope(handle,channel,type,filename);
        }
        default:{

        }
    }
}

/**
 * Gets the waveform from a power supply
 * @param handle Visa handle
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_power_supply(VisaHandle* handle, int channel, char type, const std::string& filename){
    //TODO: Implementation
    return;
}

/**
 * Gets the waveform from a electronic load
 * @param handle Visa handle
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_electronic_load(VisaHandle* handle, int channel, char type, const std::string& filename){
    //TODO: Implementation
    return;
}

/**
 * Gets the waveform from a signal generator
 * @param handle Visa handle
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_signal_generator(VisaHandle* handle, int channel, char type, const std::string& filename){
    //TODO: Implementation
    return;
}

/**
 * Gets the waveform from a spectrum analyzer
 * @param handle Visa handle
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_spectrum_analyzer(VisaHandle* handle, int channel, char type, const std::string& filename){
    //TODO: Implementation
    return;
}

/**
 * Gets the waveform from a network analyzer
 * @param handle Visa handle
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_network_analyzer(VisaHandle* handle, int channel, char type, const std::string& filename){
    //TODO: Implementation
    return;
}

/**
 * Gets the waveform from a multimeter
 * @param handle Visa handle
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_multimeter(VisaHandle* handle, int channel, char type, const std::string& filename){
    //TODO: Implementation
    return;
}

/**
 * Gets the waveform from an oscilloscope
 * @param handle Visa handle
 * @param channel Channel at device
 * @param type Type of the value
 * @param filename Filename for created file
 */
void wfm_get_oscilloscope(VisaHandle* handle, int channel, char type, const std::string& filename){
    oscilloscope_save_waveform(handle,channel,const_cast<char*>(filename.c_str()));
    return;
}