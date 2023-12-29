---
hide:
  - footer
---

# Multimeter driver

## Init

```
void multimeter_init(VisaHandle* handle);
```

```
void multimeter_deinit(VisaHandle* handle);

```

!!! note "Free memory"
    To free the used memory, deinit should be called when the device is 	not needed anymore.


## Config

```
void multimeter_set_mode(VisaHandle* handle,int channel, multimeter_mode mode);
```

| Mode | Def.| Var |
|---|---|---|
| Voltage DC|Multimeter_Mode_Voltage_DC| 1|
| Voltage AC|Multimeter_Mode_Voltage_AC| 2|
| Current DC|Multimeter_Mode_Current_DC| 3|
| Current AC|Multimeter_Mode_Current_AC| 4|
| Resistance|Multimeter_Mode_Resistance| 5|
| Frequency|Multimeter_Mode_Frequency| 6|
| Period|Multimeter_Mode_Period| 7|
| Continuity|Multimeter_Mode_Continuity| 8|
| Diode|Multimeter_Mode_Diode| 9|


## Measurement

```
double multimeter_get_measurement(VisaHandle* handle, int channel);
```