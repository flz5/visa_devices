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

class ElectronicLoad:

    def __init__(self,  lib, handle):
        self._handle = None
        self._lib = None

        self._lib.electronic_load_get_driver.restype = ctypes.c_int
        self._lib.electronic_load_get_current.restype = ctypes.c_double
        self._lib.electronic_load_get_current_min.restype = ctypes.c_double
        self._lib.electronic_load_get_current_max.restype = ctypes.c_double
        self._lib.electronic_load_get_voltage.restype = ctypes.c_double
        self._lib.electronic_load_get_voltage_min.restype = ctypes.c_double
        self._lib.electronic_load_get_voltage_max.restype = ctypes.c_double
        self._lib.electronic_load_get_resistance.restype = ctypes.c_double
        self._lib.electronic_load_get_resistance_min.restype = ctypes.c_double
        self._lib.electronic_load_get_resistance_max.restype = ctypes.c_double
        self._lib.electronic_load_get_power.restype = ctypes.c_double
        self._lib.electronic_load_get_power_min.restype = ctypes.c_double
        self._lib.electronic_load_get_power_max.restype = ctypes.c_double

    def set_driver(self,driver_id):
        self._lib.oscilloscope_set_driver(ctypes.c_void_p(self._handle), ctypes.c_int(driver_id))

    def get_driver(self):
        return self._lib.electronic_load_get_driver(ctypes.c_void_p(self._handle))

    def set_current(self,channel,value):
        self._lib.electronic_load_set_current(ctypes.c_void_p(self._handle), ctypes.c_int(channel),
                                              ctypes.c_double(value))

    def get_current(self,channel):
        return self._lib.electronic_load_get_current(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_current_min(self,channel):
        return self._lib.electronic_load_get_current_min(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_current_max(self,channel):
        return self._lib.electronic_load_get_current_max(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def set_voltage(self,channel,value):
        self._lib.electronic_load_set_voltage(ctypes.c_void_p(self._handle), ctypes.c_int(channel),
                                              ctypes.c_double(value))

    def get_voltage(self,channel):
        return self._lib.electronic_load_get_voltage(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_voltge_min(self,channel):
        return self._lib.electronic_load_get_voltage_min(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_voltage_max(self,channel):
        return self._lib.electronic_load_get_voltage_max(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def set_resistance(self,channel, value):
        self._lib.electronic_load_set_resistance(ctypes.c_void_p(self._handle), ctypes.c_int(channel),
                                                 ctypes.c_double(value))

    def get_resistance(self,channel):
        return self._lib.electronic_load_get_resistance(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_resistance_min(self,channel):
        return self._lib.electronic_load_get_resistance_min(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_resistance_max(self,channel):
        return self._lib.electronic_load_get_resistance_max(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def set_power(self,channel,value):
        self._lib.electronic_load_set_power(ctypes.c_void_p(self._handle), ctypes.c_int(channel),
                                            ctypes.c_double(value))

    def get_power(self,channel):
        return self._lib.electronic_load_get_power(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_power_min(self,channel):
        return self._lib.electronic_load_get_power_min(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_power_max(self,channel):
        return self._lib.electronic_load_get_power_max(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def set_output(self,channel,value):
        self._lib.electronic_load_set_output(ctypes.c_void_p(self._handle), ctypes.c_int(channel), ctypes.c_bool(value))

    def set_mode(self,channel,value):
        self._lib.electronic_load_set_mode(ctypes.c_void_p(self._handle), ctypes.c_int(channel), ctypes.c_bool(value))