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

#ifndef CURVETRACER_UI_DEVICE_H
#define CURVETRACER_UI_DEVICE_H
 
#include <vector>

#include "struct_device.h"


/**
 * Displays the display to add a new device
 * @return Device to add
 */
device_t ui_device_add();

/**
 * Shows a list of devices
 * @param list List of devices
 */
void ui_device_list(std::vector<device_t> data);

/**
 * Shows user interface to delete an device from the given list
 * @param list List to modify
 */
void ui_device_remove(std::vector<device_t>& data);

#endif