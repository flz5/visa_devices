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

#ifndef WFMDMP_DEVICE_TYPES_H
#define WFMDMP_DEVICE_TYPES_H

typedef enum{
    PowerSupply = 0,
    Multimeter = 1,
    ElectronicLoad = 2,
    Oscilloscope = 3,
    NetworkAnalyzer = 4,
    SpectrumAnalyzer = 5,
    SignalGenerator = 6
} device_type;

#endif //WFMDMP_DEVICE_TYPES_H