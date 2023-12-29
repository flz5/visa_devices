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
#include "generic/generic_spectrum_analyzer.h"
#include "generic_spectrum_analyzer_int.h"
#include "devices/dev_NN_SADummy.h"

const struct fnc_spectrum_analyzer spectrum_analyzer_implementation[] = {SADummy_pointer};

EXPORT void spectrum_analyzer_init(VisaHandle* handle){
    spectrum_analyzer_implementation[handle->driver_id].fnc_init(handle);
}

EXPORT void spectrum_analyzer_deinit(VisaHandle* handle){
    spectrum_analyzer_implementation[handle->driver_id].fnc_deinit(handle);
}

EXPORT void spectrum_analyzer_set_rbw(VisaHandle* handle, uint32_t channel, double value){
    spectrum_analyzer_implementation[handle->driver_id].fnc_set_rbw(handle,channel,value);
}

EXPORT void spectrum_analyzer_set_span_cr(VisaHandle* handle, uint32_t channel, double center, double range){
    spectrum_analyzer_implementation[handle->driver_id].fnc_set_span_cr(handle,channel,center,range);
}

EXPORT void spectrum_analyzer_set_span_lh(VisaHandle* handle, uint32_t channel, double low, double high){
    spectrum_analyzer_implementation[handle->driver_id].fnc_set_span_lh(handle,channel,low,high);
}

EXPORT void spectrum_analyzer_set_attenuation(VisaHandle* handle, uint32_t channel, double value){
    spectrum_analyzer_implementation[handle->driver_id].fnc_set_attenuation(handle,channel,value);
}

EXPORT double* spectrum_analyzer_get_waveform(VisaHandle* handle, uint32_t channel){
    return spectrum_analyzer_implementation[handle->driver_id].fnc_get_waveform(handle,channel);
}

EXPORT void spectrum_analyzer_save_waveform(VisaHandle* handle, uint32_t channel, char *filename){
    spectrum_analyzer_implementation[handle->driver_id].fnc_save_waveform(handle,channel,filename);
}
