#
# This file is part of the VisaDevices library project.
# Copyright (c) 2019-2023 Frank Zimdars.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as
# published by the Free Software Foundation, version 3.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#

import ctypes


class Multimeter:
    def __init__(self, lib, handle):
        self._handle = handle
        self._lib = lib

        self._lib.multimeter_get_driver.restype = ctypes.c_int
        self._lib.multimeter_get_measurement.restype = ctypes.c_double

    def set_driver(self, driver_id):
        self._lib.multimeter_set_driver(ctypes.c_void_p(self._handle), ctypes.c_int(driver_id))

    def get_driver(self):
        return self._lib.multimeter_get_driver(ctypes.c_void_p(self._handle))

    def init(self) -> None:
        self._lib.multimeter_init(ctypes.c_void_p(self._handle))

    def deinit(self) -> None:
        self._lib.multimeter_deinit(ctypes.c_void_p(self._handle))

    def set_mode(self, channel, mode):
        self._lib.multimeter_set_mode(ctypes.c_void_p(self._handle), ctypes.c_int(channel), ctypes.c_int(mode))

    def get_measurement(self, channel):
        self._lib.multimeter_get_measurement(ctypes.c_void_p(self._handle), ctypes.c_int(channel))
