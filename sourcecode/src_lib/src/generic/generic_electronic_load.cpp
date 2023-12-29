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
#include "generic/generic_electronic_load.h"
#include "generic_electronic_load_int.h"
#include "devices/dev_GW_PEL3000E.h"
#include "devices/dev_NN_ELDummy.h"

const struct fnc_electronic_load electronic_load_implementation[2] = {ELDummy_pointer, pel3000e_pointer};

EXPORT void electronic_load_set_current(VisaHandle* handle, uint32_t channel, double value) {
	electronic_load_implementation[handle->driver_id].fnc_set_current(handle, channel, value);
}

EXPORT double electronic_load_get_current(VisaHandle* handle, uint32_t channel) {
	return electronic_load_implementation[handle->driver_id].fnc_get_current(handle, channel);
}

EXPORT double electronic_load_get_current_min(VisaHandle* handle, uint32_t channel) {
	return electronic_load_implementation[handle->driver_id].fnc_get_current_min(handle, channel);
}

EXPORT double electronic_load_get_current_max(VisaHandle* handle, uint32_t channel) {
	return electronic_load_implementation[handle->driver_id].fnc_get_current_max(handle, channel);
}

EXPORT void electronic_load_set_voltage(VisaHandle* handle, uint32_t channel, double value) {
	electronic_load_implementation[handle->driver_id].fnc_set_voltage(handle, channel, value);
}

EXPORT double electronic_load_get_voltage(VisaHandle* handle, uint32_t channel) {
	return electronic_load_implementation[handle->driver_id].fnc_get_voltage(handle, channel);
}

EXPORT double electronic_load_get_voltage_min(VisaHandle* handle, uint32_t channel) {
	return electronic_load_implementation[handle->driver_id].fnc_get_voltage_min(handle, channel);
}

EXPORT double electronic_load_get_voltage_max(VisaHandle* handle, uint32_t channel) {
	return electronic_load_implementation[handle->driver_id].fnc_get_voltage_max(handle, channel);
}

EXPORT void electronic_load_set_resistance(VisaHandle* handle, uint32_t channel, double value) {
	electronic_load_implementation[handle->driver_id].fnc_set_resistance(handle, channel, value);
}

EXPORT double electronic_load_get_resistance(VisaHandle* handle, uint32_t channel) {
	return electronic_load_implementation[handle->driver_id].fnc_get_resistance(handle, channel);
}

EXPORT double electronic_load_get_resistance_min(VisaHandle* handle, uint32_t channel) {
	return electronic_load_implementation[handle->driver_id].fnc_get_resistance_min(handle, channel);
}

EXPORT double electronic_load_get_resistance_max(VisaHandle* handle, uint32_t channel) {
	return electronic_load_implementation[handle->driver_id].fnc_get_resistance_max(handle, channel);
}

EXPORT void electronic_load_set_power(VisaHandle* handle, uint32_t channel, double value) {
	electronic_load_implementation[handle->driver_id].fnc_set_power(handle, channel, value);
}

EXPORT double electronic_load_get_power(VisaHandle* handle, uint32_t channel) {
	return electronic_load_implementation[handle->driver_id].fnc_get_power(handle, channel);
}

EXPORT double electronic_load_get_power_min(VisaHandle* handle, uint32_t channel) {
	return electronic_load_implementation[handle->driver_id].fnc_get_power_min(handle, channel);
}

EXPORT double electronic_load_get_power_max(VisaHandle* handle, uint32_t channel) {
	return electronic_load_implementation[handle->driver_id].fnc_get_power_max(handle, channel);
}

EXPORT void electronic_load_set_output(VisaHandle* handle, uint32_t channel, bool value) {
	electronic_load_implementation[handle->driver_id].fnc_set_output(handle, channel, value);
}

EXPORT void electronic_load_set_mode(VisaHandle* handle, uint32_t channel, electronic_load_mode_t value) {
	electronic_load_implementation[handle->driver_id].fnc_set_mode(handle,channel, value);
}