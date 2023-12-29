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

from . import DriverPowerSupply, DriverMultimeter, DriverElectronicLoad, DriverOscilloscope


class DriverId:
    PowerSupply = DriverPowerSupply.DriverPowerSupply()
    Multimeter = DriverMultimeter.DriverMultimeter()
    ElectronicLoad = DriverElectronicLoad.DriverElectronicLoad()
    Oscilloscope = DriverOscilloscope.DriverOscilloscope()
