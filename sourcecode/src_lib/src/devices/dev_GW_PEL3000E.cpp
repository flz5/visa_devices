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

#include "devices/dev_GW_PEL3000E.h"
#include "generic_electronic_load_int.h"
#include "system.h"
#include <string>
#include <cstdlib>

EXPORT void pel3000e_set_current(VisaHandle* handle, uint32_t channel, double value) {
	viPrintf(handle->session, "CURRent:RECall A");
	viPrintf(handle->session, "CURRent:VA %.4\nf", value);
}

EXPORT double pel3000e_get_current(VisaHandle* handle, uint32_t channel) {
	char text[100];
	double value;

	viPrintf(handle->session, "MEASure:CURRent?\n");
    sys_sleep(100);
	viScanf(handle->session, "%s", text);
	value = std::atof(text);
	return value;
}

EXPORT double pel3000e_get_current_min(VisaHandle* handle, uint32_t channel) {
	return 0.0;
}

EXPORT double pel3000e_get_current_max(VisaHandle* handle, uint32_t channel) {
	return 0.0;
}

EXPORT void pel3000e_set_voltage(VisaHandle* handle, uint32_t channel, double value) {
	viPrintf(handle->session, "VOLTage:RECall A");
	viPrintf(handle->session, "VOLTage:VA %.4f\n", value);
}

EXPORT double pel3000e_get_voltage(VisaHandle* handle, uint32_t channel) {
	char text[100];
	double value;

	viPrintf(handle->session, "MEASure:VOLTage?\n");
	sys_sleep(100);
	viScanf(handle->session, "%s", text);
	value = std::atof(text);
	return value;
}

EXPORT double pel3000e_get_voltage_min(VisaHandle* handle, uint32_t channel) {
	return 0.0;
}

EXPORT double pel3000e_get_voltage_max(VisaHandle* handle, uint32_t channel) {
	return 0.0;
}

EXPORT void pel3000e_set_resistance(VisaHandle* handle, uint32_t channel, double value) {
	viPrintf(handle->session, "RESistance:RECall A");
	viPrintf(handle->session, "RESistance:VA %.4f\n", value);
}

EXPORT double pel3000e_get_resistance(VisaHandle* handle, uint32_t channel) {
	char text[100];
	double value;

	viPrintf(handle->session, "RESistance:VA?\n");
    sys_sleep(100);
	viScanf(handle->session, "%s", text);
	value = std::atof(text);
	return value;
}

EXPORT double pel3000e_get_resistance_min(VisaHandle* handle, uint32_t channel) {
	return 0.0;
}

EXPORT double pel3000e_get_resistance_max(VisaHandle* handle, uint32_t channel) {
	return 0.0;
}

EXPORT void pel3000e_set_power(VisaHandle* handle, uint32_t channel, double value) {
	viPrintf(handle->session, "POWer:RECall A");
	viPrintf(handle->session, "POWer:VA %.4f\n", value);
}

EXPORT double pel3000e_get_power(VisaHandle* handle, uint32_t channel) {
	char text[100];
	double value;

	viPrintf(handle->session, "MEASure:POWer?\n");
	sys_sleep(100);
	viScanf(handle->session, "%s", text);
	value = std::atof(text);
	return value;
}

EXPORT double pel3000e_get_power_min(VisaHandle* handle, uint32_t channel) {
	return 0.0;
}

EXPORT double pel3000e_get_power_max(VisaHandle* handle, uint32_t channel) {
	return 0.0;
}

EXPORT void pel3000e_set_output(VisaHandle* handle, uint32_t channel, bool value) {
	if (value) {
		viPrintf(handle->session, "INPut ON\n");
	}
	else {
		viPrintf(handle->session, "INPut OFF\n");
	}
}

EXPORT void pel3000e_set_mode(VisaHandle* handle, uint32_t channel, electronic_load_mode_t value) {

	switch (value) {
		case LOAD_MODE_CURRENT: {
			viPrintf(handle->session, "NSEQuence:MODE CC\n");
		}break;
		case LOAD_MODE_VOLTAGE: {
			viPrintf(handle->session, "NSEQuence:MODE CV\n");
		}break;
		case LOAD_MODE_RESISTANCE: {
			viPrintf(handle->session, "NSEQuence:MODE CR\n");
		}break;
		case LOAD_MODE_POWER: {
			viPrintf(handle->session, "NSEQuence:MODE CP\n");
		}break;
	}
}

const struct fnc_electronic_load pel3000e_pointer = {
	.fnc_set_current = pel3000e_set_current,
	.fnc_get_current = pel3000e_get_current,
	.fnc_get_current_min = pel3000e_get_current_min,
	.fnc_get_current_max = pel3000e_get_current_max,
	.fnc_set_voltage = pel3000e_set_voltage,
	.fnc_get_voltage = pel3000e_get_voltage,
	.fnc_get_voltage_min = pel3000e_get_voltage_min,
	.fnc_get_voltage_max = pel3000e_get_voltage_max,
	.fnc_set_resistance = pel3000e_set_resistance,
	.fnc_get_resistance = pel3000e_get_resistance,
	.fnc_get_resistance_min = pel3000e_get_resistance_min,
	.fnc_get_resistance_max = pel3000e_get_resistance_max,
	.fnc_set_power = pel3000e_set_power,
	.fnc_get_power = pel3000e_get_power,
	.fnc_get_power_min = pel3000e_get_power_min,
	.fnc_get_power_max = pel3000e_get_power_max,
	.fnc_set_output = pel3000e_set_output,
	.fnc_set_mode = pel3000e_set_mode

};