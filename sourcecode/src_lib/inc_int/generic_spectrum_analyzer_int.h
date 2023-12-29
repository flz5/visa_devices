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

#ifndef VISADEVICES_GENERIC_SPECTRUM_ANALYZER_INT_H
#define VISADEVICES_GENERIC_SPECTRUM_ANALYZER_INT_H


#include "system/VisaDevice.h"
#include "system/VisaSession.h"
#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*fncptr_spectrum_analyzer_init)(VisaHandle* handle);
typedef void (*fncptr_spectrum_analyzer_set_rbw)(VisaHandle* handle, uint32_t channel, double value);
typedef void (*fncptr_spectrum_analyzer_set_span_cr)(VisaHandle* handle, uint32_t channel, double center, double range);
typedef void (*fncptr_spectrum_analyzer_set_span_lh)(VisaHandle* handle, uint32_t channel, double low, double high);
typedef void (*fncptr_spectrum_analyzer_set_attenuation)(VisaHandle* handle, uint32_t channel, double value);
typedef double* (*fncptr_spectrum_analyzer_get_waveform)(VisaHandle* handle, uint32_t channel);
typedef void (*fncptr_spectrum_analyzer_save_waveform)(VisaHandle* handle, uint32_t channel, char *filename);


struct fnc_spectrum_analyzer{
    fncptr_spectrum_analyzer_set_rbw fnc_set_rbw;
    fncptr_spectrum_analyzer_set_span_cr fnc_set_span_cr;

    fncptr_spectrum_analyzer_set_span_lh fnc_set_span_lh;
    fncptr_spectrum_analyzer_set_attenuation fnc_set_attenuation;

    fncptr_spectrum_analyzer_get_waveform fnc_get_waveform;
    fncptr_spectrum_analyzer_save_waveform fnc_save_waveform;

    fncptr_spectrum_analyzer_init fnc_init;
    fncptr_spectrum_analyzer_init fnc_deinit;

};

#ifdef __cplusplus
}
#endif

#endif //VISADEVICES_GENERIC_SPECTRUM_ANALYZER_INT_H
