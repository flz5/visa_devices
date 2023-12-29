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

#ifndef _GENERIC_MULTIMETER_H
#define _GENERIC_MULTIMETER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "system/VisaSession.h"
#include <inttypes.h>

typedef enum {
	Multimeter_Mode_Voltage_DC = 1,
	Multimeter_Mode_Voltage_AC = 2,
	Multimeter_Mode_Current_DC = 3,
	Multimeter_Mode_Current_AC = 4,
	Multimeter_Mode_Resistance = 5,
	Multimeter_Mode_Frequency = 6,
	Multimeter_Mode_Period = 7,
	Multimeter_Mode_Continuity = 8,
	Multimeter_Mode_Diode = 9
} multimeter_mode;


/**
 * Starts the initialisation of the device.
 * @param handle Handle
 */
EXPORT void multimeter_init(VisaHandle* handle);

/**
 * Starts the de-initialisation of the device.
 * @param handle Handle
 */
EXPORT void multimeter_deinit(VisaHandle* handle);

/**
 * Sets the measuring mode of the device
 * @param handle Handle
 * @param channel Channel
 * @param Measuring mode (type multimeter_mode)
 */
EXPORT void multimeter_set_mode(VisaHandle* handle,uint32_t channel, multimeter_mode mode);

/**
 * Returns a measurement
 * @param handle Handle
 * @param channel Channel
 */
EXPORT double multimeter_get_measurement(VisaHandle* handle, uint32_t channel);

#ifdef __cplusplus
}
#endif

#endif
