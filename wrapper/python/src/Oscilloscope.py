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


class Oscilloscope:
    def __init__(self,  lib, handle):
        self._handle = handle
        self._lib = lib

        self._lib.oscilloscope_get_driver.restype = ctypes.c_int

    def set_driver(self,driver_id) -> None:
        self._lib.oscilloscope_set_driver(ctypes.c_void_p(self._handle), ctypes.c_int(driver_id))

    def get_driver(self) -> int:
        return self._lib.oscilloscope_get_driver(ctypes.c_void_p(self._handle))

    def init(self) -> None:
        self._lib.oscilloscope_init(ctypes.c_void_p(self._handle))

    def deinit(self) -> None:
        self._lib.power_supply_deinit(ctypes.c_void_p(self._handle))

    def save_waveform(self,channel, filename) -> None:
        self._lib.oscilloscope_save_waveform(ctypes.c_void_p(self._handle), ctypes.c_int(channel),
                                           ctypes.c_char_p(filename))

    def get_waveform(self, channel, size):

        data = (ctypes.c_double * size)()
        self._lib.oscilloscope_get_waveform(ctypes.c_void_p(self._handle),
                                            ctypes.c_int(channel), data, ctypes.c_int(size))
        return data

    def set_hdiv(self, value) -> None:
        self._lib.oscilloscope_set_hdiv(ctypes.c_void_p(self._handle), ctypes.c_int(value))

    def set_vdiv(self, value) -> None:
        self._lib.oscilloscope_set_vdiv(ctypes.c_void_p(self._handle), ctypes.c_int(value))

    def set_trigger_mode(self,mode) -> None:
        self._lib.oscilloscope_set_trigger_mode(ctypes.c_void_p(self._handle), ctypes.c_int(mode))

    def set_trigger_coupling(self, mode) -> None:
        self._lib.oscilloscope_set_trigger_coupling(ctypes.c_void_p(self._handle), ctypes.c_int(mode))

    def set_trigger_coupling(self, mode) -> None:
        self._lib.power_supply_set_current(ctypes.c_void_p(self._handle), ctypes.c_int(mode))

    def set_trigger_level(self,level) -> None:
        self._lib.oscilloscope_set_trigger_level(ctypes.c_void_p(self._handle), ctypes.c_int(level))

    def set_trigger_source(self,source) -> None:
        self._lib.oscilloscope_set_trigger_source(ctypes.c_void_p(self._handle), ctypes.c_int(source))

    def set_trigger_slope(self,slope) -> None:
        self._lib.oscilloscope_set_trigger_slope(ctypes.c_void_p(self._handle), ctypes.c_int(slope))

    def force_trigger(self) -> None:
        self._lib.oscilloscope_force_trigger(ctypes.c_void_p(self._handle))
