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

#include "devices/dev_RS_ZVA50.h"
#include <fstream>
#include "memory.hpp"
#include "system/VisaSession.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


EXPORT void zva50_init(VisaHandle* handle) {
	handle->device_storage = new zva50_handle();
}

EXPORT void zva50_deinit(VisaHandle* handle) {
	delete handle->device_storage;
}

EXPORT void zva50_set_span(VisaHandle* handle, uint32_t span) {
	viPrintf(handle->session, "SENS1:FREQ:SPAN  %i\n", span);
	static_cast<zva50_handle*>(handle->device_storage)->spanFreq = span;
	static_cast<zva50_handle*>(handle->device_storage)->lowerFreq = static_cast<zva50_handle*>(handle->device_storage)->centerFreq - (span / 2);
	static_cast<zva50_handle*>(handle->device_storage)->upperFreq = static_cast<zva50_handle*>(handle->device_storage)->centerFreq + (span / 2);
}

EXPORT void zva50_set_lowerFreq(VisaHandle* handle, uint32_t lower) {
	viPrintf(handle->session, "SENS:FREQuency:START %i\n", lower);
	static_cast<zva50_handle*>(handle->device_storage)->lowerFreq = lower;
	static_cast<zva50_handle*>(handle->device_storage)->spanFreq = static_cast<zva50_handle*>(handle->device_storage)->upperFreq - lower;
	static_cast<zva50_handle*>(handle->device_storage)->centerFreq = lower + (static_cast<zva50_handle*>(handle->device_storage)->spanFreq / 2);
}

EXPORT void zva50_set_upperFreq(VisaHandle* handle, uint32_t upper) {
	viPrintf(handle->session, "SENS:FREQuency:STOP %i\n", upper);
	static_cast<zva50_handle*>(handle->device_storage)->upperFreq = upper;
	static_cast<zva50_handle*>(handle->device_storage)->spanFreq = upper - static_cast<zva50_handle*>(handle->device_storage)->lowerFreq;
	static_cast<zva50_handle*>(handle->device_storage)->centerFreq = upper - (static_cast<zva50_handle*>(handle->device_storage)->spanFreq / 2);
}

EXPORT void zva50_set_centerFreq(VisaHandle* handle, uint32_t center) {
	viPrintf(handle->session, "SENS1:FREQ:CENT %i\n", center);
}

EXPORT void zva50_set_bandwidth(VisaHandle* handle, uint32_t bw) {
	viPrintf(handle->session, "SENS1:BAND  %i\n", bw);
}

EXPORT void zva50_set_numPoints(VisaHandle* handle, uint32_t points) {
	viPrintf(handle->session, "SENS1:SWE:POIN   %i\n", points);
}

EXPORT void zva50_set_power(VisaHandle* handle, uint32_t power) {
	viPrintf(handle->session, "SOUR:POW  %i\n", power);
}

EXPORT void zva50_set_matrix(VisaHandle* handle, uint32_t count) {
	switch (count) {
	case 1: {
		viPrintf(handle->session, "CALCulate:PARameter:DEFine:SGRoup 1");
	}break;
	case 2: {
		viPrintf(handle->session, "CALCulate:PARameter:DEFine:SGRoup 1,2");
	}break;
	case 3: {
		viPrintf(handle->session, "CALCulate:PARameter:DEFine:SGRoup 1,2,3");
	}break;
	case 4: {
		viPrintf(handle->session, "CALCulate:PARameter:DEFine:SGRoup 1,2,3,4");
	}break;

	}
	static_cast<zva50_handle*>(handle->device_storage)->matrix = count;
}

//Store touchstone via ZVA to specified filename
EXPORT void zva50_store_touchstone(VisaHandle* handle, char* filename) {

}

//Get Tocuhstone file �ber VISA and store locally
EXPORT void zva50_get_touchstone(VisaHandle* handle, char* filename) {
	char* text = new char[10000000];

	viPrintf(handle->session, "CALCulate:DATA:SGRoup ? SDATa");
	viScanf(handle->session, text);

	int fstep = static_cast<zva50_handle*>(handle->device_storage)->spanFreq / static_cast<zva50_handle*>(handle->device_storage)->numPoints;
	int pcount = static_cast<zva50_handle*>(handle->device_storage)->matrix * static_cast<zva50_handle*>(handle->device_storage)->matrix; //^2 anzahl an parametern

	char**** arr = mem_alloc_3d<char*>(pcount, 2, static_cast<zva50_handle*>(handle->device_storage)->numPoints);
	
	std::ofstream myfile;
	myfile.open(filename, std::ios::out);

	myfile << "! Created unknown\n";
	myfile << "# Hz S RI R 50 \n";
	myfile << "!freq RelS11 ImS11 \n";

	for (int i = 0; i < pcount; i++) {
		for (int j = 0; j < static_cast<zva50_handle*>(handle->device_storage)->numPoints; j++) {
			for (int k = 0; k < 2; k++) {

				//S11 S11 S11 S12 S12(RE) S12(IM)

				char *ptr = strtok(NULL, ";");
				arr[i][k][j] = ptr;

			}
		}
	}

	for (int i = 0; i < static_cast<zva50_handle*>(handle->device_storage)->numPoints; i++) {

		int freq = static_cast<zva50_handle*>(handle->device_storage)->lowerFreq;

		if (static_cast<zva50_handle*>(handle->device_storage)->numPoints > 1) {
			freq += i * fstep;
		}

		char fstr[50];
        sprintf(fstr,"%d",freq);
		myfile << fstr << " ";
			
		for (int j = 0; j < pcount; j++) {
			myfile << arr[j][0][i] << " ";
			myfile << arr[j][1][i] << " ";
		}
		myfile << std::endl;
	}

	myfile.close();

	//Speicher wieder freigeben
	mem_dealloc_3d(arr, pcount, 2, static_cast<zva50_handle*>(handle->device_storage)->numPoints);
	delete[] text;
}