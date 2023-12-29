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

#ifndef VISADEVICES_DEV_NN_SADUMMY_H
#define VISADEVICES_DEV_NN_SADUMMY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "system/VisaSession.h"
#include <inttypes.h>

EXPORT void SADummy_init(VisaHandle* handle);
EXPORT void SADummy_deinit(VisaHandle* handle);
EXPORT void SADummy_set_rbw(VisaHandle* handle, uint32_t channel, double value);
EXPORT void SADummy_set_span_cr(VisaHandle* handle, uint32_t channel, double center, double range);
EXPORT void SADummy_set_span_lh(VisaHandle* handle, uint32_t channel, double low, double high);
EXPORT void SADummy_set_attenuation(VisaHandle* handle, uint32_t channel, double value);
EXPORT double* SADummy_get_waveform(VisaHandle* handle, uint32_t channel);
EXPORT void SADummy_save_waveform(VisaHandle* handle, uint32_t channel, char *filename);

extern const struct fnc_spectrum_analyzer SADummy_pointer;

#ifdef __cplusplus
}
#endif

#endif //VISADEVICES_DEV_NN_SADUMMY_H
