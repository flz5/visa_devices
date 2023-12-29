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

#include "devices/dev_NN_PSDummy.h"
#include "generic_power_supply_int.h"

EXPORT void PSDummy_init(VisaHandle* handle){

}

EXPORT void PSDummy_deinit(VisaHandle* handle){

}

EXPORT void PSDummy_set_current(VisaHandle* handle, uint32_t channel, double value){

}

EXPORT double PSDummy_get_current(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double PSDummy_get_current_min(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double PSDummy_get_current_max(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT void PSDummy_set_voltage(VisaHandle* handle, uint32_t channel, double value){

}

EXPORT double PSDummy_get_voltage(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double PSDummy_get_voltage_min(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double PSDummy_get_voltage_max(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT void PSDummy_set_ocp(VisaHandle* handle, uint32_t channel, double value){

}

EXPORT double PSDummy_get_ocp(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double PSDummy_get_ocp_min(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double PSDummy_get_ocp_max(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT void PSDummy_set_ovp(VisaHandle* handle, uint32_t channel, double value){

}

EXPORT double PSDummy_get_ovp(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double PSDummy_get_ovp_min(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT double PSDummy_get_ovp_max(VisaHandle* handle, uint32_t channel){
    return 0.0;
}

EXPORT void PSDummy_clear_protection(VisaHandle* handle, uint32_t channel){

}

EXPORT bool PSDummy_get_protection(VisaHandle* handle, uint32_t channel){
    return false;
}

EXPORT void PSDummy_set_output(VisaHandle* handle, uint32_t channel,bool value){

}

const struct fnc_power_supply PSDummy_pointer = {
        .fnc_set_current = PSDummy_set_current,
        .fnc_get_current = PSDummy_get_current,
        .fnc_get_current_min = PSDummy_get_current_min,
        .fnc_get_current_max = PSDummy_get_current_max,

        .fnc_set_voltage = PSDummy_set_voltage,
        .fnc_get_voltage = PSDummy_get_voltage,
        .fnc_get_voltage_min = PSDummy_get_voltage_min,
        .fnc_get_voltage_max = PSDummy_get_voltage_max,

        .fnc_set_ocp = PSDummy_set_ocp,
        .fnc_get_ocp = PSDummy_get_ocp,
        .fnc_get_ocp_min = PSDummy_get_ocp_min,
        .fnc_get_ocp_max = PSDummy_get_ocp_max,

        .fnc_set_ovp = PSDummy_set_ovp,
        .fnc_get_ovp = PSDummy_get_ovp,
        .fnc_get_ovp_min = PSDummy_get_ovp_min,
        .fnc_get_ovp_max = PSDummy_get_ovp_max,

        .fnc_clear_protection = PSDummy_clear_protection,
        .fnc_get_protection = PSDummy_get_protection,

        .fnc_set_output = PSDummy_set_output,

        .fnc_init = PSDummy_init,
        .fnc_deinit = PSDummy_deinit
};