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
#include "generic/generic_network_analyzer.h"
#include "generic_network_analyzer_int.h"
#include "devices/dev_NN_NADummy.h"

const struct fnc_network_analyzer network_analyzer_implementation[] = {NADummy_pointer};

EXPORT void network_analyzer_init(VisaHandle* handle){
    network_analyzer_implementation[handle->driver_id].fnc_init(handle);
}
EXPORT void network_analyzer_deinit(VisaHandle* handle){
    network_analyzer_implementation[handle->driver_id].fnc_deinit(handle);
}

EXPORT void network_analyzer_set_span_cr(VisaHandle* handle, uint32_t channel, double center, double range){
    network_analyzer_implementation[handle->driver_id].fnc_set_span_cr(handle,channel,center,range);
}
EXPORT void network_analyzer_set_span_lh(VisaHandle* handle, uint32_t channel, double low, double high){
    network_analyzer_implementation[handle->driver_id].fnc_set_span_lh(handle,channel,low,high);
}
EXPORT double* network_analyzer_get_waveform(VisaHandle* handle, uint32_t channel){
    return network_analyzer_implementation[handle->driver_id].fnc_get_waveform(handle,channel);
}

EXPORT void network_analyzer_save_waveform(VisaHandle* handle, uint32_t channel, char *filename){
    network_analyzer_implementation[handle->driver_id].fnc_save_waveform(handle,channel,filename);
}