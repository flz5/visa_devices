---
hide:
  - footer
---


# Command

vd-command is a command line tool, to directly configure a device using the generic drivers.

!!! bug "not complete"
    The tool is not complete!

Usage:
```
vd-command <ADDR> <DRIVER_ID> <DEV_TYPE> <MODE> <CHANNEL> <UNIT> <VALUE>
```

## Arguments

### Device type

| Type      | Description                               |
| --------- | ----------------------------------------- |
|1          | power supply                              |
|2          | electronic load                           |
|3          | signal generator                          |

### Mode

| Type      | Description                               |
| --------- | ----------------------------------------- |
| s         | set                                       |
| g         | get                                       |

### CHANNEL

Integer

### UNIT

Types:

| Type      | Description                               |
| --------- | ----------------------------------------- |
| U         | Voltge                                    |
| I         | Current                                   |
| P         | Power                                     |
| W         | Waveform (oscilloscope  only)             |
| R         | Resistance                                |
| F         | Frequency                                 |

### VALUE

Double

## Results

The tools write the value directly on console output.