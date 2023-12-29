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

#ifndef CURVETRACER_CONTROLLER_CONNECT_H
#define CURVETRACER_CONTROLLER_CONNECT_H

#include "system/VisaDevice.h"
#include "system/VisaSession.h"

#include <vector>
#include "struct_device.h"

/**
 * Connects all devices in the list to the visa session
 * @param session Visa session
 * @param list Vector of device_t
 * @return true when no error occurred
 */
bool controller_connect(VisaSession* session, std::vector<device_t> &list);

/**
 * Disconnect all devices in the list
 * @param list
 * @return
 */
bool controller_disconnect(std::vector<device_t>& list);

#endif
