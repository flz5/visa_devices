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

#include "devices/dev_NN_MMDummy.h"
#include "generic_multimeter_int.h"

EXPORT void MMDummy_init(VisaHandle* handle){

}

EXPORT void MMDummy_deinit(VisaHandle* handle){

}

EXPORT  void MMDummy_setMode(VisaHandle* handle, multimeter_mode mode){

}

EXPORT  double MMDummy_getMeasurement(VisaHandle* handle, uint32_t channel){
    return 0.0;

}

const struct fnc_multimeter MMDummy_pointer = {
        .fnc_init = MMDummy_init,
        .fnc_deinit = MMDummy_deinit,
        .fnc_set_mode = MMDummy_setMode,
        .fnc_get_measurement = MMDummy_getMeasurement

};