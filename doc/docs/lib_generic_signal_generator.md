---
hide:
  - footer
---

# Signal generator

## Init

```
void signal_generator_init(VisaHandle* handle);
```

```
void signal_generator_deinit(VisaHandle* handle);

```

!!! note "Free memory"
    To free the used memory, deinit should be called when the device is 	not needed anymore.

## Waveform


```
void power_supply_set_waveform_type(VisaHandle* handle, int channel, signal_generator_waveform_type value);
```

```
void signal_generator_set_waveform_data(VisaHandle* handle, int channel, bool relative, double *data);
```
## Analog


```
void signal_generator_set_amplitude(VisaHandle* handle, int channel, double value);
```

```
void signal_generator_set_offset(VisaHandle* handle, int channel, double value);
```

```
void power_supply_set_frequency(VisaHandle* handle, int channel, double value);
```

```
void signal_generator_set_level(VisaHandle* handle, int channel, double min, double max);
```
## Output

```
void signal_generator_set_output(VisaHandle* handle, int channel, bool value);
```