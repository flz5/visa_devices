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

#include "devices/dev_TK_TDS700.h"
#include "generic_oscilloscope_int.h"

static const char names_channel[][5] = { "CH1","CH2","CH3","CH4" };

EXPORT void tds700_init(VisaHandle* handle) {
	viSetBuf(handle->session, VI_READ_BUF, 200000 * 10);
}
EXPORT void tds700_deinit(VisaHandle* handle) {

}

EXPORT void tds700_save_waveform(VisaHandle* handle, uint32_t channel, char* filename) {
	//TODO: Implement here
}

EXPORT void tds700_get_waveform(VisaHandle* handle, uint32_t channel, double* data, uint32_t size) {
	
	int count_transfered = 0;
	
	tds700_set_data_source(handle,channel);
	tds700_set_data_start(handle,1);
	tds700_set_data_stop(handle,size);
	tds700_set_data_width(handle,1);
	tds700_set_data_encoding(handle, TDS700_ENC_RIBinary);

	viPrintf(handle->session, "CURVe?\n");
	//viRead(handle->session, data, size,&count_transfered);

}

EXPORT void tds700_set_hdiv(VisaHandle* handle, uint32_t channel, double value) {
	viPrintf(handle->session, "HORizontal_MAIn:SCAle %e\n", value);
}

EXPORT void tds700_set_vdiv(VisaHandle* handle, uint32_t channel, double value) {
	viPrintf(handle->session, "%s:SCAle %e\n", names_channel[channel], value);
}

EXPORT void tds700_set_trigger_mode(VisaHandle* handle, oscilloscope_trigger_mode mode) {

	switch (mode) {
	case Auto:
	{
		viPrintf(handle->session, "TRIGger:MAIn:MODe AUTO\triggern");
	}break;
	case Normal: {
		viPrintf(handle->session, "TRIGger:MAIn:MODe NORMal\n");
	}break;
	case Single: {
		//TODO: Implement here
	}break;
	}
}

EXPORT void tds700_set_trigger_coupling(VisaHandle* handle, oscilloscope_trigger_coupling mode) {
	switch (mode) {
		case AC: {
			viPrintf(handle->session, "TRIGger:MAIn:EDGE:COUPling AC\n");
		}break;
		case DC: {
			viPrintf(handle->session, "TRIGger:MAIn:EDGE:COUPling AC\n");
		}break;
		case HFReject: {
			viPrintf(handle->session, "TRIGger:MAIn:EDGE:COUPling HFRej\n");
		}break;
		case LFReject: {
			viPrintf(handle->session, "TRIGger:MAIn:EDGE:COUPling LFRej\n");
		}break;
		case NoiseReject: {
			viPrintf(handle->session, "TRIGger:MAIn:EDGE:COUPling NOISErej\n");
		}break;
	}
}

EXPORT void tds700_set_trigger_level(VisaHandle* handle, double value) {
	viPrintf(handle->session, "TRIGger:MAIn:LEVel %d\n",value);
}

EXPORT void tds700_set_trigger_slope(VisaHandle* handle, oscilloscope_trigger_slope slope) {
	switch(slope){
		case Rising:
		{
			viPrintf(handle->session, "TRIGger:MAIn:EDGE:SLOpe RISe\n");	
		}break;
		case Falling:
		{
			viPrintf(handle->session, "TRIGger:MAIn:EDGE:SLOpe FALL\n");
		}break;
	}
}

EXPORT void tds700_set_trigger_source(VisaHandle* handle, oscilloscope_trigger_source source) {
	switch(source){
		case CH1:{
			viPrintf(handle->session, "TRIGger:MAIn:EDGE:SOUrce CH1\n");
		}break;
		case CH2:{
			viPrintf(handle->session, "TRIGger:MAIn:EDGE:SOUrce CH2\n");
		}break;
		case CH3:{
			viPrintf(handle->session, "TRIGger:MAIn:EDGE:SOUrce CH3\n");
		}break;
		case CH4:{
			viPrintf(handle->session, "TRIGger:MAIn:EDGE:SOUrce CH4\n");
		}break;
		case AUX:{
			viPrintf(handle->session, "TRIGger:MAIn:EDGE:SOUrce AUXiliary\n");
		}break;
		case Line:{
			viPrintf(handle->session, "TRIGger:MAIn:EDGE:SOUrce LINE\n");
		}break;
	}
}

EXPORT void tds700_force_trigger(VisaHandle* handle) {
	viPrintf(handle->session, "TRIGer FORCe\n");
}

//device specific functions

EXPORT void tds700_bell(VisaHandle* handle){
	viPrintf(handle->session, "BELl\n");
}

