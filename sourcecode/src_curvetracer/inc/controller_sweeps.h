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

#ifndef CURVETRACER_CONTROLLER_STEPS_H
#define CURVETRACER_CONTROLLER_STEPS_H

#include "controller.h"
#include "generic/generic_power_supply.h"
#include "generic/generic_electronic_load.h"

#include <vector>

/**
 * Sets the value on a device
 * @param device device to set
 * @param channel Channel at the device
 * @param value Value to set
 * @param mode Select what will be set
 */
void controller_set_step(const device_t& device, int channel, double value, char mode);

/**
 * Sets the value on a power supply
 * @param handle handle for device to set
 * @param channel Channel at the device
 * @param value Value to set
 * @param mode Select what will be set
 */
void controller_step_supply(VisaHandle* handle, int channel, double value, char mode);

/**
 * Sets the value on a electronic load
 * @param handle handle for device to set
 * @param channel Channel at the device
 * @param value Value to set
 * @param mode Select what will be set
 */
void controller_step_electronic_load(VisaHandle* handle, int channel, double value, char mode);

#endif