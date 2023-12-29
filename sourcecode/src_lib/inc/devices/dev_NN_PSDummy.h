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

#ifndef VISADEVICES_DEV_NN_PSDUMMY_H
#define VISADEVICES_DEV_NN_PSDUMMY_H


#ifdef __cplusplus
extern "C" {
#endif

#include "system/VisaSession.h"
#include <inttypes.h>


EXPORT void PSDummy_init(VisaHandle* handle);
EXPORT void PSDummy_deinit(VisaHandle* handle);

EXPORT void PSDummy_set_current(VisaHandle* handle, uint32_t channel, double value);
EXPORT double PSDummy_get_current(VisaHandle* handle, uint32_t channel);
EXPORT double PSDummy_get_current_min(VisaHandle* handle, uint32_t channel);
EXPORT double PSDummy_get_current_max(VisaHandle* handle, uint32_t channel);

EXPORT void PSDummy_set_voltage(VisaHandle* handle, uint32_t channel, double value);
EXPORT double PSDummy_get_voltage(VisaHandle* handle, uint32_t channel);
EXPORT double PSDummy_get_voltage_min(VisaHandle* handle, uint32_t channel);
EXPORT double PSDummy_get_voltage_max(VisaHandle* handle, uint32_t channel);

EXPORT void PSDummy_set_ocp(VisaHandle* handle, uint32_t channel, double value);
EXPORT double PSDummy_get_ocp(VisaHandle* handle, uint32_t channel);
EXPORT double PSDummy_get_ocp_min(VisaHandle* handle, uint32_t channel);
EXPORT double PSDummy_get_ocp_max(VisaHandle* handle, uint32_t channel);

EXPORT void PSDummy_set_ovp(VisaHandle* handle, uint32_t channel, double value);
EXPORT double PSDummy_get_ovp(VisaHandle* handle, uint32_t channel);
EXPORT double PSDummy_get_ovp_min(VisaHandle* handle, uint32_t channel);
EXPORT double PSDummy_get_ovp_max(VisaHandle* handle, uint32_t channel);

EXPORT void PSDummy_clear_protection(VisaHandle* handle, uint32_t channel);
EXPORT bool PSDummy_get_protection(VisaHandle* handle, uint32_t channel);

EXPORT void PSDummy_set_output(VisaHandle* handle, uint32_t channel,bool value);

extern const struct fnc_power_supply PSDummy_pointer;

#ifdef __cplusplus
}
#endif

#endif //VISADEVICES_DEV_NN_PSDUMMY_H
