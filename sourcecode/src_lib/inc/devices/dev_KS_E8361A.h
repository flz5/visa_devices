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
#include <stdint.h>

EXPORT void kse8361_init(VisaHandle* handle);
EXPORT void kse8361_set_trigger_single(VisaHandle* handle);
EXPORT void kse8361_set_trigger_continous(VisaHandle* handle);
EXPORT void kse8361_trigger(VisaHandle* handle);

//Store touchstone via ZVA to specified filename
EXPORT void kse8361_store_touchstone(VisaHandle* handle, char* filename);

//Get Tocuhstone file über VISA and store locally
EXPORT void kse8361_get_touchstone(VisaHandle* handle, char* filename);