//Sets the format in which waveform data is transfered
EXPORT void tds700_set_data_encoding(VisaHandle* handle, tds700_encoding encoding){
	switch(encoding){
		case TDS700_ENC_ASCII:{
			viPrintf(handle->session, "DATa:ENCdg ASCII\n");
		}break;
		case TDS700_ENC_RIBinary:{
			viPrintf(handle->session, "DATa:ENCdg RIBinary\n");	
		}break;
		case TDS700_ENC_RPBinary:{
			viPrintf(handle->session, "DATa:ENCdg RPBinary\n");
		}break;
		case TDS700_ENC_SRIbinary:{
			viPrintf(handle->session, "DATa:ENCdg SRIbinary\n");
		}break;
		case TDS700_ENC_SRPbinary:{
			viPrintf(handle->session, "DATa:ENCdg SRPbinary\n");
		}break;
	}
}

EXPORT void tds700_set_data_source(VisaHandle* handle, uint32_t channel){
	switch(channel){
		case 1:{
			viPrintf(handle->session, "DATa:SOUrce CH1\n");
		}break;
		case 2:{
			viPrintf(handle->session, "DATa:SOUrce CH2\n");	
		}break;
		case 3:{
			viPrintf(handle->session, "DATa:SOUrce CH3\n");
		}break;
		case 4:{
			viPrintf(handle->session, "DATa:SOUrce CH4\n");
		}break;
	}
}

//Sets the size of the transfered values in bytes (1 oder 2 byte possible)
EXPORT void tds700_set_data_width(VisaHandle* handle, uint32_t width){
	viPrintf(handle->session, "DATa:WIDth %i\n",width);
}

//Sets the first value in the transfered waveform (minimum is 1)
EXPORT void tds700_set_data_start(VisaHandle* handle, uint32_t start){
	viPrintf(handle->session, "DATa:STARt %i\n",start);
}

//Sets the last value in the transfered waveform (has to be higher than start)
EXPORT void tds700_set_data_stop(VisaHandle* handle, uint32_t stop){
	viPrintf(handle->session, "DATa:STOp %i\n",stop);
}

//Sets the channel coupling
EXPORT void tds700_set_channel_coupling(VisaHandle* handle,uint32_t channel, oscilloscope_channel_coupling coupling){

	switch(coupling){
		case COUPLING_AC:{
			viPrintf(handle->session, "%s:COUPLING AC\n",names_channel[channel]);
		}break;
		case COUPLING_DC:{
			viPrintf(handle->session, "%s:COUPLING DC\n",names_channel[channel]);
		}break;
		case COUPLING_GND:{
			viPrintf(handle->session, "%s:COUPLING GND\n",names_channel[channel]);
		}break;
	}
}

//Sets the input impedance of the channel
EXPORT void tds700_set_channel_impedance(VisaHandle* handle,uint32_t channel, oscilloscope_channel_impedance impedance){
	switch(impedance){
		case R50:{
			viPrintf(handle->session, "%s:IMPedance FIFty\n",names_channel[channel]);
		}break;
		case R1M:{
			viPrintf(handle->session, "%s:IMPedance MEG\n",names_channel[channel]);
		}break;
	}
}

//Sets the channel offset (substracted before aquisistion)
EXPORT void tds700_set_channel_offset(VisaHandle* handle,uint32_t channel, double value){
viPrintf(handle->session, "%s:OFFSet %e\n",names_channel[channel],value);
}

//Sets the channel position (on screen)
EXPORT void tds700_set_channel_position(VisaHandle* handle,uint32_t channel, double value){
	viPrintf(handle->session, "%s:POSition %e\n",names_channel[channel],value);
}

//Sets the record length (maximum different between models and options)
EXPORT void tds700_set_horizontal_lenght(VisaHandle* handle, unsigned long value){
	viPrintf(handle->session, "HORIZONTAL:RECORDLENGTH %i\n", value);
}

const struct fnc_oscilloscope tds700_pointer = {
	.fnc_init = tds700_init,
	.fnc_deinit = tds700_deinit,

	.fnc_save_waveform = tds700_save_waveform,
	.fnc_get_waveform = tds700_get_waveform,

	.fnc_set_hdiv = tds700_set_hdiv,
	.fnc_set_vdiv = tds700_set_vdiv,

	.fnc_set_trigger_mode = tds700_set_trigger_mode,
	.fnc_set_trigger_level = tds700_set_trigger_level,
	.fnc_set_trigger_coupling = tds700_set_trigger_coupling,
	.fnc_set_trigger_source = tds700_set_trigger_source,
	.fnc_set_trigger_slope = tds700_set_trigger_slope,

	.fnc_force_trigger = tds700_force_trigger
};