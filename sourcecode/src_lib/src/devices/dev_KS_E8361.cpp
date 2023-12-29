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

#include "devices/dev_KS_E8361A.h"
#include <iostream>
#include <fstream>
#include <cstring>

EXPORT void kse8361_init(VisaHandle* handle) {
	viSetBuf(handle->session, VI_READ_BUF, 200000 * 10);
}

EXPORT void kse8361_set_trigger_single(VisaHandle* handle) {
	char text[100];
	viPrintf(handle->session, "INITiate1:CONTinuous OFF;*OPC?\n");
	viScanf(handle->session, text);
}

EXPORT void kse8361_set_trigger_continous(VisaHandle* handle) {
	char text[100];
	viPrintf(handle->session, "INITiate1:CONTinuous ON;*OPC?\n");
	viScanf(handle->session, text);
}

EXPORT void kse8361_trigger(VisaHandle* handle) {
	char text[100];
	viPrintf(handle->session, "INITiate1;*OPC?\n");
	viScanf(handle->session, text);
}

//Store touchstone via ZVA to specified filename
EXPORT void kse8361_store_touchstone(VisaHandle* handle, char* filename) {
	viPrintf(handle->session, "MMEM:STOR '%s'\n", filename);
}

//Get Tocuhstone file �ber VISA and store locally
EXPORT void kse8361_get_touchstone(VisaHandle* handle, char* filename) {

	char* text = new char[200000 * 10];

	viPrintf(handle->session, "MMEM:STOR 'c:\\MyData.s2p'\n");
	viPrintf(handle->session, "'MMEM:TRAN? 'c:\\MyData.s2p'\n");
	viScanf(handle->session, text);

	std::ofstream myfile;
	myfile.open(filename, std::ios::out);
	myfile.write(text, strlen(text));
	myfile.close();

	delete[] text;
}