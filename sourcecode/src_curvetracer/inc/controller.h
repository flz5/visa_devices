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

#ifndef CURVETRACER_CONTROLLER_H
#define CURVETRACER_CONTROLLER_H

#include <vector>

#include "struct_device.h"
#include "struct_measurement.h"
#include "sweep.h"
#include "measurement_array.h"
#include "system/VisaSession.h"

/**
 * Starts an automatic sweep and measurement cycle
 * @param session Visa Session
 * @param devices Vector of devices
 * @param measurement Vector os Measurements
 * @param step  Vector of sweeps
 * @param folder Path to a folder where the results will be stored
 */
void controller_start(VisaSession *session, std::vector<device_t> devices, std::vector<measurement_t> measurement,
                      std::vector<Sweep> step, const std::string& _folder);

/**
 * Checks if the data in the measurement vector is correct
 * @param devices Vector of devices
 * @param measurement Vector of measurements
 * @return true if no error was found
 */
bool controller_check_sweep(std::vector<device_t> &devices, std::vector<Sweep> &sweep);

/**
 * Checks if the data in the sweep vector is correct
 * @param devices Vector of devices
 * @param sweep Vector of sweeps (to check)
 * @return true if no error was found
 */
bool controller_check_measurements(std::vector<device_t> &devices, std::vector<measurement_t> &measurement);

#endif
