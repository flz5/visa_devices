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


class OscilloscopeChannelCoupling:
    COUPLING_DC = 0
    COUPLING_AC = 1
    COUPLING_GND = 2


class OscilloscopeImpedance:
    R50 = 0
    R75 = 1
    R1M = 2


class OscilloscopeTriggerSource:
    CH1 = 0
    CH2 = 1
    CH3 = 2
    CH4 = 3
    AUX = 4
    Line = 5


class OscilloscopeTriggerCoupling:
    AC = 0
    DC = 1
    HFReject = 2
    LFReject = 3
    NoiseReject = 4


class OscilloscopeTriggerMode:
    AUTO = 0
    NORMAL = 1
    SINGLE = 2


class OscilloscopeTriggerSlope:
    RISING = 0
    FALLING = 1
