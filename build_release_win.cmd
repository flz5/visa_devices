mkdir build
cd build
mkdir cmake
cd cmake

cmake -G "Visual Studio 17 2022" ..\..\sourcecode\

cd ..
cd ..
cmake -S sourcecode -B build\cmake
cmake --build build\cmake

cd build
mkdir bin
mkdir lib
cd ..

xcopy build\cmake\bin\Debug build\bin
xcopy build\cmake\lib\Debug build\lib

mkdir release
xcopy sourcecode\src_lib\inc build\inc /E /I
cd build
tar.exe -a -c -f ..\release\libVisaDevices_win.zip bin lib inc

cd ..
cd doc
mkdocs build
tar.exe -a -c -f ..\release\libVisaDevices_doc.zip site

cd ..
cd wrapper/python/
pip wheel . -w ..\..\release
rmdir build

cd ..
cd ..
cd examples
tar.exe -a -c -f ..\release\libVisaDevices_examples.zip c matlab python

cd ..

