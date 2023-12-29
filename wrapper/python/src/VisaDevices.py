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


class VisaDevices:

    def __init__(self, filename):
        self.session = None
        self.lib = ctypes.CDLL(filename)

        self.lib.visa_session_open.restype = ctypes.c_void_p
        self.lib.visa_device_connect.restype = ctypes.c_void_p

    def session_open(self):
        self.session = self.lib.visa_session_open()

    def device_connect(self, addr_str, v1, v2):
        addr = addr_str.encode('utf-8')
        return self.lib.visa_device_connect(ctypes.c_void_p(self.session), ctypes.c_char_p(addr),
                                            ctypes.c_int(v1), ctypes.c_int(v2))
