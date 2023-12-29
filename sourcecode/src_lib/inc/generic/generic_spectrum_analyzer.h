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

#ifndef VISADEVICES_GENERIC_SPECTRUM_ANALYZER_H
#define VISADEVICES_GENERIC_SPECTRUM_ANALYZER_H


#ifdef __cplusplus
extern "C" {
#endif

#include "system/VisaSession.h"
#include <inttypes.h>

EXPORT void spectrum_analyzer_init(VisaHandle* handle);
EXPORT void spectrum_analyzer_deinit(VisaHandle* handle);
EXPORT void spectrum_analyzer_set_rbw(VisaHandle* handle, uint32_t channel, double value);
EXPORT void spectrum_analyzer_set_span_cr(VisaHandle* handle, uint32_t channel, double center, double range);
EXPORT void spectrum_analyzer_set_span_lh(VisaHandle* handle, uint32_t channel, double low, double high);
EXPORT void spectrum_analyzer_set_attenuation(VisaHandle* handle, uint32_t channel, double value);
EXPORT double* spectrum_analyzer_get_waveform(VisaHandle* handle, uint32_t channel);
EXPORT void spectrum_analyzer_save_waveform(VisaHandle* handle, uint32_t channel, char *filename);

#ifdef __cplusplus
}
#endif

#endif //VISADEVICES_GENERIC_SPECTRUM_ANALYZER_H
