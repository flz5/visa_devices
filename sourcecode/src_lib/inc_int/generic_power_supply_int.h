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


#include "system/VisaDevice.h"
#include "system/VisaSession.h"
#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*fncptr_power_supply_init)(VisaHandle* handle);

//Strom
typedef void (*fncptr_power_supply_set_current)(VisaHandle* handle, uint32_t channel, double value);
typedef double (*fncptr_power_supply_get_current)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_power_supply_get_current_min)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_power_supply_get_current_max)(VisaHandle* handle, uint32_t channel);

//Spannung
typedef void (*fncptr_power_supply_set_voltage)(VisaHandle* handle, uint32_t channel, double value);
typedef double (*fncptr_power_supply_get_voltage)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_power_supply_get_voltage_min)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_power_supply_get_voltage_max)(VisaHandle* handle, uint32_t channel);

//�berstrom
typedef void (*fncptr_power_supply_set_ocp)(VisaHandle* handle, uint32_t channel, double value);
typedef double (*fncptr_power_supply_get_ocp)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_power_supply_get_ocp_min)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_power_supply_get_ocp_max)(VisaHandle* handle, uint32_t channel);

//�berspannung
typedef void (*fncptr_power_supply_set_ovp)(VisaHandle* handle, uint32_t channel, double value);
typedef double (*fncptr_power_supply_get_ovp)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_power_supply_get_ovp_min)(VisaHandle* handle, uint32_t channel);
typedef double (*fncptr_power_supply_get_ovp_max)(VisaHandle* handle, uint32_t channel);

//Sicherheits�berwachung
typedef void (*fncptr_power_supply_clear_protection)(VisaHandle* handle, uint32_t channel);
typedef bool (*fncptr_power_supply_get_protection)(VisaHandle* handle, uint32_t channel);

//Ausgang
typedef void (*fncptr_power_supply_set_output)(VisaHandle* handle, uint32_t channel, bool value);

struct fnc_power_supply {
	fncptr_power_supply_set_current fnc_set_current;
	fncptr_power_supply_get_current fnc_get_current;
	fncptr_power_supply_get_current_min fnc_get_current_min;
	fncptr_power_supply_get_current_max fnc_get_current_max;

	fncptr_power_supply_set_voltage fnc_set_voltage;
	fncptr_power_supply_get_voltage fnc_get_voltage;
	fncptr_power_supply_get_voltage_min fnc_get_voltage_min;
	fncptr_power_supply_get_voltage_max fnc_get_voltage_max;

	fncptr_power_supply_set_ocp fnc_set_ocp;
	fncptr_power_supply_get_ocp fnc_get_ocp;
	fncptr_power_supply_get_ocp_min fnc_get_ocp_min;
	fncptr_power_supply_get_ocp_max fnc_get_ocp_max;

	fncptr_power_supply_set_ovp fnc_set_ovp;
	fncptr_power_supply_get_ovp fnc_get_ovp;
	fncptr_power_supply_get_ovp_min fnc_get_ovp_min;
	fncptr_power_supply_get_ovp_max fnc_get_ovp_max;

	fncptr_power_supply_clear_protection fnc_clear_protection;
	fncptr_power_supply_get_protection fnc_get_protection;

	fncptr_power_supply_set_output fnc_set_output;

	fncptr_power_supply_init fnc_init;
	fncptr_power_supply_init fnc_deinit;

};

#ifdef __cplusplus
}
#endif

#endif