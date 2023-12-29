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

#ifndef VISADEVICES_DEV_NN_ELDUMMY_H
#define VISADEVICES_DEV_NN_ELDUMMY_H


#ifdef __cplusplus
extern "C" {
#endif

#include "system/VisaSession.h"
#include "generic/generic_electronic_load.h"
#include <inttypes.h>

EXPORT void ELDummy_init(VisaHandle* handle);
EXPORT void ELDummy_deinit(VisaHandle* handle);

EXPORT void ELDummy_set_current(VisaHandle* handle, uint32_t channel, double value);
EXPORT double ELDummy_get_current(VisaHandle* handle, uint32_t channel);
EXPORT double ELDummy_get_current_min(VisaHandle* handle, uint32_t channel);
EXPORT double ELDummy_get_current_max(VisaHandle* handle, uint32_t channel);

EXPORT void ELDummy_set_voltage(VisaHandle* handle, uint32_t channel, double value);
EXPORT double ELDummy_get_voltage(VisaHandle* handle, uint32_t channel);
EXPORT double ELDummy_get_voltage_min(VisaHandle* handle, uint32_t channel);
EXPORT double ELDummy_get_voltage_max(VisaHandle* handle, uint32_t channel);

EXPORT void ELDummy_set_resistance(VisaHandle* handle, uint32_t channel, double value);
EXPORT double ELDummy_get_resistance(VisaHandle* handle, uint32_t channel);
EXPORT double ELDummy_get_resistance_min(VisaHandle* handle, uint32_t channel);
EXPORT double ELDummy_get_resistance_max(VisaHandle* handle, uint32_t channel);

EXPORT void ELDummy_set_power(VisaHandle* handle, uint32_t channel, double value);
EXPORT double ELDummy_get_power(VisaHandle* handle, uint32_t channel);
EXPORT double ELDummy_get_power_min(VisaHandle* handle, uint32_t channel);
EXPORT double ELDummy_get_power_max(VisaHandle* handle, uint32_t channel);

EXPORT void ELDummy_set_output(VisaHandle* handle, uint32_t channel, bool value);
EXPORT void ELDummy_set_mode(VisaHandle* handle, uint32_t channel, electronic_load_mode_t value);


//Generic Interface
extern const struct fnc_electronic_load ELDummy_pointer;

#ifdef __cplusplus
}
#endif

#endif //VISADEVICES_DEV_NN_ELDUMMY_H
