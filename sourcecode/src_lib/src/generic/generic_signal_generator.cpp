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

#include "generic_signal_generator_int.h"
#include "devices/dev_RG_MSO5000.h"
#include "devices/dev_NN_SGDummy.h"
#include "devices/dev_KS_33210.h"
#include "devices/dev_JT_JDS6600.h"

const struct fnc_signal_generator signal_generator_implementation[] = {
        SGDummy_pointer,
        mso5000_generator_pointer,
        ks33210_pointer,
        jds6600_pointer};

EXPORT void signal_generator_init(VisaHandle* handle) {
    signal_generator_implementation[handle->driver_id].fnc_init(handle);
}

EXPORT void signal_generator_deinit(VisaHandle* handle) {
    signal_generator_implementation[handle->driver_id].fnc_deinit(handle);
}

EXPORT void power_supply_set_waveform_type(VisaHandle* handle, uint32_t channel, signal_generator_waveform_type value){
    signal_generator_implementation[handle->driver_id].fnc_set_waveform_type(handle,channel,value);
}

EXPORT void signal_generator_set_waveform_data(VisaHandle* handle, uint32_t channel, bool relative, double *data){
    signal_generator_implementation[handle->driver_id].fnc_set_waveform_data(handle,channel,relative,data);
}

EXPORT void signal_generator_set_amplitude(VisaHandle* handle, uint32_t channel, double value){
    signal_generator_implementation[handle->driver_id].fnc_set_amplitude(handle,channel,value);

}
EXPORT void signal_generator_set_offset(VisaHandle* handle, uint32_t channel, double value){
    signal_generator_implementation[handle->driver_id].fnc_set_offset(handle,channel,value);
}

EXPORT void power_supply_set_frequency(VisaHandle* handle, uint32_t channel, double value){
    signal_generator_implementation[handle->driver_id].fnc_set_frequency(handle,channel,value);
}

EXPORT void signal_generator_set_level(VisaHandle* handle, uint32_t channel, double min, double max){
    signal_generator_implementation[handle->driver_id].fnc_set_level(handle,channel,min,max);
}

EXPORT void signal_generator_set_output(VisaHandle* handle, uint32_t channel, bool value){
    signal_generator_implementation[handle->driver_id].fnc_set_output(handle,channel,value);
}