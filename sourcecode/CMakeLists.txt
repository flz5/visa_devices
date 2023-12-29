#
# This file is part of the VisaDevices library project.
# Copyright (c) 2019-2023 Frank Zimdars.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as
# published by the Free Software Foundation, version 3.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#

# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.

cmake_minimum_required (VERSION 3.0.0)
set (CMAKE_CXX_STANDARD 20)
project (VisaDevices)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES_LIB
        src_lib/src/dllmain.cpp
        src_lib/src/VisaSession.cpp
        src_lib/src/generic/generic.cpp
        src_lib/src/generic/generic_electronic_load.cpp
        src_lib/src/generic/generic_multimeter.cpp
        src_lib/src/generic/generic_oscilloscope.cpp
        src_lib/src/generic/generic_power_supply.cpp
        src_lib/src/devices/dev_GW_PEL3000E.cpp
        src_lib/src/devices/dev_KS_6612.cpp
        src_lib/src/devices/dev_KS_34401.cpp
        src_lib/src/devices/dev_KS_E8361.cpp
        src_lib/src/devices/dev_RG_MSO5000.cpp
        src_lib/src/devices/dev_KS_33210.cpp
        src_lib/src/devices/dev_JT_JDS6600.cpp
        src_lib/src/devices/dev_RS_ZVA50.cpp
        src_lib/src/devices/dev_SL_SPD3303X.cpp
        src_lib/src/devices/dev_TK_TDS700.cpp
        src_lib/src/devices/dev_RG_DP800.cpp
        src_lib/src/devices/dev_NN_ELDummy.cpp
        src_lib/src/devices/dev_NN_MMDummy.cpp
        src_lib/src/devices/dev_NN_OSDummy.cpp
        src_lib/src/devices/dev_NN_PSDummy.cpp
        src_lib/src/devices/dev_NN_SG_Dummy.cpp
        src_lib/src/devices/dev_NN_NADummy.cpp
        src_lib/src/devices/dev_NN_SADummy.cpp
        src_lib/src/system.cpp
        src_lib/src/devices/dev_SL_SPS5000X.cpp
        src_lib/src/generic/generic_signal_generator.cpp
        src_lib/src/generic/generic_network_analyzer.cpp
        src_lib/src/generic/generic_spectrum_analyzer.cpp
        src_command/inc/cmd_get.h
        src_command/inc/cmd_set.h
        src_command/inc/device_types.h
)

# Create a library called "libVisaDevices" which includes the source files.
# The extension is already found. Any number of sources could be listed here.
add_library (libVisaDevices SHARED ${SOURCES_LIB})

#Set defines for library
# set variable for the C preprocessor to detect the operating system
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(libVisaDevices PRIVATE
            DLL_EXPORT
            OS_LINUX
    )
    target_include_directories(libVisaDevices
            PRIVATE
            ${PROJECT_SOURCE_DIR}/src_lib/inc
            ${PROJECT_SOURCE_DIR}/src_lib/inc_int
            "TODO"
    )
    #Link with VISA library
    target_link_libraries(libVisaDevices "TODO")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_definitions(libVisaDevices PRIVATE
            DLL_EXPORT
            OS_MAC
    )
    target_include_directories(libVisaDevices
            PRIVATE
            ${PROJECT_SOURCE_DIR}/src_lib/inc
            ${PROJECT_SOURCE_DIR}/src_lib/inc_int
            "/Library/Frameworks/Visa.framework/Versions/A/Headers"
    )
    #Link with VISA library
    target_link_libraries(libVisaDevices "/Library/Frameworks/Visa.framework/VISA")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(libVisaDevices PRIVATE
            DLL_EXPORT
            OS_WIN
    )
    target_include_directories(libVisaDevices
            PRIVATE
            ${PROJECT_SOURCE_DIR}/src_lib/inc
            ${PROJECT_SOURCE_DIR}/src_lib/inc_int
            "C:\\Program Files\\IVI Foundation\\VISA\\Win64\\Include\\"
    )
    #Link with VISA library
    target_link_libraries(libVisaDevices "C:\\Program Files\\IVI Foundation\\VISA\\Win64\\Lib_x64\\msc\\visa64.lib")
endif()

#------------------------
#vd-curvetracer

set(SOURCES_CURVETRACER
        src_curvetracer/src/controller.cpp
        src_curvetracer/src/controller_connect.cpp
        src_curvetracer/src/controller_measurement.cpp
        src_curvetracer/src/controller_sweep.cpp
        src_curvetracer/src/main.cpp
        src_curvetracer/src/measurement_array.cpp
        src_curvetracer/src/ui.cpp
        src_curvetracer/src/ui_devices.cpp
        src_curvetracer/src/ui_files.cpp
        src_curvetracer/src/ui_sweep.cpp
        src_curvetracer/src/ui_measurements.cpp
        src_curvetracer/src/ui_measurements.cpp
        src_curvetracer/src/sweep_counter.cpp
        src_curvetracer/inc/sweep_counter.h
        src_curvetracer/src/sweep.cpp
)

add_executable(vd-curvetracer ${SOURCES_CURVETRACER})

target_include_directories(vd-curvetracer
        PRIVATE
        ${PROJECT_SOURCE_DIR}/src_curvetracer/inc
        ${PROJECT_SOURCE_DIR}/src_lib/inc
)

#Set defines for library
# set variable for the C preprocessor to detect the operating system
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(vd-curvetracer PRIVATE
            OS_LINUX
    )
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_definitions(vd-curvetracer PRIVATE
            OS_MAC
    )
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(vd-curvetracer PRIVATE
            OS_WIN
    )
endif()

target_link_libraries(vd-curvetracer libVisaDevices)

#------------------------
#vd-command

set(SOURCES_COMMAND
        src_command/src/main.cpp
        src_command/src/cmd_set.cpp
        src_command/src/cmd_get.cpp
)

add_executable(vd-command ${SOURCES_COMMAND})

target_include_directories(vd-command
        PRIVATE
        ${PROJECT_SOURCE_DIR}/src_command/inc
        ${PROJECT_SOURCE_DIR}/src_lib/inc
)

#Set defines for library
# set variable for the C preprocessor to detect the operating system
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(vd-command PRIVATE
            OS_LINUX
    )
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_definitions(vd-command PRIVATE
            OS_MAC
    )
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(vd-command PRIVATE
            OS_WIN
    )
endif()

target_link_libraries(vd-command libVisaDevices)

#------------------------
#vd-wfmdemp

set(SOURCES_WFMDMP
        src_wfmdmp/src/main.cpp
        src_wfmdmp/src/wfm_get.cpp
)

add_executable(vd-wmfdmp ${SOURCES_WFMDMP})

target_include_directories(vd-wmfdmp
        PRIVATE
        ${PROJECT_SOURCE_DIR}/src_wfmdmp/inc
        ${PROJECT_SOURCE_DIR}/src_lib/inc
)

#Set defines for library
# set variable for the C preprocessor to detect the operating system
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(vd-wmfdmp PRIVATE
            OS_LINUX
    )
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_definitions(vd-wmfdmp PRIVATE
            OS_MAC
    )
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(vd-wmfdmp PRIVATE
            OS_WIN
    )
endif()

target_link_libraries(vd-wmfdmp libVisaDevices)
