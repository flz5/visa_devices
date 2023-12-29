---
hide:
  - footer
---

# Power supply driver

## Init

```
void power_supply_init(VisaHandle* handle);
```

```
void power_supply_deinit(VisaHandle* handle);

```

!!! note "Free memory"
    To free the used memory, deinit should be called when the device is 	not needed anymore.

## Voltage / current source


```
void power_supply_deinit(VisaHandle* handle);
```


```
void power_supply_set_current(VisaHandle* handle, int channel, double value);
```

```
double power_supply_get_current(VisaHandle* handle, int channel);
```


```
double power_supply_get_current_min(VisaHandle* handle, int channel);
```


```
double power_supply_get_current_max(VisaHandle* handle, int channel);
```


```
void power_supply_set_voltage(VisaHandle* handle, int channel, double value);
```


```
double power_supply_get_voltage(VisaHandle* handle, int channel);
```


```
double power_supply_get_voltage_min(VisaHandle* handle, int channel);
```


```
double power_supply_get_voltage_max(VisaHandle* handle, int channel);
```

## Overvoltage / Overcurrent protection

!!! warning "Device handling"
    The OCP/OOVP behavior depends on the device. Normally the output is switched off, but shorting the output is also possible.

```
void power_supply_set_ocp(VisaHandle* handle, int channel, double value);
```

```
double power_supply_get_ocp(VisaHandle* handle, int channel);
```

```
double power_supply_get_ocp_max(VisaHandle* handle, int channel);
```

```
void power_supply_set_ovp(VisaHandle* handle, int channel, double value);
```

```
power_supply_get_ovp(VisaHandle* handle, int channel);
```

```
power_supply_get_ovp_min(VisaHandle* handle, int channel);
```

```
power_supply_get_ovp_max(VisaHandle* handle, int channel);
```

```
void power_supply_clear_protection(VisaHandle* handle, int channel);
```

```
bool power_supply_get_protection(VisaHandle* handle, int channel);
```


## Output state

```
void power_supply_set_output(VisaHandle* handle, int channel, bool value);
```