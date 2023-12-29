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

#ifndef _GENERIC_MULTIMETER_INT_H
#define _GENERIC_MULTIMETER_INT_H

#include "system/VisaSession.h"
#include "generic/generic_multimeter.h"
#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*fncptr_multimeter_init)(VisaHandle* handle);
typedef void (*fncptr_multimeter_deinit)(VisaHandle* handle);
typedef void (*fncptr_multimeter_set_mode)(VisaHandle* handle, multimeter_mode mode);
typedef double (*fncptr_multimeter_get_measurement)(VisaHandle* handle, uint32_t channel);

struct fnc_multimeter {

	fncptr_multimeter_init fnc_init;
	fncptr_multimeter_init fnc_deinit;

	fncptr_multimeter_set_mode fnc_set_mode;
	fncptr_multimeter_get_measurement fnc_get_measurement;

};

#ifdef __cplusplus
}
#endif

#endif
