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

#ifndef VISADEVICES_DEV_NN_SGDUMMY_H
#define VISADEVICES_DEV_NN_SGDUMMY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "generic/generic_signal_generator.h"
#include "system/VisaSession.h"
#include <inttypes.h>

void SGDummy_init(VisaHandle* handle);
void SGDummy_deinit(VisaHandle* handle);

void SGDummy_set_waveform_type(VisaHandle* handle, uint32_t channel, signal_generator_waveform_type value);
void SGDummy_set_waveform_data(VisaHandle* handle, uint32_t channel, bool relative, double *data);
void SGDummy_set_amplitude(VisaHandle* handle, uint32_t channel, double value);
void SGDummy_set_offset(VisaHandle* handle, uint32_t channel, double value);
void SGDummy_set_frequency(VisaHandle* handle, uint32_t channel, double value);
void SGDummy_set_level(VisaHandle* handle, uint32_t channel, double min, double max);
void SGDummy_set_output(VisaHandle* handle, uint32_t channel, bool value);


extern const struct fnc_signal_generator SGDummy_pointer;

#ifdef __cplusplus
}
#endif

#endif //VISADEVICES_DEV_NN_SGDUMMY_H
