---
hide:
  - footer
---


# Supported electronic loads

This page contains a list of devices, for which models a driver is avaiable.

The ids for use with the generic driver are definded here:
```
inc/generic/generic_electronic_load_id.h
```

The implementation for the specific devices can be found here:
```
inc/devices/
```

## GW Instek

| Model    | Revision | Driver (file)     | Driver (ID)         | Driver (value)  |
| -----    | -------- | -------------     | --------------      | --------------- | 
| PEL3000E | All      | dev_GW_PEL3000E.h | DRIVER_EL_PEL3000E  | 0x00010000      |

