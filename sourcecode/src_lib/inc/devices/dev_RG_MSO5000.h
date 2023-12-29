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

#ifndef _DEV_RG_MSO5000_H
#define _DEV_RG_MSO5000_H

#include "generic/generic_oscilloscope.h"
#include <inttypes.h>

/*
This device driver can be used for multiple devices. The following oscilloscoped are supported:
 MSO5072
 MSO5074
 MSO5102
 MSO5104
 MSO5507
 MSO5354

 Revision of the devices are mentioned here as there should be no difference for the interface. 
The features itself may be different.

Info: 
	Not all possible features are implemented at the moment.

Limitations:
	
	
*/

#ifdef __cplusplus
extern "C" {
#endif

typedef enum{
	MSO5000_ENC_ASCII = 0,	//ASCII representation of signed integer
	MSO5000_ENC_WORD = 1, //signed integer (MSB first)
	MSO5000_ENC_BYTE = 2, //unsigned integer (MSB first)
} mso5000_encoding;

EXPORT void mso5000_init(VisaHandle* handle);
EXPORT void mso5000_deinit(VisaHandle* handle);

EXPORT void mso5000_save_waveform(VisaHandle* handle, uint32_t channel, char* filename);
EXPORT void mso5000_get_waveform(VisaHandle* handle, uint32_t channel, double* data, uint32_t size);
EXPORT void mso5000_set_hdiv(VisaHandle* handle, uint32_t channel, double value);
EXPORT void mso5000_set_vdiv(VisaHandle* handle, uint32_t channel, double value);
EXPORT void mso5000_set_trigger_mode(VisaHandle* handle, oscilloscope_trigger_mode mode);
EXPORT void mso5000_set_trigger_coupling(VisaHandle* handle, oscilloscope_trigger_coupling mode);
EXPORT void mso5000_set_trigger_level(VisaHandle* handle, double value);
EXPORT void mso5000_set_trigger_slope(VisaHandle* handle, oscilloscope_trigger_slope slope);
EXPORT void mso5000_set_trigger_source(VisaHandle* handle, oscilloscope_trigger_source source);

EXPORT void mso5000_force_trigger(VisaHandle* handle);

EXPORT void mso5000_set_waveform_source(VisaHandle* handle, uint32_t channel);
EXPORT void mso5000_set_waveform_format(VisaHandle* handle, mso5000_encoding value);
//Sets the first value in the transfered waveform (minimum is 1)
EXPORT void mso5000_set_waveform_start(VisaHandle* handle, uint32_t start);
//Sets the last value in the transfered waveform (has to be higher than start)
EXPORT void mso5000_set_waveform_stop(VisaHandle* handle, uint32_t stop);

extern const struct fnc_oscilloscope mso5000_oscilloscope_pointer;
extern const struct fnc_signal_generator mso5000_generator_pointer;

#ifdef __cplusplus
}
#endif

#endif