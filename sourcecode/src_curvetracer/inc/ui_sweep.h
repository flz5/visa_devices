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

#ifndef CURVETRACER_UI_SWEEP_H
#define CURVETRACER_UI_SWEEP_H

#include <vector>
#include "sweep.h"

/**
 * Displays the interface to add a new sweep
 * @return sweep to add
 */
Sweep ui_sweep_add();

/**
 * Shows a list of sweeps
 * @param list List of sweeps
 */
void ui_sweep_list(std::vector<Sweep> list);

/**
 * Shows user interface to delete a sweep from the given list
 * @param list List to modify
 */
void ui_sweep_remove(std::vector<Sweep>& list);

#endif