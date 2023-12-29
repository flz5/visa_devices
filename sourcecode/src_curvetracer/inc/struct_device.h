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

#ifndef CURVETRACER_STRUCT_DEVICE_H
#define CURVETRACER_STRUCT_DEVICE_H

#include "system/VisaSession.h"
#include <string>
#include <cinttypes>


typedef enum{
    TYPE_MULTIMETER = 0,
    TYPE_POWERSUPPLY = 1,
    TYPE_OSCILLOSCOPE = 2,
    TYPE_SIGNALGENERATOR = 3,
    TYPE_ELECTRONIC_LOAD = 4

} device_type;


typedef struct {
    //ID of the device (driver)
	uint32_t device_id;
    //type of the device
    device_type type_id;
    //visa address
	std::string address;
    //visa handle
	VisaHandle *handle;

} device_t;

#endif