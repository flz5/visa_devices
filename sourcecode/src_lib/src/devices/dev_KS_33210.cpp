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


#include "devices/dev_KS_33210.h"
#include "generic_signal_generator_int.h"

void ks33210_init(VisaHandle* handle){

}

void ks33210_deinit(VisaHandle* handle){

}

void ks33210_set_waveform_type(VisaHandle* handle, uint32_t channel, signal_generator_waveform_type value){

    switch (value) {
        case WAVEFORM_SINE:
        {
            viPrintf(handle->session, "FUNCtion SINusoid");
        }break;
        case WAVEFORM_RECT:
        {
            viPrintf(handle->session, "FUNCtion SQUare");
        }break;
        default:{

        }
    }
}

void ks33210_set_waveform_data(VisaHandle* handle, uint32_t channel, bool relative, double *data){

}

void ks33210_set_amplitude(VisaHandle* handle, uint32_t channel, double value){
    viPrintf(handle->session, "VOLTage %.4f\n", value);
}

void ks33210_set_offset(VisaHandle* handle, uint32_t channel, double value){
    viPrintf(handle->session, "VOLTage:OFFSet %.4f\n", value);
}

void ks33210_set_frequency(VisaHandle* handle, uint32_t channel, double value){
    viPrintf(handle->session, "FREQuency %.4f\n", value);
}

void ks33210_set_level(VisaHandle* handle, uint32_t channel, double min, double max){

    double ampl = max - min;
    double offset = (min + max)/2;

    ks33210_set_amplitude(handle,channel,ampl);
    ks33210_set_offset(handle,channel,offset);
}

void ks33210_set_output(VisaHandle* handle, uint32_t channel, bool value){
    if(value){
        viPrintf(handle->session, "OUTPut ON");
    }else{
        viPrintf(handle->session, "OUTPut OFF");
    }
}

const struct fnc_signal_generator ks33210_pointer = {
        .fnc_set_waveform_type = ks33210_set_waveform_type,
        .fnc_set_waveform_data = ks33210_set_waveform_data,
        .fnc_set_amplitude = ks33210_set_amplitude,
        .fnc_set_offset = ks33210_set_offset,
        .fnc_set_frequency = ks33210_set_frequency,
        .fnc_set_level = ks33210_set_level,
        .fnc_set_output = ks33210_set_output,
        .fnc_init = ks33210_init,
        .fnc_deinit = ks33210_deinit

};