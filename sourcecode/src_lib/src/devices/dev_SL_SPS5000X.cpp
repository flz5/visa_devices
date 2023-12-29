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

#include "system/VisaSession.h"
#include "devices/dev_SL_SPS5000X.h"
#include "generic_power_supply_int.h"

#include <cstdlib>
#include "system.h"

EXPORT void SPS5000X_init(VisaHandle* handle) {

}

EXPORT void SPS5000X_deinit(VisaHandle* handle) {

}

void SPS5000X_set_current(VisaHandle* handle, uint32_t channel, double value) {
    if (channel == 1) {
        viPrintf(handle->session, "SOURce:CURRent:SET CH1,%.4f\n", value);
    }
    else if (channel == 2) {
        viPrintf(handle->session, "SOURce:CURRent:SET CH2,%.4f\n", value);
    }
}

double SPS5000X_get_current(VisaHandle* handle, uint32_t channel) {
    char text[100];
    double value;

    if (channel == 1) {
        viPrintf(handle->session, "MEASure:CURRent? CH1\n");
    }
    else {
        viPrintf(handle->session, "MEASure:CURRent? CH2\n");
    }

    sys_sleep(100);
    viScanf(handle->session, "%s", text);
    value = std::atof(text);

    return value;
}

double SPS5000X_get_current_min(VisaHandle* handle, uint32_t channel) {
    return 0.0;
}

double SPS5000X_get_current_max(VisaHandle* handle, uint32_t channel) {
    //CH1: 3.2A max
    //CH2: 3.2A max
    if (channel == 1 || channel == 2) {
        return 3.2;
    }
    else {
        return 0.0;
    }
}

void SPS5000X_set_voltage(VisaHandle* handle, uint32_t channel, double value) {
    if (channel == 1) {
        viPrintf(handle->session, "SOURce:VOLTage:SET CH1,%.4f\n", value);
    }
    else if (channel == 2) {
        viPrintf(handle->session, "SOURce:VOLTage:SET CH2,%.4f\n", value);
    }
}

double SPS5000X_get_voltage(VisaHandle* handle, uint32_t channel) {
    char text[100];
    double value;

    if (channel == 1) {
        viPrintf(handle->session, "MEASure:VOLTage? CH1\n");
    }
    else {
        viPrintf(handle->session, "MEASure:VOLTage? CH2\n");
    }

    sys_sleep(100);
    viScanf(handle->session, "%s", text);
    value = std::atof(text);

    return value;
}

double SPS5000X_get_voltage_min(VisaHandle* handle, uint32_t channel) {
    return 0.0;
}

double SPS5000X_get_voltage_max(VisaHandle* handle, uint32_t channel) {
    return 32.0;
}

void SPS5000X_set_ocp(VisaHandle* handle, uint32_t channel, double value) {
    //Function not supported by device
    return;
}

double SPS5000X_get_ocp(VisaHandle* handle, uint32_t channel) {
    //Function not supported by device
    return 0.0;
}

double SPS5000X_get_ocp_min(VisaHandle* handle, uint32_t channel) {
    //Function not supported by device
    return 0.0;
}

double SPS5000X_get_ocp_max(VisaHandle* handle, uint32_t channel) {
    //Function not supported by device
    return 0.0;
}

void SPS5000X_set_ovp(VisaHandle* handle, uint32_t channel, double value) {
    if (channel == 1) {
        viPrintf(handle->session, "SOURce:OVP CH1,%.4f\n", value);
    }
    else if (channel == 2) {
        viPrintf(handle->session, "SOURce:OVP CH2,%.4f\n", value);
    }
}
double SPS5000X_get_ovp(VisaHandle* handle, uint32_t channel) {
    //Function not supported by device
    return 0.0;
}
double SPS5000X_get_ovp_min(VisaHandle* handle, uint32_t channel) {
    //Function not supported by device
    return 0.0;
}
double SPS5000X_get_ovp_max(VisaHandle* handle, uint32_t channel) {
    //Function not supported by device
    return 0.0;
}

void SPS5000X_clear_protection(VisaHandle* handle, uint32_t channel) {
    //Function not supported by device
    return;

}
bool SPS5000X_get_protection(VisaHandle* handle, uint32_t channel) {
    //Function not supported by device
    return false;
}

void SPS5000X_set_output(VisaHandle* handle, uint32_t channel, bool value) {
    const char *channel_text[4] = { "CH1","CH2","CH3" };
    //Exit function if the channel is invalid for the device
    if (channel > 3 || channel < 0) {
        return;
    }

    if (value == true) {
        viPrintf(handle->session, "OUTPut %s,ON\n", channel_text[channel]);
    }
    else {
        viPrintf(handle->session, "OUTPut %s,OFF\n", channel_text[channel]);
    }
}

const struct fnc_power_supply SPS5000X_pointer = {
        .fnc_set_current = SPS5000X_set_current,
        .fnc_get_current = SPS5000X_get_current,
        .fnc_get_current_min = SPS5000X_get_current_min,
        .fnc_get_current_max = SPS5000X_get_current_max,

        .fnc_set_voltage = SPS5000X_set_voltage,
        .fnc_get_voltage = SPS5000X_get_voltage,
        .fnc_get_voltage_min = SPS5000X_get_voltage_min,
        .fnc_get_voltage_max = SPS5000X_get_voltage_max,

        .fnc_set_ocp = SPS5000X_set_ocp,
        .fnc_get_ocp = SPS5000X_get_ocp,
        .fnc_get_ocp_min = SPS5000X_get_ocp_min,
        .fnc_get_ocp_max = SPS5000X_get_ocp_max,

        .fnc_set_ovp = SPS5000X_set_ovp,
        .fnc_get_ovp = SPS5000X_get_ovp,
        .fnc_get_ovp_min = SPS5000X_get_ovp_min,
        .fnc_get_ovp_max = SPS5000X_get_ovp_max,

        .fnc_clear_protection = SPS5000X_clear_protection,
        .fnc_get_protection = SPS5000X_get_protection,

        .fnc_set_output = SPS5000X_set_output,

        .fnc_init = SPS5000X_init,
        .fnc_deinit = SPS5000X_deinit

};
