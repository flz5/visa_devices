---
hide:
  - footer
---


# Supported power supplies

This page contains a list of devices, for which models a driver is avaiable.

The ids for use with the generic driver are definded here:
```
inc/generic/generic_power_supply_id.h
```

The implementation for the specific devices can be found here:
```
inc/devices/
```

## Keysight

| Model    | Revision | Driver (file)     | Driver (ID)         | Driver (value)  |
| -----    | -------- | -------------     | --------------      | --------------- | 
| 6611     | All      | dev_KS_6612.h     | DRIVER_PS_KS6611    | 0x00010000      |
| 6612     | All      | dev_KS_6612.h     | DRIVER_PS_KS6612    | 0x00010001      |
| 6613     | All      | dev_KS_6612.h     | DRIVER_PS_KS6613    | 0x00010002      |
| 6614     | All      | dev_KS_6612.h     | DRIVER_PS_KS6614    | 0x00010003      |
| 6631     | All      | dev_KS_6612.h     | DRIVER_PS_KS6631    | 0x00010004      |
| 6632     | All      | dev_KS_6612.h     | DRIVER_PS_KS6632    | 0x00010005      |
| 6633     | All      | dev_KS_6612.h     | DRIVER_PS_KS6633    | 0x00010006      |
| 6634     | All      | dev_KS_6612.h     | DRIVER_PS_KS6634    | 0x00010007      |
| 66312    | All      | dev_KS_6612.h     | DRIVER_PS_KS66312   | 0x00010008      |
| 66332    | All      | dev_KS_6612.h     | DRIVER_PS_KS66332   | 0x00010009      |


## Siglent

| Model    | Revision | Driver (file)     | Driver (ID)         | Driver (value)  |
| -------- | -------- | ----------------- | ------------------- | --------------- | 
| SPD3303X | All      | dev_SL_SPD3303X.h | DRIVER_PS_SPD3303X  | 0x00020000      |
| SPD3303C | All      | dev_SL_SPD3303X.h | DRIVER_PS_SPD3303C  | 0x00020001      |
| SPD1168X | All      | dev_SL_SPD3303X.h | DRIVER_PS_SPD1168X  | 0x00020002      |
| SPS5041X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5041X  | 0x00030000      |
| SPS5042X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5042X  | 0x00030001      |
| SPS5043X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5043X  | 0x00030002      |
| SPS5044X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5044X  | 0x00030003      |
| SPS5045X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5045X  | 0x00030004      |  
| SPS5051X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5051X  | 0x00030005      |
| SPS5081X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5081X  | 0x00030006      |
| SPS5082X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5082X  | 0x00030007      |
| SPS5083X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5083X  | 0x00030008      |
| SPS5084X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5084X  | 0x00030009      |
| SPS5085X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5085X  | 0x0003000A      |
| SPS5161X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5161X  | 0x0003000B      |
| SPS5162X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5162X  | 0x0003000C      |
| SPS5163X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5163X  | 0x0003000D      |
| SPS5164X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5164X  | 0x0003000E      |
| SPS5165X | All      | dev_SL_SPS5000X.h | DRIVER_PS_SPS5165X  | 0x0003000F      |


## Rigol


| Model    | Revision | Driver (file)     | Driver (ID)         | Driver (value)  |
| -------- | -------- | ----------------- | ------------------- | --------------- | 
| DP832A   | All      | dev_RG_DP800.h    | DRIVER_PS_DP832A    | 0x00040001      |
| DP832    | All      | dev_RG_DP800.h    | DRIVER_PS_DP832     | 0x00040002      |
| DP831A   | All      | dev_RG_DP800.h    | DRIVER_PS_DP831A    | 0x00040003      |
| DP831    | All      | dev_RG_DP800.h    | DRIVER_PS_DP831     | 0x00040004      |
| DP822A   | All      | dev_RG_DP800.h    | DRIVER_PS_DP822A    | 0x00040005      |
| DP822    | All      | dev_RG_DP800.h    | DRIVER_PS_DP822     | 0x00040006      |
| DP821A   | All      | dev_RG_DP800.h    | DRIVER_PS_DP821A    | 0x00040007      |
| DP821    | All      | dev_RG_DP800.h    | DRIVER_PS_DP821     | 0x00040008      |
| DP813A   | All      | dev_RG_DP800.h    | DRIVER_PS_DP813A    | 0x00040009      |
| DP813    | All      | dev_RG_DP800.h    | DRIVER_PS_DP813     | 0x0004000A      |
| DP811A   | All      | dev_RG_DP800.h    | DRIVER_PS_DP811A    | 0x0004000B      |
| DP811    | All      | dev_RG_DP800.h    | DRIVER_PS_DP811     | 0x0004000C      |
