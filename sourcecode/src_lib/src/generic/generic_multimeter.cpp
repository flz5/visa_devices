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
#include "generic/generic_multimeter.h"
#include "generic_multimeter_int.h"
#include "devices/dev_NN_MMDummy.h"
#include "devices/dev_KS_34401.h"

const struct fnc_multimeter multimeter_implementation[2] = {MMDummy_pointer,ks34401_pointer};

EXPORT void multimeter_init(VisaHandle* handle) {
	multimeter_implementation[handle->driver_id].fnc_init(handle);
}

EXPORT void multimeter_deinit(VisaHandle* handle) {
	multimeter_implementation[handle->driver_id].fnc_deinit(handle);
}

EXPORT void multimeter_set_mode(VisaHandle* handle, uint32_t channel, multimeter_mode mode) {
	multimeter_implementation[handle->driver_id].fnc_init(handle);
}

EXPORT double multimeter_get_measurement(VisaHandle* handle, uint32_t channel) {
	return multimeter_implementation[handle->driver_id].fnc_get_measurement(handle, channel);
}