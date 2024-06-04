# TSM_PicoW_Sensor
Project using the PicoW board with VS Code, implementing a sensor application.

## McuLib
The project uses the McuLib. The location of the library is specified with the variable 'MCULIB_DIR' in the top-level CMakeLists.txt. The McuLib can be shared with multiple projects.

## Environment
In order for this project to work, the Rasperry Pi Pico SDK needs to be installed and shall have set two environment variables as below (example below for Windows):
```
PICO_SDK_PATH=C:\Raspy\pico\pico-sdk
PICO_TOOLCHAIN_PATH=C:\Raspy\arm-none-eabi-gcc-12.2.1-1.2\bin
```
Additionally, the launch config uses a variable pointing to the SEGGER installation, example below for windows:
```
SEGGER_PATH=C:/Program Files/SEGGER/JLink
```
The variables can be set on user level.

## Unit Tests
Enable 'PL_CONFIG_USE_UNIT_TESTS' in platform.h

Run JRun manually:
```
"c:\Program Files\SEGGER\JLink\JRun.exe" --device RP2040_M0_0 -if SWD build/debug-test/TSM_PicoW_Sensor.elf
"c:\Program Files\SEGGER\JLink\JRun.exe" --device RP2040_M0_0 -if SWD --jlinkscriptfile test.JLinkScript build/debug-test/TSM_PicoW_Sensor.elf
```
CTest: add the following in the main CMakeLists.txt:
```
enable_testing()
add_test(NAME ${CMAKE_PROJECT_NAME} COMMAND JRun.exe)
```
Manual test run:
```
ctest -v --test-dir build/debug-test --timeout 120 --output-on-failure --verbose
```
https://coderefinery.github.io/cmake-workshop/testing/
ctest -v (verbose)

## gcov
Compile files with
```
add_compile_options(--coverage)
```
(check CMakeLists.txt)

https://jhbell.com/using-cmake-and-gcov
https://marketplace.visualstudio.com/items?itemName=JacquesLucke.gcov-viewer

gcov extension
F1: gcov viewer: show
gcov needs to be in the path, and at least version 9 ==> edit settings, gcov binary

gcovr
https://gcovr.com
pip install gcovr

Make sure gcov of toolchain is in path! Rename binary to gcov.exe

Run gcovr in root of project:
gcovr .   => text report
gcovr --html-details -o ./coverage/main.html

\\ GCOVR_EXCL_LINE
\\ GCOVR_EXCL_START
\\ GCOVR_EXCL_STOP

McuRdimon_CONFIG_IS_ENABLED

## GNU profiling
add 'gprof' folder
add gprof library
add -pg compiler option for files to be profiled



