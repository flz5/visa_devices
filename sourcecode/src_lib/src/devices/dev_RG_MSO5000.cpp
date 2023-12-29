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
#include "devices/dev_RG_MSO5000.h"
#include "generic_oscilloscope_int.h"
#include "generic_signal_generator_int.h"

#include <cstdint>
#include <cstring>
#include <iostream>

static const char names_channel[][9] = { "CHANnel1","CHANnel2","CHANnel3","CHANnel4"};

EXPORT void mso5000_init(VisaHandle* handle) {
	//TODO: Implementation
}

EXPORT void mso5000_deinit(VisaHandle* handle) {
	//TODO: Implementation
}

EXPORT void mso5000_save_waveform(VisaHandle* handle, uint32_t channel, char* filename) {
	//TODO: Implementation
}

EXPORT void mso5000_get_waveform(VisaHandle* handle, uint32_t channel, double* data, uint32_t size) {

    ViChar *buffer = new ViChar[100];
    ViUInt32  retCount = 0 ;
    char text[100];

    viPrintf(handle->session, "WAV:SOUR %s\n", names_channel[channel]);
    viPrintf(handle->session, "WAV:MODE NORMal\n");
    viPrintf(handle->session, "WAVeform:FORMat BYTE\n");
    viPrintf(handle->session, "WAV:DATA?\n");

    viRead(handle->session, (ViBuf)buffer, 1, &retCount);
    viRead(handle->session, (ViBuf)buffer, 1, &retCount);
    viRead(handle->session, (ViBuf)buffer, buffer[0], &retCount);

    int ss = std::atoi(buffer);
    ViChar *buffer_data = new ViChar[ss];
    viRead(handle->session, (ViBuf)buffer, ss, &retCount);


    viPrintf(handle->session, "WAVeform:YORigin?\n");
    viScanf(handle->session, "%s", text);
    double reference = std::atof(text);


    viPrintf(handle->session, "WAVeform:YINCrement?\n");
    viScanf(handle->session, "%s", text);
    double y_inc = std::atof(text);


    int copy_size = 0;
    //Den kleineren Wert zur Begrenzung der Kopie nutzen
    if(size > ss){
        copy_size = ss;
    }else{
        copy_size = size;
    }

    for(int i = 0;i<size;i++){
        data[i] = (buffer[i] - reference) * y_inc;
    }

    delete[] buffer;
    delete[] buffer_data;

}

EXPORT void mso5000_set_hdiv(VisaHandle* handle, uint32_t channel, double value) {
	viPrintf(handle->session, "TIMebase:MAIN:SCALe %f\n",value);
}

EXPORT void mso5000_set_vdiv(VisaHandle* handle, uint32_t channel, double value) {
	viPrintf(handle->session, "%s:SCAle %f\n", names_channel[channel], value);
}

EXPORT void mso5000_set_trigger_mode(VisaHandle* handle, oscilloscope_trigger_mode mode) {
	switch (mode) {
		case Auto:
		{
			viPrintf(handle->session, "TRIGger:SWEep AUTO\n");
		}break;
		case Normal: {
			viPrintf(handle->session, "TRIGger:SWEep NORMal\n");
		}break;
		case Single: {
			viPrintf(handle->session, "TRIGger:SWEep SINGle\n");
		}break;
	}
}

EXPORT void mso5000_set_trigger_coupling(VisaHandle* handle, oscilloscope_trigger_coupling mode) {
	switch (mode) {
		case AC: {
			viPrintf(handle->session, "TRIGger:COUPling AC\n");
		}break;
		case DC: {
			viPrintf(handle->session, "TRIGger:COUPling AC\n");
		}break;
		case HFReject: {
			viPrintf(handle->session, "TRIGger:COUPling HFReject\n");
		}break;
		case LFReject: {
			viPrintf(handle->session, "TRIGger:COUPling LFReject\n");
		}break;
		case NoiseReject: {
			//Have to be enabled by:
			//TRIGger:NREJect
			//stays on until disabled
			//avaiable for all coupling modes
		}break;
	}
}

EXPORT void mso5000_set_trigger_level(VisaHandle* handle, double value) {
	viPrintf(handle->session, "TRIGger:EDGE:LEVel %f\n",value);
}

