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

// dllmain.cpp : Definiert den Einstiegspunkt für die DLL-Anwendung.

#include "system/VisaSession.h"
#include "system/VisaDevice.h"

#include "devices/dev_GW_PEL3000E.h"
#include "devices/dev_RS_ZVA50.h"
#include "devices/dev_KS_E8361A.h"
#include "devices/dev_KS_34401.h"
#include "devices/dev_KS_6612.h"
#include "devices/dev_SL_SPD3303X.h"

#ifdef OS_WIN

#define WIN32_LEAN_AND_MEAN
#include "stdbool.h"
#include <Windows.h>

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

#endif
