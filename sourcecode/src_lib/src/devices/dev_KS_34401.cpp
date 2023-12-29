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

#include "devices/dev_KS_34401.h"
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include "system.h"
#include "generic_multimeter_int.h"



EXPORT void ks34401_init(VisaHandle* handle){
    //TODO: Implementieren
}

EXPORT void ks34401_deinit(VisaHandle* handle){

}


EXPORT void ks34401_beep(VisaHandle* handle) {
	viPrintf(handle->session, "SYST:BEEP\n");
}

//SYS:BEEP:STATE OFF/ON
EXPORT void ks34401_setBeeper(VisaHandle* handle, bool state) {


	if (state) {
		viPrintf(handle->session, "SYS:BEEP:STATE ON");

	}
	else {
		viPrintf(handle->session, "SYS:BEEP:STATE OFF");
	}
}

EXPORT bool ks34401_getBeeper(VisaHandle* handle) {
	return true;
}

EXPORT void ks34401_setMode(VisaHandle* handle, multimeter_mode mode) {
	switch (mode) {
		case Multimeter_Mode_Voltage_DC: {
			viPrintf(handle->session, "CONF:VOLT:DC AUTO\n");
		}break;
		case	Multimeter_Mode_Voltage_AC:
		{
			viPrintf(handle->session, "CONF:VOLT:AC AUTO\n");
		}break;
		case	Multimeter_Mode_Current_DC:
		{
			viPrintf(handle->session, "CONF:CURR:DC AUTO\n");
		}break;
		case	Multimeter_Mode_Current_AC:
		{
			viPrintf(handle->session, "CONF:CURR:AC AUTO\n");
		}break;
		case	Multimeter_Mode_Resistance:
		{
			viPrintf(handle->session, "CONF:RES AUTO");
		}break;
		case	Multimeter_Mode_Frequency:
		{
			viPrintf(handle->session, "CONF:FREQ AUTO");
		}break;
		case	Multimeter_Mode_Period:
		{
			//viPrintf(handle->session, "CONF:CONTinuity AUTO");
		}break;
		case	Multimeter_Mode_Continuity: {
			viPrintf(handle->session, "CONF:CONT AUTO");
		}break;
		case	Multimeter_Mode_Diode:
		{
			viPrintf(handle->session, "CONF:DIOD");
		}break;
	}
	sys_sleep(1000);
}

EXPORT void ks34401_setDisplay(VisaHandle* handle, bool state) {
	if (state) {
		viPrintf(handle->session, "DISP ON\n");
	}
	else {
		viPrintf(handle->session, "DISP OFF\n");
	}
}

EXPORT void ks34401_setDisplayText(VisaHandle* handle, const char *text){
	viPrintf(handle->session, "DISP:TEXT '%s'\n", text);
}
EXPORT void ks34401_getDisplayText(VisaHandle* handle, char *text){
	viPrintf(handle->session, "DISP:TEXT?\n");
	sys_sleep(100);
	viScanf(handle->session,"%s", text);
}

EXPORT void ks34401_clearDisplayText(VisaHandle* handle) {
	viPrintf(handle->session, "DISP:TEXT:CLE\n");
}

EXPORT double ks34401_getMeasurement(VisaHandle* handle, uint32_t channel) {
	char text[100];
	double value;

	viPrintf(handle->session, "READ?\n");
	sys_sleep(100);
	viScanf(handle->session, "%s", text);
	value = std::atof(text);

	return value;
}

EXPORT void ks34401_getID(VisaHandle* handle, KS34401_Struct_ID* ptrStr) {

	char text[100];
	double value;
	char delimiter[] = ",";
	char* ptr;

	viPrintf(handle->session, "*IDN?");
	sys_sleep(100);
	viScanf(handle->session, "%s", text);

	ptr = std::strtok(text, delimiter);
	strcpy(ptrStr->manufactor, ptr);
	ptr = strtok(NULL, delimiter);
	strcpy(ptrStr->model, ptr);
	ptr = strtok(NULL, delimiter);
	strcpy(ptrStr->serialnumber, ptr);
	ptr = strtok(NULL, delimiter);
	strcpy(ptrStr->version, ptr);
}

EXPORT void ks34401_getVersion(VisaHandle* handle, KS34401_Struct_Version* ptrStr) {
	char text[100];
	double value;
	char delimiter[] = ".";
	char* ptr;

	viPrintf(handle->session, "*SYST:VERS?");
	sys_sleep(100);
	viScanf(handle->session,"%s", text);

	ptr = std::strtok(text, delimiter);
	ptrStr->year = atoi(ptr);
	ptr = strtok(NULL, delimiter);
	ptrStr->version = atoi(ptr);
}


EXPORT bool ks34401_test(VisaHandle* handle) {
	viPrintf(handle->session, "*TST?");
	return false;
}


EXPORT void ks34401_getError(VisaHandle* handle, KS34401_Struct_Error* ptrStr){
	
}

EXPORT void ks34401_reset(VisaHandle* handle) {
	viPrintf(handle->session, "*RST?");
}

EXPORT multimeter_mode ks34401_getMode(VisaHandle* handle) {
	return Multimeter_Mode_Voltage_DC;
}
	
EXPORT void ks34401_setImpMode(VisaHandle* handle, bool state) {
	if (state) {
		viPrintf(handle->session, "INP:IMP:AUTO ON");
	}
	else {
		viPrintf(handle->session, "INP:IMP:AUTO OFF");
	}
}

EXPORT bool ks34401_getImpMode(VisaHandle* handle) {

	return false;
}


const struct fnc_multimeter ks34401_pointer = {
        .fnc_init = ks34401_init,
        .fnc_deinit = ks34401_deinit,
        .fnc_set_mode = ks34401_setMode,
        .fnc_get_measurement = ks34401_getMeasurement

};