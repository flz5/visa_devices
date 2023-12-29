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

#ifndef _GENERIC_ELECTRONIC_LOAD_INT_H
#define _GENERIC_ELECTRONIC_LOAD_INT_H

#include "system/VisaDevice.h"
#include "system/VisaSession.h"
#include "generic/generic_electronic_load.h"
#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

//System
typedef void (*fncptr_electric_load_init)(VisaHandle* handle);

//Strom
typedef void (*fncptr_electric_load_set_current)(VisaHandle* handle, uint32_t channel, double value);
typedef double (*fncptr_electric_load_get_current)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_electric_load_get_current_min)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_electric_load_get_current_max)(VisaHandle* handle, uint32_t channel);

//Spannung
typedef void (*fncptr_electric_load_set_voltage)(VisaHandle* handle, uint32_t channel, double value);
typedef double (*fncptr_electric_load_get_voltage)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_electric_load_get_voltage_min)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_electric_load_get_voltage_max)(VisaHandle* handle, uint32_t channel);

//Widerstand
typedef void (*fncptr_electric_load_set_resistance)(VisaHandle* handle, uint32_t channel, double value);
typedef double (*fncptr_electric_load_get_resistance)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_electric_load_get_resistance_min)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_electric_load_get_resistance_max)(VisaHandle* handle, uint32_t channel);

//Leistung
typedef void (*fncptr_electric_load_set_power)(VisaHandle* handle, uint32_t channel, double value);
typedef double (*fncptr_electric_load_get_power)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_electric_load_get_power_min)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_electric_load_get_power_max)(VisaHandle* handle, uint32_t channel);

//Ausgang
typedef void (*fncptr_electric_load_set_output)(VisaHandle* handle, uint32_t channel, bool value);

//Modus
typedef void (*fncptr_electric_load_set_mode)(VisaHandle* handle, uint32_t channel, electronic_load_mode_t value);


struct fnc_electronic_load {

	fncptr_electric_load_set_current fnc_set_current;
	fncptr_electric_load_get_current fnc_get_current;
	fncptr_electric_load_get_current_min fnc_get_current_min;
	fncptr_electric_load_get_current_max fnc_get_current_max;

	fncptr_electric_load_set_voltage fnc_set_voltage;
	fncptr_electric_load_get_voltage fnc_get_voltage;
	fncptr_electric_load_get_voltage_min fnc_get_voltage_min;
	fncptr_electric_load_get_voltage_max fnc_get_voltage_max;

	fncptr_electric_load_set_resistance fnc_set_resistance;
	fncptr_electric_load_get_resistance fnc_get_resistance;
	fncptr_electric_load_get_resistance_min fnc_get_resistance_min;
	fncptr_electric_load_get_resistance_max fnc_get_resistance_max;

	fncptr_electric_load_set_power fnc_set_power;
	fncptr_electric_load_get_power fnc_get_power;
	fncptr_electric_load_get_power_min fnc_get_power_min;
	fncptr_electric_load_get_power_max fnc_get_power_max;

	fncptr_electric_load_set_output fnc_set_output;
	fncptr_electric_load_set_mode fnc_set_mode;

	fncptr_electric_load_init fnc_init;
	fncptr_electric_load_init fnc_deinit;

};

#ifdef __cplusplus
}
#endif

#endif