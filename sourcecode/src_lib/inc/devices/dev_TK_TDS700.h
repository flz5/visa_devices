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

#ifndef _DEV_TK_TDS700_H
#define _DEV_TK_TDS700_H

#include "system/VisaSession.h"
#include "generic/generic_oscilloscope.h"
#include <inttypes.h>
#include <inttypes.h>

/*
This device driver can be used for multiple devices. The following oscilloscoped are supported:
	TDS420
	TDS430
	TDS460
	TDS510
	TDS520
	TDS540
	TDS620
	TDS644
	TDS680
	TDS684
	TDS724
	TDS754
	TDS784

Revision of the devices are mentioned here as there should be no difference for the interface. 
The features itself may be different.

Info: 
	Not all possible features are implemented at the moment.

Limitations:
	The function tds700_get_waveform always sets the transfer parameters.

*/

typedef enum{
	TDS700_ENC_ASCII = 0,	//ASCII representation of signed integer
	TDS700_ENC_RIBinary = 1, //signed integer (MSB first)
	TDS700_ENC_RPBinary = 2, //unsigned integer (MSB first)
	TDS700_ENC_SRIbinary = 3, //signed integer (LSB first)
	TDS700_ENC_SRPbinary = 4 //unsigned integer (LSB first)

} tds700_encoding;

extern const struct fnc_oscilloscope tds700_pointer;

EXPORT void tds700_init(VisaHandle* handle);
EXPORT void tds700_deinit(VisaHandle* handle);

EXPORT void tds700_save_waveform(VisaHandle* handle, uint32_t channel, char* filename);
EXPORT void tds700_get_waveform(VisaHandle* handle, uint32_t channel, double* data, uint32_t size);

EXPORT void tds700_set_hdiv(VisaHandle* handle, uint32_t channel, double value);
EXPORT void tds700_set_vdiv(VisaHandle* handle, uint32_t channel, double value);

EXPORT void tds700_set_trigger_mode(VisaHandle* handle, oscilloscope_trigger_mode mode);
EXPORT void tds700_set_trigger_coupling(VisaHandle* handle, oscilloscope_trigger_coupling mode);
EXPORT void tds700_set_trigger_level(VisaHandle* handle, double value);
EXPORT void tds700_set_trigger_slope(VisaHandle* handle, oscilloscope_trigger_slope slope);
EXPORT void tds700_set_trigger_source(VisaHandle* handle, oscilloscope_trigger_source source);

EXPORT void tds700_force_trigger(VisaHandle* handle);

//Device specific funktions (not avaiable in the generic interface)

//Sets the source of the transfered data
EXPORT void tds700_set_data_source(VisaHandle* handle, uint32_t channel);
//Sets the format in which waveform data is transfered
EXPORT void tds700_set_data_encoding(VisaHandle* handle, tds700_encoding encoding);
//Sets the size of the transfered values in bytes (1 oder 2 byte possible)
EXPORT void tds700_set_data_width(VisaHandle* handle, uint32_t width);
//Sets the first value in the transfered waveform (minimum is 1)
EXPORT void tds700_set_data_start(VisaHandle* handle, uint32_t start);
//Sets the last value in the transfered waveform (has to be higher than start)
EXPORT void tds700_set_data_stop(VisaHandle* handle, uint32_t stop);
//Beeps the audio indicator
EXPORT void tds700_bell(VisaHandle* handle);
//Sets the channel coupling
EXPORT void tds700_set_channel_coupling(VisaHandle* handle,uint32_t channel, oscilloscope_channel_coupling coupling);
//Sets the input impedance of the channel
EXPORT void tds700_set_channel_impedance(VisaHandle* handle,uint32_t channel, oscilloscope_channel_impedance impedance);
//Sets the channel offset (substracted before aquisistion)
EXPORT void tds700_set_channel_offset(VisaHandle* handle,uint32_t channel, double value);
//Sets the channel position (on screen)
EXPORT void tds700_set_channel_position(VisaHandle* handle, uint32_t channel, double value);
//Sets the record length (maximum different between models and options)
EXPORT void tds700_set_horizontal_lenght(VisaHandle* handle, unsigned long value);

#endif