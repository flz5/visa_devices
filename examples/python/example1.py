import ctypes
lib = ctypes.CDLL("./libVisaDevices.dll")

lib.visa_session_open.restype = ctypes.c_void_p
session = lib.visa_session_open()

addr_str = "TCPIP0::192.168.10.25::5025::SOCKET"
addr = addr_str.encode('utf-8')

lib.visa_device_connect.restype = ctypes.c_void_p
handle = lib.visa_device_connect(ctypes.c_void_p(session), ctypes.c_char_p(addr), ctypes.c_int(0), ctypes.c_int(0))

lib.power_supply_set_driver(ctypes.c_void_p(handle), ctypes.c_int(0x00020000))
lib.power_supply_set_voltage(ctypes.c_void_p(handle), ctypes.c_int(1), ctypes.c_double(5.88))

lib.power_supply_get_voltage.restype = ctypes.c_double
kk = lib.power_supply_get_voltage(ctypes.c_void_p(handle), ctypes.c_int(1))

print("UU")