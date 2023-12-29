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

#include "system/VisaSession.h"

#include "generic_power_supply_int.h"
#include "devices/dev_NN_PSDummy.h"
#include "devices/dev_KS_6612.h"
#include "devices/dev_SL_SPD3303X.h"
#include "devices/dev_SL_SPS5000X.h"
#include "devices/dev_RG_DP800.h"

const struct fnc_power_supply power_supply_implementation[] = {
        PSDummy_pointer,
        ks6612_pointer,
        SPD3303X_pointer,
        SPS5000X_pointer,
        DP800_pointer};

EXPORT void power_supply_init(VisaHandle* handle) {
	power_supply_implementation[handle->driver_id].fnc_init(handle);
}

EXPORT void power_supply_deinit(VisaHandle* handle) {
	power_supply_implementation[handle->driver_id].fnc_deinit(handle);
}

EXPORT void power_supply_set_current(VisaHandle* handle, uint32_t channel, double value) {
	power_supply_implementation[handle->driver_id].fnc_set_current(handle, channel, value);
}

EXPORT double power_supply_get_current(VisaHandle* handle, uint32_t channel) {
	return power_supply_implementation[handle->driver_id].fnc_get_current(handle, channel);
}

EXPORT double power_supply_get_current_min(VisaHandle* handle, uint32_t channel) {
	return power_supply_implementation[handle->driver_id].fnc_get_current_min(handle, channel);
}

EXPORT double power_supply_get_current_max(VisaHandle* handle, uint32_t channel) {
	return power_supply_implementation[handle->driver_id].fnc_get_current_max(handle, channel);
}

EXPORT void power_supply_set_voltage(VisaHandle* handle, uint32_t channel, double value) {
	power_supply_implementation[handle->driver_id].fnc_set_voltage(handle, channel, value);
}

EXPORT double power_supply_get_voltage(VisaHandle* handle, uint32_t channel) {
	return power_supply_implementation[handle->driver_id].fnc_get_voltage(handle, channel);
}

EXPORT double power_supply_get_voltage_min(VisaHandle* handle, uint32_t channel) {
	return power_supply_implementation[handle->driver_id].fnc_get_voltage_min(handle, channel);
}

EXPORT double power_supply_get_voltage_max(VisaHandle* handle, uint32_t channel) {
	return power_supply_implementation[handle->driver_id].fnc_get_voltage_max(handle, channel);
}

EXPORT void power_supply_set_ocp(VisaHandle* handle, uint32_t channel, double value) {
	power_supply_implementation[handle->driver_id].fnc_set_ocp(handle, channel, value);
}

EXPORT double power_supply_get_ocp(VisaHandle* handle, uint32_t channel) {
	return power_supply_implementation[handle->driver_id].fnc_get_ocp(handle, channel);
}

EXPORT double power_supply_get_ocp_min(VisaHandle* handle, uint32_t channel) {
	return power_supply_implementation[handle->driver_id].fnc_get_ocp_min(handle, channel);
}

EXPORT double power_supply_get_ocp_max(VisaHandle* handle, uint32_t channel) {
	return power_supply_implementation[handle->driver_id].fnc_get_ocp_max(handle, channel);
}

EXPORT void power_supply_set_ovp(VisaHandle* handle, uint32_t channel, double value) {
	power_supply_implementation[handle->driver_id].fnc_set_ovp(handle, channel, value);
}

EXPORT double power_supply_get_ovp(VisaHandle* handle, uint32_t channel) {
	return power_supply_implementation[handle->driver_id].fnc_get_ovp(handle, channel);
}

EXPORT double power_supply_get_ovp_min(VisaHandle* handle, uint32_t channel) {
	return power_supply_implementation[handle->driver_id].fnc_get_ovp_min(handle, channel);
}

EXPORT double power_supply_get_ovp_max(VisaHandle* handle, uint32_t channel) {
	return power_supply_implementation[handle->driver_id].fnc_get_ovp_max(handle, channel);
}

EXPORT void power_supply_clear_protection(VisaHandle* handle, uint32_t channel) {
	power_supply_implementation[handle->driver_id].fnc_clear_protection(handle, channel);
}

EXPORT bool power_supply_get_protection(VisaHandle* handle, uint32_t channel) {
	return power_supply_implementation[handle->driver_id].fnc_get_protection(handle, channel);
}

EXPORT void power_supply_set_output(VisaHandle* handle, uint32_t channel, bool value) {
	power_supply_implementation[handle->driver_id].fnc_set_output(handle, channel, value);
}
