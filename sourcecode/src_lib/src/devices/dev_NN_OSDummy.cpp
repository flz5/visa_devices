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

#include "devices/dev_NN_OSDummy.h"
#include "generic_oscilloscope_int.h"

EXPORT void OSDummy_init(VisaHandle* handle){

}
EXPORT void OSDummy_deinit(VisaHandle* handle){

}

EXPORT void OSDummy_save_waveform(VisaHandle* handle, uint32_t channel, char* filename){

}

EXPORT void OSDummy_get_waveform(VisaHandle* handle, uint32_t channel, double* data, uint32_t size){

}
EXPORT void OSDummy_set_hdiv(VisaHandle* handle, uint32_t channel, double value){

}
EXPORT void OSDummy_set_vdiv(VisaHandle* handle, uint32_t channel, double value){

}
EXPORT void OSDummy_set_trigger_mode(VisaHandle* handle, oscilloscope_trigger_mode mode){

}
EXPORT void OSDummy_set_trigger_coupling(VisaHandle* handle, oscilloscope_trigger_coupling mode){

}
EXPORT void OSDummy_set_trigger_level(VisaHandle* handle, double value){

}
EXPORT void OSDummy_set_trigger_slope(VisaHandle* handle, oscilloscope_trigger_slope slope){

}
EXPORT void OSDummy_set_trigger_source(VisaHandle* handle, oscilloscope_trigger_source source){

}

EXPORT void OSDummy_force_trigger(VisaHandle* handle){

}

const struct fnc_oscilloscope OSDummy_oscilloscope_pointer = {
        .fnc_init = OSDummy_init,
        .fnc_deinit = OSDummy_deinit,

        .fnc_save_waveform = OSDummy_save_waveform,
        .fnc_get_waveform = OSDummy_get_waveform,

        .fnc_set_hdiv = OSDummy_set_hdiv,
        .fnc_set_vdiv = OSDummy_set_vdiv,

        .fnc_set_trigger_mode = OSDummy_set_trigger_mode,
        .fnc_set_trigger_level = OSDummy_set_trigger_level,
        .fnc_set_trigger_coupling = OSDummy_set_trigger_coupling,
        .fnc_set_trigger_source = OSDummy_set_trigger_source,
        .fnc_set_trigger_slope = OSDummy_set_trigger_slope,

        .fnc_force_trigger = OSDummy_force_trigger
};