EXPORT void mso5000_set_trigger_slope(VisaHandle* handle, oscilloscope_trigger_slope slope) {
	switch(slope){
		case Rising:
		{
			viPrintf(handle->session, "TRIGger:EDGE:SLOpe POSitive\n");	
		}break;
		case Falling:
		{
			viPrintf(handle->session, "TRIGger:EDGE:SLOpe NEGative\n");
		}break;
	}
}

EXPORT void mso5000_set_trigger_source(VisaHandle* handle, oscilloscope_trigger_source source) {
	switch(source){
		case CH1:{
			viPrintf(handle->session, "TRIGger:EDGE:SOUrce CHANnel1\n");
		}break;
		case CH2:{
			viPrintf(handle->session, "TRIGger:EDGE:SOUrce CHANnel2\n");
		}break;
		case CH3:{
			viPrintf(handle->session, "TRIGger:EDGE:SOUrce CHANnel3\n");
		}break;
		case CH4:{
			viPrintf(handle->session, "TRIGger:EDGE:SOUrce CHANnel4\n");
		}break;
		case AUX:{
			//not supported by device
		}break;
		case Line:{
			viPrintf(handle->session, "TRIGger:EDGE:SOUrce ACLINE\n");
		}break;
	}
}

EXPORT void mso5000_force_trigger(VisaHandle* handle) {
	viPrintf(handle->session, "TFORCe\n");
}

//Sets the channel position (on screen)
EXPORT void mso5000_set_channel_position(VisaHandle* handle,uint32_t channel, double value){
	viPrintf(handle->session, "%s:POSition %f\n",names_channel[channel],value);
}

EXPORT void mso5000_set_waveform_source(VisaHandle* handle, uint32_t channel){
	viPrintf(handle->session, "WAVeform:SOUrce %s\n",names_channel[channel]);
}

EXPORT void mso5000_set_waveform_format(VisaHandle* handle, mso5000_encoding value){
	switch(value){
		case MSO5000_ENC_BYTE:{
			viPrintf(handle->session, "WAVeform:FORMat BYTE\n");
		}break;
		case MSO5000_ENC_WORD:{
			viPrintf(handle->session, "WAVeform:FORMat WORD\n");	
		}break;
		case MSO5000_ENC_ASCII:{
			viPrintf(handle->session, "WAVeform:FORMat ASCII\n");
		}break;
	}
}

EXPORT void mso5000_set_waveform_start(VisaHandle* handle, uint32_t start){
	viPrintf(handle->session, "WAVeform:STARt %i\n",start);
}

//Sets the last value in the transfered waveform (has to be higher than start)
EXPORT void mso5000_set_waveform_stop(VisaHandle* handle, uint32_t stop){
	viPrintf(handle->session, "WAVeform:STOP %i\n",stop);
}


void mso5000_set_lock(VisaHandle* handle, bool state){

    if(state){
        viPrintf(handle->session, "SYSTem:LOCKed ON\n");
    }else{
        viPrintf(handle->session, "SYSTem:LOCKed OFF\n");

    }

}













const struct fnc_oscilloscope mso5000_oscilloscope_pointer = {
	.fnc_init = mso5000_init,
	.fnc_deinit = mso5000_deinit,

	.fnc_save_waveform = mso5000_save_waveform,
	.fnc_get_waveform = mso5000_get_waveform,

	.fnc_set_hdiv = mso5000_set_hdiv,
	.fnc_set_vdiv = mso5000_set_vdiv,

	.fnc_set_trigger_mode = mso5000_set_trigger_mode,
	.fnc_set_trigger_level = mso5000_set_trigger_level,
	.fnc_set_trigger_coupling = mso5000_set_trigger_coupling,
	.fnc_set_trigger_source = mso5000_set_trigger_source,
	.fnc_set_trigger_slope = mso5000_set_trigger_slope,

	.fnc_force_trigger = mso5000_force_trigger
};

const struct fnc_signal_generator mso5000_generator_pointer = {
        .fnc_set_waveform_type = nullptr,
        .fnc_set_waveform_data = nullptr,
        .fnc_set_amplitude = nullptr,
        .fnc_set_offset = nullptr,
        .fnc_set_frequency = nullptr,
        .fnc_set_level = nullptr,
        .fnc_set_output = nullptr,
        .fnc_init = nullptr,
        .fnc_deinit = nullptr

};