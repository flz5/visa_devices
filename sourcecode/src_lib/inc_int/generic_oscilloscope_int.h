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

#ifndef _GENERIC_OSCILLOSCOPE_INT_H
#define _GENERIC_OSCILLOSCOPE_INT_H

#include "system/VisaSession.h"
#include "generic/generic_oscilloscope.h"
#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

//System
typedef void (*fncptr_oscilloscope_init)(VisaHandle* handle);

typedef void (*fncptr_oscilloscope_save_waveform)(VisaHandle* handle, uint32_t channel,char* filename);
typedef void (*fncptr_oscilloscope_get_waveform)(VisaHandle* handle, uint32_t channel, double* data, uint32_t size);

typedef void (*fncptr_oscilloscope_set_hdiv)(VisaHandle* handle, uint32_t channel, double value);
typedef void (*fncptr_oscilloscope_set_vdiv)(VisaHandle* handle, uint32_t channel, double value);

typedef void (*fncptr_oscilloscope_set_trigger_mode)(VisaHandle* handle, oscilloscope_trigger_mode mode);
typedef void (*fncptr_oscilloscope_set_trigger_level)(VisaHandle* handle, double value);
typedef void (*fncptr_oscilloscope_set_trigger_coupling)(VisaHandle* handle, oscilloscope_trigger_coupling mode);
typedef void (*fncptr_oscilloscope_set_trigger_source)(VisaHandle* handle, oscilloscope_trigger_source source);
typedef void (*fncptr_oscilloscope_set_trigger_slope)(VisaHandle* handle, oscilloscope_trigger_slope slope);

typedef void (*fncptr_oscilloscope_force_trigger)(VisaHandle* handle);

struct fnc_oscilloscope {
	fncptr_oscilloscope_init fnc_init;
	fncptr_oscilloscope_init fnc_deinit;

	fncptr_oscilloscope_save_waveform fnc_save_waveform;
	fncptr_oscilloscope_get_waveform fnc_get_waveform;

	fncptr_oscilloscope_set_hdiv fnc_set_hdiv;
	fncptr_oscilloscope_set_vdiv fnc_set_vdiv;

	fncptr_oscilloscope_set_trigger_mode fnc_set_trigger_mode;
	fncptr_oscilloscope_set_trigger_level fnc_set_trigger_level;
	fncptr_oscilloscope_set_trigger_coupling fnc_set_trigger_coupling;
	fncptr_oscilloscope_set_trigger_source fnc_set_trigger_source;
	fncptr_oscilloscope_set_trigger_slope fnc_set_trigger_slope;

	fncptr_oscilloscope_force_trigger fnc_force_trigger;

};

#ifdef __cplusplus
}
#endif

#endif