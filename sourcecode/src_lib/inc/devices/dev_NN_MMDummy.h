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

#ifndef VISADEVICES_DEV_NN_MMDUMMY_H
#define VISADEVICES_DEV_NN_MMDUMMY_H


#ifdef __cplusplus
extern "C" {
#endif

#include "generic/generic_multimeter.h"
#include "system/VisaSession.h"
#include <stdint.h>
#include <inttypes.h>

EXPORT void MMDummy_init(VisaHandle* handle);
EXPORT void MMDummy_deinit(VisaHandle* handle);
EXPORT  void MMDummy_setMode(VisaHandle* handle, multimeter_mode mode);
EXPORT  double MMDummy_getMeasurement(VisaHandle* handle, uint32_t channel);


extern const struct fnc_multimeter MMDummy_pointer;

#ifdef __cplusplus
}
#endif

#endif //VISADEVICES_DEV_NN_MMDUMMY_H
