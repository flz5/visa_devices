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

#include "devices/dev_NN_ELDummy.h"
#include "generic_electronic_load_int.h"

EXPORT void ELDummy_init(VisaHandle* handle){

}

EXPORT void ELDummy_deinit(VisaHandle* handle){

}

EXPORT void ELDummy_set_current(VisaHandle* handle, uint32_t channel, double value){

}

EXPORT double ELDummy_get_current(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double ELDummy_get_current_min(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double ELDummy_get_current_max(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT void ELDummy_set_voltage(VisaHandle* handle, uint32_t channel, double value){

}

EXPORT double ELDummy_get_voltage(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double ELDummy_get_voltage_min(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double ELDummy_get_voltage_max(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT void ELDummy_set_resistance(VisaHandle* handle, uint32_t channel, double value){

}

EXPORT double ELDummy_get_resistance(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double ELDummy_get_resistance_min(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double ELDummy_get_resistance_max(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT void ELDummy_set_power(VisaHandle* handle, uint32_t channel, double value){

}

EXPORT double ELDummy_get_power(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double ELDummy_get_power_min(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double ELDummy_get_power_max(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT void ELDummy_set_output(VisaHandle* handle, uint32_t channel, bool value){

}

EXPORT void ELDummy_set_mode(VisaHandle* handle, uint32_t channel, electronic_load_mode_t value){

}

const struct fnc_electronic_load ELDummy_pointer = {
        .fnc_set_current = ELDummy_set_current,
        .fnc_get_current = ELDummy_get_current,
        .fnc_get_current_min = ELDummy_get_current_min,
        .fnc_get_current_max = ELDummy_get_current_max,
        .fnc_set_voltage = ELDummy_set_voltage,
        .fnc_get_voltage = ELDummy_get_voltage,
        .fnc_get_voltage_min = ELDummy_get_voltage_min,
        .fnc_get_voltage_max = ELDummy_get_voltage_max,
        .fnc_set_resistance = ELDummy_set_resistance,
        .fnc_get_resistance = ELDummy_get_resistance,
        .fnc_get_resistance_min = ELDummy_get_resistance_min,
        .fnc_get_resistance_max = ELDummy_get_resistance_max,
        .fnc_set_power = ELDummy_set_power,
        .fnc_get_power = ELDummy_get_power,
        .fnc_get_power_min = ELDummy_get_power_min,
        .fnc_get_power_max = ELDummy_get_power_max,
        .fnc_set_output = ELDummy_set_output,
        .fnc_set_mode = ELDummy_set_mode

};