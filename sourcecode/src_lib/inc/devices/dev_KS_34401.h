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


#ifndef _DEV_KS_34401_H
#define _DEV_KS_34401_H

#ifdef __cplusplus
extern "C" {
#endif

#include "generic/generic_multimeter.h"
#include "system/VisaSession.h"
#include <stdint.h>
#include <inttypes.h>

typedef struct {
	int year;
	int version;
} KS34401_Struct_Version ;

typedef struct {
	char* manufactor;
	char* model;
	char* serialnumber;
	char* version;
} KS34401_Struct_ID;

typedef struct  {
	int id;
	int text;
} KS34401_Struct_Error;


//Measurement Configuration
EXPORT  void ks34401_setMode(VisaHandle* handle, multimeter_mode mode);
EXPORT  multimeter_mode ks34401_getMode(VisaHandle* handle);
EXPORT  void ks34401_setImpMode(VisaHandle* handle, bool state);
EXPORT  bool ks34401_getImpMode(VisaHandle* handle);

//Measurement
EXPORT  double ks34401_getMeasurement(VisaHandle* handle, uint32_t channel);

//System
EXPORT  void ks34401_getVersion(VisaHandle* handle, KS34401_Struct_Version* ptrStr);
EXPORT  bool ks34401_test(VisaHandle* handle);
EXPORT void ks34401_getError(VisaHandle* handle, KS34401_Struct_Error* ptrStr);
EXPORT void ks34401_reset(VisaHandle* handle);
EXPORT void ks34401_getID(VisaHandle* handle, KS34401_Struct_ID* ptrStr);

//Beeper
EXPORT void ks34401_beep(VisaHandle* handle);
EXPORT void ks34401_setBeeper(VisaHandle* handle, bool state);
EXPORT bool ks34401_getBeeper(VisaHandle* handle);

//Display
EXPORT void ks34401_setDisplay(VisaHandle* handle, bool state);
EXPORT void ks34401_setDisplayText(VisaHandle* handle, const char* text);
EXPORT void ks34401_getDisplayText(VisaHandle* handle, char *text);
EXPORT void ks34401_clearDisplayText(VisaHandle* handle);

extern const struct fnc_multimeter ks34401_pointer;

#ifdef __cplusplus
}
#endif

#endif