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

#ifdef OS_WIN
#include <windows.h>
#endif

#if defined(OS_LINUX) || defined(OS_MAC)
#include <time.h>
#include <errno.h>
#endif

//Sleep for the requested number of milliseconds.
void sys_sleep(int time){

    #ifdef OS_WIN
    Sleep(time);
    #endif

    #if defined(OS_LINUX) || defined(OS_MAC)

    struct timespec ts;
    int res;

    if (time < 0)
    {
        errno = EINVAL;
        return;
    }

    ts.tv_sec = time / 1000;
    ts.tv_nsec = (time % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    #endif

}