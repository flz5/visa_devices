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

#ifndef _GENERIC_OSCILLOSCOPE_H
#define _GENERIC_OSCILLOSCOPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "system/VisaSession.h"
#include <inttypes.h>

typedef enum {
	Rising = 0,
	Falling = 1
} oscilloscope_trigger_slope;

typedef enum  {
	Auto = 0,
	Normal = 1,
	Single = 2
} oscilloscope_trigger_mode;

typedef enum {
	AC = 0,
	DC = 1,
	HFReject = 2,	//High frequency reject mode
	LFReject = 3,	//Low frequency reject mode
	NoiseReject = 4
} oscilloscope_trigger_coupling;

typedef enum {
	CH1 = 0,
	CH2 = 1,
	CH3 = 2,
	CH4 = 3,
	AUX = 4,
	Line = 5
} oscilloscope_trigger_source;

typedef enum {
	R50 = 0,	//50 Ohm
	R75 = 1,	//75 Ohm
	R1M = 2		//1 MOhm
} oscilloscope_channel_impedance;

typedef enum {
	COUPLING_DC = 0,
	COUPLING_AC = 1,
	COUPLING_GND = 2
} oscilloscope_channel_coupling;

typedef enum {
    PLOT_YT = 0,    //Y-t Modus
    PLOT_XY = 1,    //X-Y Modus
    PLOT_ROLL = 2   //Rollend
} oscilloscope_plot_mode;

/**
 *
 */
EXPORT void oscilloscope_init(VisaHandle* handle);

/**
 *
 */
EXPORT void oscilloscope_deinit(VisaHandle* handle);


/**
 *
 */
EXPORT void oscilloscope_save_waveform(VisaHandle* handle, uint32_t channel, char *filename);

/**
 *
 */
EXPORT void oscilloscope_get_waveform(VisaHandle* handle, uint32_t channel, double *data, uint32_t size);

/**
 *
 */
EXPORT void oscilloscope_set_hdiv(VisaHandle* handle, uint32_t channel, double value);

/**
 *
 */
EXPORT void oscilloscope_set_vdiv(VisaHandle* handle, uint32_t channel, double value);

/**
 *
 */
EXPORT void oscilloscope_set_trigger_mode(VisaHandle* handle,oscilloscope_trigger_mode mode);

/**
 *
 */
EXPORT void oscilloscope_set_trigger_coupling(VisaHandle* handle,oscilloscope_trigger_coupling mode);

/**
 *
 */
EXPORT void oscilloscope_set_trigger_level(VisaHandle* handle, double value);

/**
 *
 */
EXPORT void oscilloscope_set_trigger_source(VisaHandle* handle, oscilloscope_trigger_source source);

/**
 *
 */
EXPORT void oscilloscope_set_trigger_slope(VisaHandle* handle, oscilloscope_trigger_slope slope);

/**
 *
 */
EXPORT void oscilloscope_force_trigger(VisaHandle* handle);

#ifdef __cplusplus
}
#endif

#endif