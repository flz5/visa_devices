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

#ifndef VISADEVICES_DEV_NN_OSDUMMY_H
#define VISADEVICES_DEV_NN_OSDUMMY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "system/VisaSession.h"
#include "generic/generic_oscilloscope.h"
#include <inttypes.h>

EXPORT void OSDummy_init(VisaHandle* handle);
EXPORT void OSDummy_deinit(VisaHandle* handle);

EXPORT void OSDummy_save_waveform(VisaHandle* handle, uint32_t channel, char* filename);
EXPORT void OSDummy_get_waveform(VisaHandle* handle, uint32_t channel, double* data, uint32_t size);
EXPORT void OSDummy_set_hdiv(VisaHandle* handle, uint32_t channel, double value);
EXPORT void OSDummy_set_vdiv(VisaHandle* handle, uint32_t channel, double value);
EXPORT void OSDummy_set_trigger_mode(VisaHandle* handle, oscilloscope_trigger_mode mode);
EXPORT void OSDummy_set_trigger_coupling(VisaHandle* handle, oscilloscope_trigger_coupling mode);
EXPORT void OSDummy_set_trigger_level(VisaHandle* handle, double value);
EXPORT void OSDummy_set_trigger_slope(VisaHandle* handle, oscilloscope_trigger_slope slope);
EXPORT void OSDummy_set_trigger_source(VisaHandle* handle, oscilloscope_trigger_source source);

EXPORT void OSDummy_force_trigger(VisaHandle* handle);

extern const struct fnc_oscilloscope OSDummy_oscilloscope_pointer;

#ifdef __cplusplus
}
#endif

#endif //VISADEVICES_DEV_NN_OSDUMMY_H
