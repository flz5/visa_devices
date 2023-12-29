---
hide:
  - footer
---


# Supported oscilloscopes

This page contains a list of devices, for which models a driver is avaiable.

The ids for use with the generic driver are definded here:
```
inc/generic/generic_oscilloscope_id.h
```

The implementation for the specific devices can be found here:
```
inc/devices/
```

## Rigol

| Model    | Revision | Driver (file)     | Driver (ID)         | Driver (value)  |
| -----    | -------- | -------------     | --------------      | --------------- | 
| MSO5072  | All      | dev_RG_MSO5000.h  | DRIVER_OS_MSO5072   | 0x00020000      |
| MSO5074  | All      | dev_RG_MSO5000.h  | DRIVER_OS_MSO5074   | 0x00020001      |
| MSO5102  | All      | dev_RG_MSO5000.h  | DRIVER_OS_MSO5102   | 0x00020002      |
| MSO5104  | All      | dev_RG_MSO5000.h  | DRIVER_OS_MSO5104   | 0x00020003      |
| MSO5507  | All      | dev_RG_MSO5000.h  | DRIVER_OS_MSO5507   | 0x00020004      |
| MSO5354  | All      | dev_RG_MSO5000.h  | DRIVER_OS_MSO5354   | 0x00020005      |

## Tektronix

| Model    | Revision | Driver (file)     | Driver (ID)         | Driver (value)  |
| -----    | -------- | -------------     | --------------      | --------------- | 
| TDS420   | All      | dev_TK_TDS700.h   | DRIVER_OS_TDS420    | 0x00010000      |
| TDS 430  | All      | dev_TK_TDS700.h   | DRIVER_OS_TDS430    | 0x00010001      |
| TDS 460  | All      | dev_TK_TDS700.h   | DRIVER_OS_TDS460    | 0x00010002      |
| TDS 510  | All      | dev_TK_TDS700.h   | DRIVER_OS_TDS510    | 0x00010003      |
| TDS 520  | All      | dev_TK_TDS700.h   | DRIVER_OS_TDS520    | 0x00010004      |
| TDS 540  | All      | dev_TK_TDS700.h   | DRIVER_OS_TDS540    | 0x00010005      |
| TDS 620  | All      | dev_TK_TDS700.h   | DRIVER_OS_TDS620    | 0x00010006      |
| TDS 644  | All      | dev_TK_TDS700.h   | DRIVER_OS_TDS644    | 0x00010007      |
| TDS 680  | All      | dev_TK_TDS700.h   | DRIVER_OS_TDS680    | 0x00010008      |
| TDS 684  | All      | dev_TK_TDS700.h   | DRIVER_OS_TDS684    | 0x00010009      |
| TDS 724  | All      | dev_TK_TDS700.h   | DRIVER_OS_TDS724    | 0x0001000A      |
| TDS 754  | All      | dev_TK_TDS700.h   | DRIVER_OS_TDS754    | 0x0001000B      |
| TDS 784  | All      | dev_TK_TDS700.h   | DRIVER_OS_TDS784    | 0x0001000C      |

