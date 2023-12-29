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

#ifdef DLL_EXPORT
    #define _USE_VI
    #ifdef OS_WIN
        #define EXPORT extern "C" __declspec(dllexport)
    #else
        #define EXPORT extern "C" __attribute__((visibility("default")))
    #endif
#else
    #ifdef OS_WIN
        #define EXPORT extern "C" __declspec(dllimport)
    #else
        #define EXPORT
    #endif
#endif


#ifndef _VISA_SESSION_H
#define _VISA_SESSION_H

#include "VisaDevice.h"
#ifdef _USE_VI
#include <visa.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif

#ifdef _USE_VI
	#include <visa.h>

	struct VisaSession {
		ViSession resource_manager;
        bool isOpen;
	};

	struct VisaHandle {
        //handle for session
		ViSession session;
        //state of session
		enum VisaDeviceState state;
        //Driver ID (driver selection)
		int driver_id;
        //Device ID (for driver)
		int device_id;
        //Pointer for memory storage of the driver
		void* device_storage;
	};
#else
	typedef struct VisaHandle VisaHandle;
	typedef struct VisaSession VisaSession;

#endif

	EXPORT VisaSession* visa_session_open();
	EXPORT bool visa_session_is_ok(VisaSession* session);
	EXPORT void visa_session_close(VisaSession* session);

	EXPORT VisaHandle* visa_device_connect(VisaSession* session, char* resource_string, unsigned int access_mode,
                                           unsigned int timeout_ms);
	EXPORT void visa_device_close(VisaHandle* handle);

	EXPORT void visa_device_reset(VisaHandle* handle);
	EXPORT void visa_device_test(VisaHandle* handle);

    EXPORT void visa_device_set_driver(VisaHandle* handle, int id);

#ifdef __cplusplus
}
#endif


#endif