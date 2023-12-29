---
hide:
  - footer
---

# VISA

Virtual instrument software architecture (VISA) is a widely used application programming interface, for communicating with test and measurement instruments from a computer.


## Device addresses

### LXI

Communication over LAN

Typical device address:
```
PLACEHOLDER
```

### Ethernet sockets

Device which not implement the LXI standard can be acces using a direct socket connection. 

Typical device address:
```
PLACEHOLDER
```

### Serial port

Typical device address:
```
ASRL1::INSTR
```

### GPIB

Typical device address:
```
PLACEHOLDER
```

### USB

Typical device address:
```
PLACEHOLDER
```

## Muliple access

Is not possible. When a communication channel is opened,  a parallel connection to another software is not possible.
