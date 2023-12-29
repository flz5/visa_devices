---
hide:
  - footer
---


# Generic drivers

The generic drivers provide a uniform device-independent control interface.

During initialization, the device and driver ID is stored in the device's session. Based on this, the data is passed on to the associated specialized driver when the generic functions are called.

The generic driver interface includes a reduced set of functions which is available to all instruments of that type. It is alternatively possible to call the device specific driver functions.

The Usage is shown on this page using the multimeter driver as an example. Other device type can be handled identical.

## Connect driver

The handling of the driver is implemented inside the "VisaSession.h".

```
void visa_device_set_driver(VisaHandle* handle, int id)
int visa_device_get_driver(VisaHandle* handle)
```

**handle:**Visa Handle

**id:** Device id (can be found in generic/generic_id.h)


## Header files

| Type | File |
|---|---|
|Multimeter|generic/generic_multimeter.h|
|Electronic load|generic/generic_electronic_load.h|
|Power supply|generic/generic_power_supply.h|
|Oscilloscope|generic/generic_oscilloscope.h|

