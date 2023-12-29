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

/*

This device driver can be used for multiple devices. The following oscilloscoped are supported:
	6611	
	6612	
	6613	
	6614	
	66312	
	66332	
	6631	
	6632	
	6633	
	6634

Revision of the devices are mentioned here as there should be no difference for the interface. 
The features itself may be different.

Info: 
Not all possible features are implemented at the moment.

Limitations:
No detection of the device limits	
	
*/

#ifndef _KS_6612_H
#define _KS_6612_H

#ifdef __cplusplus
extern "C" {
#endif

#include "system/VisaSession.h"
#include <inttypes.h>

typedef struct {
	char* manufactor;
	char* model;
	char* serialnumber;
	char* version;
} KS6612_Struct_ID;

typedef struct  {
	int year;
	int version;
} KS6612_Struct_Version;

typedef struct  {
	int id;
	int text;
} KS6612_Struct_Error;

typedef enum  {
	KS6612_Display_Mode_Norm,
	KS6612_Display_Mode_Text
} KS6612_Display_Mode;

EXPORT void ks6612_init(VisaHandle* handle);
EXPORT void ks6612_deinit(VisaHandle* handle);

//System
EXPORT void ks6612_getID(VisaHandle* handle, KS6612_Struct_ID* ptrStr);
EXPORT void ks6612_getVersion(VisaHandle* handle, KS6612_Struct_Version* ptrStr);
EXPORT void ks6612_getError(VisaHandle* handle, KS6612_Struct_Error* ptrStr);

//Display
EXPORT void ks6612_setDisplay(VisaHandle* handle, bool state);
EXPORT void ks6612_setDisplayText(VisaHandle* handle, const char* text);
EXPORT void ks6612_getDisplayText(VisaHandle* handle, char* text);
EXPORT void ks6612_clearDisplayText(VisaHandle* handle);
EXPORT void ks6612_setDisplayMode(VisaHandle* handle, KS6612_Display_Mode mode);

//Voltage
EXPORT void ks6612_set_voltage(VisaHandle* handle, uint32_t channel, double voltage);
EXPORT double ks6612_get_voltage(VisaHandle* handle, uint32_t channel);
EXPORT double ks6612_get_voltage_min(VisaHandle* handle, uint32_t channel);
EXPORT double ks6612_get_voltage_max(VisaHandle* handle, uint32_t channel);

EXPORT void ks6612_set_ovp(VisaHandle* handle, uint32_t channel, double ovp_voltage);
EXPORT double ks6612_get_ovp(VisaHandle* handle, uint32_t channel);
EXPORT double ks6612_get_ovp_min(VisaHandle* handle, uint32_t channel);
EXPORT double ks6612_get_ovp_max(VisaHandle* handle, uint32_t channel);

//Current
EXPORT void ks6612_set_current(VisaHandle*, uint32_t channel, double current);
EXPORT double ks6612_get_current(VisaHandle* handle, uint32_t channel);
EXPORT double ks6612_get_current_min(VisaHandle* handle, uint32_t channel);
EXPORT double ks6612_get_current_max(VisaHandle* handle, uint32_t channel);

EXPORT void ks6612_set_ocp(VisaHandle* handle, uint32_t channel, double ocp_current);
EXPORT double ks6612_get_ocp(VisaHandle* handle, uint32_t channel);
EXPORT double ks6612_get_ocp_min(VisaHandle* handle, uint32_t channel);
EXPORT double ks6612_get_ocp_max(VisaHandle* handle, uint32_t channel);

//Output
EXPORT void ks6612_clear_protection(VisaHandle* handle, uint32_t channel);
EXPORT bool ks6612_get_protection(VisaHandle* handle, uint32_t channel);

EXPORT void ks6612_set_output(VisaHandle* handle, uint32_t channel, bool state);

//Generic Interface
extern const struct fnc_power_supply ks6612_pointer;


#ifdef __cplusplus
}
#endif

#endif