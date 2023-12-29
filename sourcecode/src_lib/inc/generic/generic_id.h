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

#ifndef _GENERIC_ID_H
#define _GENERIC_ID_H

/*
	Device ids are unique in their categorie (e.g. power supplies)
	The 4 lower digits are the device id, the 4 upper ones the driver id

*/


#include "generic_electronic_load_id.h"
#include "generic_power_supply_id.h"
#include "generic_multimeter_id.h"
#include "generic_oscilloscope_id.h"
#include "generic_signal_generator_id.h"

#define DRIVER_NONE		0x00000000

#endif

