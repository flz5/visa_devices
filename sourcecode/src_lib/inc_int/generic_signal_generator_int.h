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

#ifndef _GENERIC_POWER_SUPPLY_H
#define _GENERIC_POWER_SUPPLY_H


#include "system/VisaDevice.h"
#include "system/VisaSession.h"
#include "generic/generic_signal_generator.h"
#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*fncptr_signal_generator_init)(VisaHandle* handle);
typedef void (*fncptr_signal_generator_set_waveform_type)(VisaHandle* handle, uint32_t channel, signal_generator_waveform_type value);
typedef void (*fncptr_signal_generator_set_waveform_data)(VisaHandle* handle, uint32_t channel, bool relative, double *data);
typedef void (*fncptr_signal_generator_set_amplitude)(VisaHandle* handle, uint32_t channel, double value);
typedef void (*fncptr_signal_generator_set_offset)(VisaHandle* handle, uint32_t channel, double value);
typedef void (*fncptr_signal_generator_set_frequency)(VisaHandle* handle, uint32_t channel, double value);
typedef void (*fncptr_signal_generator_set_level)(VisaHandle* handle, uint32_t channel, double min, double max);
typedef void (*fncptr_signal_generator_set_output)(VisaHandle* handle, uint32_t channel, bool value);


struct fnc_signal_generator{
    fncptr_signal_generator_set_waveform_type fnc_set_waveform_type;
    fncptr_signal_generator_set_waveform_data fnc_set_waveform_data;

    fncptr_signal_generator_set_amplitude fnc_set_amplitude;
    fncptr_signal_generator_set_offset fnc_set_offset;

    fncptr_signal_generator_set_frequency fnc_set_frequency;
    fncptr_signal_generator_set_level fnc_set_level;

    fncptr_signal_generator_set_output fnc_set_output;

    fncptr_signal_generator_init fnc_init;
    fncptr_signal_generator_init fnc_deinit;

};

#ifdef __cplusplus
}
#endif

#endif