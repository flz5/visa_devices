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

#include "devices/dev_KS_6612.h"
#include <cstdlib>
#include "system.h"
#include "generic_power_supply_int.h"
#include <string.h>


EXPORT void ks6612_init(VisaHandle* handle) {

}

EXPORT void ks6612_deinit(VisaHandle* handle) {

}

EXPORT void ks6612_getVersion(VisaHandle* handle, KS6612_Struct_Version* ptrStr) {
	char text[100];
	double value;
	char delimiter[] = ".";
	char* ptr;

	viPrintf(handle->session, "*SYST:VERS?\n");
	sys_sleep(100);
	viScanf(handle->session, text);

	ptr = strtok(text, delimiter);
	ptrStr->year = atoi(ptr);
	ptr = strtok(NULL, delimiter);
	ptrStr->version = atoi(ptr);
}

EXPORT void ks6612_getID(VisaHandle* handle, KS6612_Struct_ID* ptrStr) {
	char text[100];
	char delimiter[] = ",";
	char* ptr;

	viPrintf(handle->session, "*IDN?\n");
	sys_sleep(100);
	viScanf(handle->session, "%s", text);

	ptr = strtok(text, delimiter);
	strcpy(ptrStr->manufactor, ptr);
	ptr = strtok(NULL, delimiter);
	strcpy(ptrStr->model, ptr);
	ptr = strtok(NULL, delimiter);
	strcpy(ptrStr->serialnumber, ptr);
	ptr = strtok(NULL, delimiter);
	strcpy(ptrStr->version, ptr);
}

EXPORT void ks6612_getError(VisaHandle* handle, KS6612_Struct_Error* ptrStr) {

}

EXPORT void ks6612_setDisplay(VisaHandle* handle, bool state) {
	if (state) {
		viPrintf(handle->session, "DISP ON\n");
	}
	else {
		viPrintf(handle->session, "DISP OFF\n");
	}
}

EXPORT void ks6612_setDisplayText(VisaHandle* handle, const char* text) {
	viPrintf(handle->session, "DISP:TEXT '%s'\n", text);
}

EXPORT void ks6612_getDisplayText(VisaHandle* handle, char* text) {
	viPrintf(handle->session, "DISP:TEXT?\n");
	sys_sleep(100);
	viScanf(handle->session, text);
}

EXPORT void ks6612_clearDisplayText(VisaHandle* handle) {
	viPrintf(handle->session, "DISP:TEXT:CLE\n");
}

EXPORT void ks6612_setDisplayMode(VisaHandle* handle, KS6612_Display_Mode mode) {
	if (mode == KS6612_Display_Mode_Text) {
		viPrintf(handle->session, "DISP:MODE TEXT\n");
	}
	else {
		viPrintf(handle->session, "DISP:MODE NORM\n");
	}
}

EXPORT void ks6612_set_voltage(VisaHandle* handle, uint32_t channel, double voltage) {
	viPrintf(handle->session, "VOLT %.4f\n", voltage);
}

EXPORT double ks6612_get_voltage(VisaHandle* handle,uint32_t channel) {
	char text[100];
	double value;

	viPrintf(handle->session, "VOLT?\n");
	sys_sleep(100);
	viScanf(handle->session,"%s", text);
	value = std::atof(text);

	return value;
}

EXPORT double ks6612_get_voltage_min(VisaHandle* handle, uint32_t channel) {
	return 0.0;
}

EXPORT double ks6612_get_voltage_max(VisaHandle* handle, uint32_t channel) {
	char text[100];
	double value;

	viPrintf(handle->session, "VOLT MAX?\n");
	sys_sleep(100);
	viScanf(handle->session, "%s", text);
	value = std::atof(text);

	return value;
}

EXPORT void ks6612_set_ovp(VisaHandle* handle, uint32_t channel, double ovp_voltage) {
	viPrintf(handle->session, "VOLT:PROT %.4\nf", ovp_voltage);
}

EXPORT double ks6612_get_ovp(VisaHandle* handle, uint32_t channel) {
	char text[100];
	double value;

	viPrintf(handle->session, "VOLT:PROT?\n");
	sys_sleep(100);
	viScanf(handle->session, "%s", text);
	value = std::atof(text);

	return value;
}

