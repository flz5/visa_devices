---
hide:
  - footer
---



```
#include "system/VisaDevice.h"
#include "system/VisaSession.h"
#include "devices/dev_SL_SPD3303X.h"
#include "generic/generic_power_supply.h"
#include "generic/generic_id.h"

int main()
{
    VisaSession* session = visa_session_open();

    std::string addr = "TCPIP0::192.168.10.25::5025::SOCKET";

    VisaHandle* hDev = visa_device_connect(session,addr.data(),0,0);

    power_supply_set_driver(hDev,DRIVER_SPD3303X);
    power_supply_set_voltage(hDev,1,5.88);

    double kk = SPD3303X_get_voltage(hDev, 1);

}
```