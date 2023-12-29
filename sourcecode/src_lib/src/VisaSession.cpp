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

EXPORT VisaSession* visa_session_open() {
	ViSession* session = new ViSession;
    VisaSession* vs = new VisaSession;
	ViStatus  status;

	status = viOpenDefaultRM(session);
	if (status < VI_SUCCESS) {
        vs->resource_manager = *session;
        vs->isOpen = true;
	}
	else {
        vs->resource_manager = 0;
        vs->isOpen = false;
	}

	return vs;
}

EXPORT bool visa_session_is_ok(VisaSession* session) {
	return session->isOpen;
}

EXPORT void visa_session_close(VisaSession* session) {
    viClose(session->resource_manager);
    session->isOpen = false;
}

EXPORT VisaHandle* visa_device_connect(VisaSession* session, char* resource_string, unsigned int access_mode, unsigned int timeout_ms) {
	VisaHandle* handle = new VisaHandle;

	viOpen(session->resource_manager, resource_string, access_mode, timeout_ms, &(handle)->session);

	(handle)->state = VisaDeviceState_OK;
	return handle;

}
EXPORT void visa_device_close(VisaHandle* handle) {
	viClose(handle->session);
	delete handle;
}

EXPORT void visa_device_reset(VisaHandle* handle) {
	viPrintf(handle->session, "*RST\n");
}

EXPORT void visa_device_test(VisaHandle* handle) {
	viPrintf(handle->session, "*TST?\n");
	//Sleep(100);
}

EXPORT void visa_device_set_driver(VisaHandle* handle, int id){
    handle->device_id = id & 0xFFFF;
    handle->driver_id = ((id >> 16) & 0xFFFF) ;
}

EXPORT int visa_device_get_driver(VisaHandle* handle) {
    return handle->device_id;
}
