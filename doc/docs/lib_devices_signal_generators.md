---
hide:
  - footer
---


# Supported signal generators

This page contains a list of devices, for which models a driver is avaiable.

The ids for use with the generic driver are definded here:
```
inc/generic/generic_signal_generator_id.h
```

The implementation for the specific devices can be found here:
```
inc/devices/
```

## Rigol

| Model    | Revision | Driver (file)     | Driver (ID)         | Driver (value)  |
| -----    | -------- | -------------     | --------------      | --------------- | 
| MSO5072  | All      | dev_RG_MSO5000.h  | DRIVER_SG_MSO5072   | 0x00020000      |
| MSO5074  | All      | dev_RG_MSO5000.h  | DRIVER_SG_MSO5074   | 0x00020001      |
| MSO5102  | All      | dev_RG_MSO5000.h  | DRIVER_SG_MSO5102   | 0x00020002      |
| MSO5104  | All      | dev_RG_MSO5000.h  | DRIVER_SG_MSO5104   | 0x00020003      |
| MSO5507  | All      | dev_RG_MSO5000.h  | DRIVER_SG_MSO5507   | 0x00020004      |
| MSO5354  | All      | dev_RG_MSO5000.h  | DRIVER_SG_MSO5354   | 0x00020005      |
