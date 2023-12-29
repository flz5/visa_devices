# VisaDevices

VisaDevices is a plattform independend library to control different lab instrument through the standardized VISA interface. It is written in C++ and designed as a shared library. To make the usage in different programming languages easier the interface is reduced to a standard C interface.

**Included applications:**

*wfmdmp:*
A simple programm to transfer waveform data from a device to a file.

*command:*
Allows the execution of simple commands via the library from the terminal.

*curvetrace:*
Controls multiple devices to set device parameters and measure data.

**Note:** The project is under work and at the moment not finished. This means:

- Many of the device drivers are not complete or tested to work properly.
- Inputs are not validated
- The API may change

## Releases (Versioning scheme)

The project uses semantic versioning.
The Release contains binary files for the plattforms and a documentation.

## Folder structure

| folder        | description                                                   |
| ------------- | ------------------------------------------------------------- |
| build         | output for compiled programmes                                |
| build_temp    | temporary folder                                              |
| doc           | documentation                                                 |
| examples      | programming examples                                          |
| src           | source code of the project                                    |
| wrapper       | wrapper for use in other programming languages                |

## Building the project

The project uses the CMake build system with C++11 standard. 
The VISA library has to be installed (64bit version) and the path have to be edited according to the specific installation directory. The default installation directories are listed under the plattform dependend sections.

### Defines

| Define        | Description                                                   |
|-------------- | ------------------------------------------------------------- |
| OS_WIN        | Build for Windows plattform                                   |
| OS_LINUX      | Build for Linux plattform                                     |
| OS_MAC        | Build for MacOS plattform                                     |
| LIB_EXPORT    | Configures the Headers files for compilation of the library   |


## Wrapper

### Python

```
cd wrapper/python/
pip wheel . -w wheels
```

## Documentation

The documentation can be found in the folder "/doc". 
It is generated with MKDocs (Python), which can be installed using PIP.

```
pip install mkdocs
pip install mkdocs-material
```

To build the documentation one of the following commands (inside the doc folder) can be used:
```
mkdocs build
mkdocs serve
```

## Add a device

- **Clone the source code.** 
- **Create a new source file.** 
        Source files for devices are located under
        "sourcecode\src_lib\src\devices", the header files under
        "sourcecode\src_lib\inc\devices". The dummy drivers can be used as a
        model for the new file. 
- **Add entry to array and create a device ID**
        Add a pointer to the array of the generic driver, for which the device can be used. 
        ("sourcecode\src_lib\src\generic").
        The device ids are the position in the array and are listed in 
        "sourcecode\src_lib\inc\generic\generic_id.h".
- **Create a merge request**
        It is possible that the ids change during the merge.

## License

The software is licensed under the **LGPL V3** opensource license.