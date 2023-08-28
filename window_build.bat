@ECHO OFF
@REM cmake -G "MinGW Makefiles" -S . -B bin/debug/
cmake --build bin/debug/ && start /b bin/debug/SDL2_Template.exe