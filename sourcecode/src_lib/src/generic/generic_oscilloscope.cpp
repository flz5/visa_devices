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

#include "generic/generic_oscilloscope.h"
#include "generic_oscilloscope_int.h"

//Device driver implementations
#include "devices/dev_TK_TDS700.h"
#include "devices/dev_RG_MSO5000.h"
#include "devices/dev_NN_OSDummy.h"

fnc_oscilloscope oscilloscope_implentations[3] = { OSDummy_oscilloscope_pointer,
                                                   tds700_pointer ,
                                                   mso5000_oscilloscope_pointer};

EXPORT void oscilloscope_init(VisaHandle* handle) {
	oscilloscope_implentations[handle->driver_id].fnc_init(handle);
}
EXPORT void oscilloscope_deinit(VisaHandle* handle) {
	oscilloscope_implentations[handle->driver_id].fnc_deinit(handle);
}

EXPORT void oscilloscope_save_waveform(VisaHandle* handle, uint32_t channel, char* filename) {
	oscilloscope_implentations[handle->driver_id].fnc_save_waveform(handle, channel, filename);
}

EXPORT void oscilloscope_get_waveform(VisaHandle* handle, uint32_t channel, double* data, uint32_t size) {
	oscilloscope_implentations[handle->driver_id].fnc_get_waveform(handle, channel, data, size);
}

EXPORT void oscilloscope_set_hdiv(VisaHandle* handle, uint32_t channel, double value) {
	oscilloscope_implentations[handle->driver_id].fnc_set_hdiv(handle, channel, value);
}

EXPORT void oscilloscope_set_vdiv(VisaHandle* handle, uint32_t channel, double value) {
	oscilloscope_implentations[handle->driver_id].fnc_set_vdiv(handle, channel, value);
}

EXPORT void oscilloscope_set_trigger_mode(VisaHandle* handle, oscilloscope_trigger_mode mode) {
	oscilloscope_implentations[handle->driver_id].fnc_set_trigger_mode(handle, mode);
}

EXPORT void oscilloscope_set_trigger_coupling(VisaHandle* handle, oscilloscope_trigger_coupling mode) {
	oscilloscope_implentations[handle->driver_id].fnc_set_trigger_coupling(handle, mode);
}
EXPORT void oscilloscope_set_trigger_level(VisaHandle* handle, double value) {
	oscilloscope_implentations[handle->driver_id].fnc_set_trigger_level(handle,value);
}

EXPORT void oscilloscope_set_trigger_source(VisaHandle* handle, oscilloscope_trigger_source source) {
	oscilloscope_implentations[handle->driver_id].fnc_set_trigger_source(handle, source);
}

EXPORT void oscilloscope_set_trigger_slope(VisaHandle* handle, oscilloscope_trigger_slope slope) {
	oscilloscope_implentations[handle->driver_id].fnc_set_trigger_slope(handle, slope);
}

EXPORT void oscilloscope_force_trigger(VisaHandle* handle) {
	oscilloscope_implentations[handle->driver_id].fnc_force_trigger(handle);
}
