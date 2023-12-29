---
hide:
  - footer
---

# Electronic load


## Init

```
void electronic_load_init(VisaHandle* handle);
```

```
void electronic_load_deinit(VisaHandle* handle);

```

!!! note "Free memory"
    To free the used memory, deinit should be called when the device is 	not needed anymore.

## Mode


```
oid electronic_load_set_mode(VisaHandle* handle, int channel, electronic_load_mode_t value);
```

| Mode | Var |
|---|---|
|LOAD_MODE_CURRENT|0|
|LOAD_MODE_VOLTAGE|1|
|LOAD_MODE_RESISTANCE|2|
|LOAD_MODE_POWER|3|


## Current

```
void electronic_load_set_current(VisaHandle* handle, int channel, double value);
```

```
 double electronic_load_get_current(VisaHandle* handle, int channel);
```

```
double electronic_load_get_current_min(VisaHandle* handle, int channel);
```

```
double electronic_load_get_current_max(VisaHandle* handle, int channel);
```

## Voltage


```
void electronic_load_set_voltage(VisaHandle* handle, int channel, double value);
```

```
double electronic_load_get_voltage(VisaHandle* handle, int channel);
```

```
double electronic_load_get_voltage_min(VisaHandle* handle, int channel);
```

```
double electronic_load_get_voltage_max(VisaHandle* handle, int channel);
```
## Resistance


```
void electronic_load_set_resistance(VisaHandle* handle, int channel, double value);
```

```
double electronic_load_get_resistance(VisaHandle* handle, int channel);
```

```
double electronic_load_get_resistance_min(VisaHandle* handle, int channel);
```

```
double electronic_load_get_resistance_max(VisaHandle* handle, int channel);
```
## Power

```
void electronic_load_set_power(VisaHandle* handle, int channel, double value);
```

```
double electronic_load_get_power(VisaHandle* handle, int channel);
```

```
double electronic_load_get_power_min(VisaHandle* handle, int channel);
```

```
double electronic_load_get_power_max(VisaHandle* handle, int channel);
```

## Output

```
void electronic_load_set_output(VisaHandle* handle, int channel, bool value);
```