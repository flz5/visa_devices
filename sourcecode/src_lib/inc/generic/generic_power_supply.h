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

#ifdef __cplusplus
extern "C" {
#endif

#include "system/VisaSession.h"
#include <inttypes.h>

/**
 *
 * @param handle Handle for the device
 */
EXPORT void power_supply_init(VisaHandle* handle);

/**
 *
 * @param handle Handle for the device
 */
EXPORT void power_supply_deinit(VisaHandle* handle);

/**
 *
 * @param handle Handle for the device
 * @param channel
 * @param value
 */
EXPORT void power_supply_set_current(VisaHandle* handle, uint32_t channel, double value);

/**
 *
 * @param handle Handle for the device
 * @param channel
 * @return
 */
EXPORT double power_supply_get_current(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle Handle for the device
 * @param channel
 * @return
 */
EXPORT double power_supply_get_current_min(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle Handle for the device
 * @param channel
 * @return
 */
EXPORT double power_supply_get_current_max(VisaHandle* handle, uint32_t channel);

/**
 * Sets the output voltage
 * @param handle Handle for the device
 * @param channel Channel
 * @param value Output voltage in volts
 */
EXPORT void power_supply_set_voltage(VisaHandle* handle, uint32_t channel, double value);

/**
 * Returns the measured voltage at the output of the channel
 * @param handle Handle for the device
 * @param channel Channel
 * @return Measured voltage
 */
EXPORT double power_supply_get_voltage(VisaHandle* handle, uint32_t channel);

/**
 * Return the minimun configurabele output voltage of the selected channel
 * @param handle Handle for the device
 * @oaram channel Channdel
 */
EXPORT double power_supply_get_voltage_min(VisaHandle* handle, uint32_t channel);

/**
 * Return the maxmimem configurable output voltage of the selected channel
 * @param handle Handle for the device
 * @param channel
 * @return
 */
EXPORT double power_supply_get_voltage_max(VisaHandle* handle, uint32_t channel);

/**
 * Sets the over-current-protection for the selected channel
 * @param handle Handle for the device
 * @param channel Channel
 * @param value OCP limit im Amps
 */
EXPORT void power_supply_set_ocp(VisaHandle* handle, uint32_t channel, double value);

/**
 *
 * @param handle Handle for the device
 * @param channel
 * @return
 */
EXPORT double power_supply_get_ocp(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double power_supply_get_ocp_max(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @param value
 */
EXPORT void power_supply_set_ovp(VisaHandle* handle, uint32_t channel, double value);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double power_supply_get_ovp(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double power_supply_get_ovp_min(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT double power_supply_get_ovp_max(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 */
EXPORT void power_supply_clear_protection(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @return
 */
EXPORT bool power_supply_get_protection(VisaHandle* handle, uint32_t channel);

/**
 *
 * @param handle
 * @param channel
 * @param value
 */
EXPORT void power_supply_set_output(VisaHandle* handle, uint32_t channel, bool value);

#ifdef __cplusplus
}
#endif

#endif