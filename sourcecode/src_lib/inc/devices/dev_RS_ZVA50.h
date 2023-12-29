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

#ifndef _DEV_RS_ZVA50_H_
#define _DEV_RS_ZVA50_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "system/VisaSession.h"
#include <stdint.h>
#include <inttypes.h>

struct zva50_handle {
	int matrix;
	int lowerFreq;	//unteres Frequenzlimit
	int upperFreq;	//oberes Frequenzlimit
	int spanFreq;
	int centerFreq;		//Mittlere Frequenz
	int numPoints;	//Anzahl der Messpunkte
};

EXPORT void zva50_init(VisaHandle* handle);
EXPORT void zva50_deinit(VisaHandle* handle);

EXPORT void zva50_set_span(VisaHandle* handle, uint32_t span);
EXPORT void zva50_set_lowerFreq(VisaHandle* handle, uint32_t lower);
EXPORT void zva50_set_upperFreq(VisaHandle* handle, uint32_t upper);
EXPORT void zva50_set_centerFreq(VisaHandle* handle, uint32_t center);
EXPORT void zva50_set_bandwidth(VisaHandle* handle, uint32_t bw);
EXPORT void zva50_set_numPoints(VisaHandle* handle, uint32_t points);
EXPORT void zva50_set_power(VisaHandle* handle, uint32_t power);

EXPORT void zva50_set_matrix(VisaHandle* handle, uint32_t count);

//Store touchstone via ZVA to specified filename
EXPORT void zva50_store_touchstone(VisaHandle* handle, char *filename);

//Get Tocuhstone file �ber VISA and store locally
EXPORT void zva50_get_touchstone(VisaHandle*handle, char *filename);

#endif

#ifdef __cplusplus
}
#endif