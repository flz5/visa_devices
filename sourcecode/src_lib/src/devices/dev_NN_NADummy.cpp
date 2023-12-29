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

#include "devices/dev_NN_NADummy.h"
#include "generic_network_analyzer_int.h"

EXPORT void NADummy_init(VisaHandle* handle){

}
EXPORT void NADummy_deinit(VisaHandle* handle){

}

EXPORT void NADummy_set_span_cr(VisaHandle* handle, uint32_t channel, double center, double range){

}
EXPORT void NADummy_set_span_lh(VisaHandle* handle, uint32_t channel, double low, double high){

}
EXPORT double* NADummy_get_waveform(VisaHandle* handle, uint32_t channel){
        return nullptr;
}

EXPORT void NADummy_save_waveform(VisaHandle* handle, uint32_t channel, char *filename){

}

const struct fnc_network_analyzer NADummy_pointer = {

        .fnc_set_span_cr = NADummy_set_span_cr,
        .fnc_set_span_lh = NADummy_set_span_lh,
        .fnc_get_waveform = NADummy_get_waveform,
        .fnc_save_waveform = NADummy_save_waveform,
        .fnc_init = NADummy_init,
        .fnc_deinit = NADummy_deinit

};
