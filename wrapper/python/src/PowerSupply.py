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


class PowerSupply:
    def __init__(self, lib, handle):
        self._handle = handle
        self._lib = lib

        self._lib.power_supply_get_voltage.restype = ctypes.c_double
        self._lib.power_supply_get_driver.restype = ctypes.c_int
        self._lib.power_supply_get_current.restype = ctypes.c_double
        self._lib.power_supply_get_current_min.restype = ctypes.c_double
        self._lib.power_supply_get_current_max.restype = ctypes.c_double
        self._lib.power_supply_get_voltage_min.restype = ctypes.c_double
        self._lib.power_supply_get_voltage_max.restype = ctypes.c_double
        self._lib.power_supply_get_ocp.restype = ctypes.c_double
        self._lib.power_supply_get_ocp_max.restype = ctypes.c_double
        self._lib.power_supply_get_ovp.restype = ctypes.c_double
        self._lib.power_supply_get_ovp_min.restype = ctypes.c_double
        self._lib.power_supply_get_ovp_max.restype = ctypes.c_double
        self._lib.power_supply_get_protection.restype = ctypes.c_bool

    def set_driver(self, driver_id):
        self._lib.power_supply_set_driver(ctypes.c_void_p(self._handle), ctypes.c_int(driver_id))

    def get_driver(self):
        return self._lib.power_supply_get_driver(ctypes.c_void_p(self._handle))

    def init(self):
        self._lib.power_supply_init(ctypes.c_void_p(self._handle))

    def deinit(self):
        self._lib.power_supply_deinit(ctypes.c_void_p(self._handle))

    def set_current(self, channel, value):
        self._lib.power_supply_set_current(ctypes.c_void_p(self._handle), ctypes.c_int(channel), ctypes.c_double(value))

    def get_current(self, channel):
        return self._lib.power_supply_get_current(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_current_min(self, channel):
        return self._lib.power_supply_get_current_min(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_current_max(self, channel):
        return self._lib.power_supply_get_current_max(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def set_voltage(self, channel, value):
        self._lib.power_supply_set_voltage(ctypes.c_void_p(self._handle), ctypes.c_int(channel), ctypes.c_double(value))

    def get_voltage(self, channel):
        return self._lib.power_supply_get_voltage(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_voltage_min(self, channel):
        return self._lib.power_supply_get_voltage_min(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_voltage_max(self, channel):
        return self._lib.power_supply_get_voltage_max(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def set_ocp(self, channel, value):
        self._lib.power_supply_set_ocp(ctypes.c_void_p(self._handle), ctypes.c_int(channel), ctypes.c_double(value))

    def get_ocp(self, channel):
        return self._lib.power_supply_get_ocp(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_ocp_max(self, channel):
        return self._lib.power_supply_get_ocp_max(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def set_ovp(self, channel, value):
        self._lib.power_supply_set_ovp(ctypes.c_void_p(self._handle), ctypes.c_int(channel), ctypes.c_double(value))

    def get_ovp(self, channel):
        return self._lib.power_supply_get_ovp(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_ovp_min(self, channel):
        return self._lib.power_supply_get_ovp_min(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_ovp_max(self, channel):
        return self._lib.power_supply_get_ovp_max(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def clear_protection(self, channel):
        self._lib.power_supply_clear_protection(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def get_protection(self, channel):
        return self._lib.power_supply_get_protection(ctypes.c_void_p(self._handle), ctypes.c_int(channel))

    def set_output(self, channel, value):
        self._lib.power_supply_set_output(ctypes.c_void_p(self._handle), ctypes.c_int(channel), ctypes.c_bool(value))
