---
hide:
  - footer
---


# Waveform 

vd-wfmdmp is a command line tool, to directly read waveform data from a device using the generic drivers.

!!! bug "not complete"
    The tool is not complete!

Usage:
```
vd-wfmdmp <ADDR> <DRIVER_ID> <DEV_TYPE> <CHANNEL> <UNIT> <FILENAME>
```

Example:
```
vd-wfmdmp.exe TCPIP0::192.168.10.26::inst0::INSTR 12345678 1 s 1 U file.cs
```

## Arguments

### Device type

| Type      | Description                               |
| --------- | ----------------------------------------- |
| 1         | power supply                              |
| 2         | electronic load                           |
| 3         | signal generator                          |

### Channel

Integer

### Unit

Types:

| Type      | Description                               |
| --------- | ----------------------------------------- |
| U         | Voltge                                    |
| I         | Current                                   |
| P         | Power                                     |
| W         | Waveform (oscilloscope  only)             |
| R         | Resistance                                |
| F         | Frequency                                 |

### File

Path to the file.

## Results

The tools write the data directly in the specifie file.