EXPORT double ks6612_get_ovp_min(VisaHandle* handle, uint32_t channel) {
	return 0.0;
}

EXPORT double ks6612_get_ovp_max(VisaHandle* handle, uint32_t channel) {
	char text[100];
	double value;

	viPrintf(handle->session, "VOLT:PROT Max?\n");
	sys_sleep(100);
	viScanf(handle->session, "%s", text);
	value = std::atof(text);

	return value;
}

EXPORT void ks6612_set_current(VisaHandle* handle, uint32_t channel, double current) {
	viPrintf(handle->session, "CURR %.4f\n", current);
}

EXPORT double ks6612_get_current(VisaHandle* handle, uint32_t channel) {
	char text[100];
	double value;

	viPrintf(handle->session, "MEAS:CURR?\n");
	sys_sleep(100);
	viScanf(handle->session, "%s", text);
	value = std::atof(text);

	return value;
}


EXPORT double ks6612_get_current_min(VisaHandle* handle, uint32_t channel) {
	return 0.0;
}

EXPORT double ks6612_get_current_max(VisaHandle* handle, uint32_t channel) {
	char text[100];
	double value;

	viPrintf(handle->session, "CURR MAX?\n");
	sys_sleep(100);
	viScanf(handle->session,"%s", text);
	value = std::atof(text);

	return value;
}

EXPORT void ks6612_set_ocp(VisaHandle* handle, uint32_t channel, double ocp_current) {
	viPrintf(handle->session, "CURR:PROT %.4f\n", ocp_current);
}

EXPORT double ks6612_get_ocp(VisaHandle* handle, uint32_t channel) {
	char text[100];
	double value;

	viPrintf(handle->session, "CURR:PROT?\n");
	sys_sleep(100);
	viScanf(handle->session, "%s", text);
	value = std::atof(text);

	return value;
}

EXPORT double ks6612_get_ocp_min(VisaHandle* handle, uint32_t channel) {
	return 0.0;
}

EXPORT double ks6612_get_ocp_max(VisaHandle* handle, uint32_t channel) {
	char text[100];
	double value;

	viPrintf(handle->session, "CURR MAX?\n");
    sys_sleep(100);
	viScanf(handle->session, "%s", text);
	value = std::atof(text);

	return value;
}

EXPORT void ks6612_clear_protection(VisaHandle* handle, uint32_t channel) {
	viPrintf(handle->session, "OUTP:PROT:CLE\n");
}

EXPORT bool ks6612_get_protection(VisaHandle* handle, uint32_t channel) {
	return false;
}

EXPORT void ks6612_set_output(VisaHandle* handle, uint32_t channel, bool state) {
	if (state) {
		viPrintf(handle->session, "OUTP ON\n");
	}
	else {
		viPrintf(handle->session, "OUTP OFF\n");
	}
}

const struct fnc_power_supply ks6612_pointer = {
	.fnc_set_current = ks6612_set_current,
	.fnc_get_current = ks6612_get_current,
	.fnc_get_current_min = ks6612_get_current_min,
	.fnc_get_current_max = ks6612_get_current_max,

	.fnc_set_voltage = ks6612_set_voltage,
	.fnc_get_voltage = ks6612_get_voltage,
	.fnc_get_voltage_min = ks6612_get_voltage_min,
	.fnc_get_voltage_max = ks6612_get_voltage_max,

	.fnc_set_ocp = ks6612_set_ocp,
	.fnc_get_ocp = ks6612_get_ocp,
	.fnc_get_ocp_min = ks6612_get_ocp_min,
	.fnc_get_ocp_max = ks6612_get_ocp_max,

	.fnc_set_ovp = ks6612_set_ovp,
	.fnc_get_ovp = ks6612_get_ovp,
	.fnc_get_ovp_min = ks6612_get_ovp_min,
	.fnc_get_ovp_max = ks6612_get_ovp_max,

	.fnc_clear_protection = ks6612_clear_protection,
	.fnc_get_protection = ks6612_get_protection,

	.fnc_set_output = ks6612_set_output,

	.fnc_init = ks6612_init,
	.fnc_deinit = ks6612_deinit
};
