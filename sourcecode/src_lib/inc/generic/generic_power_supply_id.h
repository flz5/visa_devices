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

#ifndef VD_GENERIC_POWER_SUPPLY_ID_H
#define VD_GENERIC_POWER_SUPPLY_ID_H

//*** Power supplies ***

#define DRIVER_PS_DUMMY     0x00000000

//Keysight (former HP, Agilent)
#define DRIVER_PS_KS6611	0x00010000
#define DRIVER_PS_KS6612	0x00010001
#define DRIVER_PS_KS6613	0x00010002
#define DRIVER_PS_KS6614	0x00010003
#define DRIVER_PS_KS66312	0x00010004
#define DRIVER_PS_KS66332	0x00010005
#define DRIVER_PS_KS6631	0x00010006
#define DRIVER_PS_KS6632	0x00010007
#define DRIVER_PS_KS6633	0x00010008
#define DRIVER_PS_KS6634	0x00010009

//Siglent
#define DRIVER_PS_SPD3303X  0x00020000
#define DRIVER_PS_SPD3303C	0x00020001
#define DRIVER_PS_SPD1168X	0x00020002

#define DRIVER_PS_SPS5041X 0x00030000
#define DRIVER_PS_SPS5042X 0x00030001
#define DRIVER_PS_SPS5043X 0x00030002
#define DRIVER_PS_SPS5044X 0x00030003
#define DRIVER_PS_SPS5045X 0x00030004
#define DRIVER_PS_SPS5051X 0x00030005
#define DRIVER_PS_SPS5081X 0x00030006
#define DRIVER_PS_SPS5082X 0x00030007
#define DRIVER_PS_SPS5083X 0x00030008
#define DRIVER_PS_SPS5084X 0x00030009
#define DRIVER_PS_SPS5085X 0x0003000A
#define DRIVER_PS_SPS5161X 0x0003000B
#define DRIVER_PS_SPS5162X 0x0003000C
#define DRIVER_PS_SPS5163X 0x0003000D
#define DRIVER_PS_SPS5164X 0x0003000E
#define DRIVER_PS_SPS5165X 0x0003000F

//Rigol
#define DRIVER_PS_DP832A    0x00040001
#define DRIVER_PS_DP832     0x00040002
#define DRIVER_PS_DP831A    0x00040003
#define DRIVER_PS_DP831     0x00040004
#define DRIVER_PS_DP822A    0x00040005
#define DRIVER_PS_DP822     0x00040006
#define DRIVER_PS_DP821A    0x00040007
#define DRIVER_PS_DP821     0x00040008
#define DRIVER_PS_DP813A    0x00040009
#define DRIVER_PS_DP813     0x0004000A
#define DRIVER_PS_DP811A    0x0004000B
#define DRIVER_PS_DP811     0x0004000C

#endif //HELLO_GENERIC_POWER_SUPPLY_ID_H
