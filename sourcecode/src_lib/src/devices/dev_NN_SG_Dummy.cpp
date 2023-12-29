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


#include "devices/dev_NN_SGDummy.h"
#include "generic_signal_generator_int.h"

void SGDummy_init(VisaHandle* handle){

}

void SGDummy_deinit(VisaHandle* handle){

}

void SGDummy_set_waveform_type(VisaHandle* handle, uint32_t channel, signal_generator_waveform_type value){

}

void SGDummy_set_waveform_data(VisaHandle* handle, uint32_t channel, bool relative, double *data){

}

void SGDummy_set_amplitude(VisaHandle* handle, uint32_t channel, double value){

}

void SGDummy_set_offset(VisaHandle* handle, uint32_t channel, double value){

}

void SGDummy_set_frequency(VisaHandle* handle, uint32_t channel, double value){

}

void SGDummy_set_level(VisaHandle* handle, uint32_t channel, double min, double max){

}

void SGDummy_set_output(VisaHandle* handle, uint32_t channel, bool value){

}


const struct fnc_signal_generator SGDummy_pointer = {
        .fnc_set_waveform_type = SGDummy_set_waveform_type,
        .fnc_set_waveform_data = SGDummy_set_waveform_data,
        .fnc_set_amplitude = SGDummy_set_amplitude,
        .fnc_set_offset = SGDummy_set_offset,
        .fnc_set_frequency = SGDummy_set_frequency,
        .fnc_set_level = SGDummy_set_level,
        .fnc_set_output = SGDummy_set_output,
        .fnc_init = SGDummy_init,
        .fnc_deinit = SGDummy_deinit

};