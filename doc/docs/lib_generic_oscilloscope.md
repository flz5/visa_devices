---
hide:
  - footer
---

# Oscilloscope

## Init

```
void oscilloscope_init(VisaHandle* handle);
```

```
void oscilloscope_deinit(VisaHandle* handle);

```

!!! note "Free memory"
    To free the used memory, deinit should be called when the device is 	not needed anymore.

## data

```
void oscilloscope_save_waveform(VisaHandle* handle, int channel, char *filename);
```

```
void oscilloscope_get_waveform(VisaHandle* handle, int channel, double *data, int size);
```


## scaling

```
void oscilloscope_set_hdiv(VisaHandle* handle, int channel, double value);
```

```
void oscilloscope_set_vdiv(VisaHandle* handle, int channel, double value);
```


## trigger

```
void oscilloscope_set_trigger_mode(VisaHandle* handle,oscilloscope_trigger_mode mode);
```

```
void oscilloscope_set_trigger_coupling(VisaHandle* handle,oscilloscope_trigger_coupling mode);
```

```
void oscilloscope_set_trigger_level(VisaHandle* handle, double value);
```

```
void oscilloscope_set_trigger_source(VisaHandle* handle, oscilloscope_trigger_source source);
```

```
void oscilloscope_set_trigger_slope(VisaHandle* handle, oscilloscope_trigger_slope slope);
```

```
void oscilloscope_force_trigger(VisaHandle* handle);
```

