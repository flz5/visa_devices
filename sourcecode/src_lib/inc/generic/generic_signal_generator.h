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

#ifndef _GENERIC_SIGNAL_GENERATOR_H
#define _GENERIC_SIGNAL_GENERATOR_H


#ifdef __cplusplus
extern "C" {
#endif

#include "system/VisaSession.h"
#include <inttypes.h>

typedef enum {
    WAVEFORM_DATA = 0,
    WAVEFORM_SINE = 1,
    WAVEFORM_RECT = 2,
} signal_generator_waveform_type;

/**
 *
 */
EXPORT void signal_generator_init(VisaHandle* handle);

/**
 *
 */
EXPORT void signal_generator_deinit(VisaHandle* handle);

/**
 *
 */
EXPORT void power_supply_set_waveform_type(VisaHandle* handle, uint32_t channel, signal_generator_waveform_type value);

/**
 *
 */
EXPORT void signal_generator_set_waveform_data(VisaHandle* handle, uint32_t channel, bool relative, double *data);

/**
 *
 */
EXPORT void signal_generator_set_amplitude(VisaHandle* handle, uint32_t channel, double value);

/**
 *
 */
EXPORT void signal_generator_set_offset(VisaHandle* handle, uint32_t channel, double value);

/**
 *
 */
EXPORT void power_supply_set_frequency(VisaHandle* handle, uint32_t channel, double value);

/**
 *
 */
EXPORT void signal_generator_set_level(VisaHandle* handle, uint32_t channel, double min, double max);

/**
 *
 */
EXPORT void signal_generator_set_output(VisaHandle* handle, uint32_t channel, bool value);

#ifdef __cplusplus
}
#endif

#endif
