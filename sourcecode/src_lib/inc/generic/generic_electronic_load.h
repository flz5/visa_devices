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

#ifndef _GENERIC_ELECTRONIC_LOAD_H
#define _GENERIC_ELECTRONIC_LOAD_H

#ifdef __cplusplus
extern "C" {
#endif

#include "system/VisaSession.h"
#include <inttypes.h>

typedef enum {
		LOAD_MODE_CURRENT = 0,
		LOAD_MODE_VOLTAGE = 1,
		LOAD_MODE_RESISTANCE = 2,
		LOAD_MODE_POWER = 3
} electronic_load_mode_t;

/**
 *
 * @param handle
 * @param channel
 * @param value
 */
EXPORT void electronic_load_set_current(VisaHandle* handle, uint32_t channel, double value);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double electronic_load_get_current(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double electronic_load_get_current_min(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double electronic_load_get_current_max(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @param value
 */
EXPORT void electronic_load_set_voltage(VisaHandle* handle, uint32_t channel, double value);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double electronic_load_get_voltage(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double electronic_load_get_voltage_min(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double electronic_load_get_voltage_max(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @param value
 */
EXPORT void electronic_load_set_resistance(VisaHandle* handle, uint32_t channel, double value);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double electronic_load_get_resistance(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double electronic_load_get_resistance_min(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double electronic_load_get_resistance_max(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @param value
 */
EXPORT void electronic_load_set_power(VisaHandle* handle, uint32_t channel, double value);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double electronic_load_get_power(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double electronic_load_get_power_min(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double electronic_load_get_power_max(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @param value
 */
EXPORT void electronic_load_set_output(VisaHandle* handle, uint32_t channel, bool value);

/**
 *
 * @param handle
 * @param channel
 * @param value
 */
EXPORT void electronic_load_set_mode(VisaHandle* handle, uint32_t channel, electronic_load_mode_t value);


#ifdef __cplusplus
}
#endif

#endif