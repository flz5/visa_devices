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

#ifndef CURVETRACER_UI_MEASUREMENT_H
#define CURVETRACER_UI_MEASUREMENT_H

#include <vector>
#include "struct_measurement.h"

/**
 * Displays the interface to add a new measurement
 * @return measurement to add
 */
measurement_t ui_measurement_add();

/**
 * Shows a list of measurements
 * @param data List of devices
 */
void ui_measurement_list(std::vector<measurement_t> data);

/**
 * Shows user interface to delete a measurement from the given list
 * @param data List to modify
 */
void ui_measurement_remove(std::vector<measurement_t>& data);

#endif
