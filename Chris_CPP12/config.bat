mkdir build

REM ***** PC  *******

mkdir build
cd build
cmake -G "Visual Studio 14" "%CURRENT_DIR%" ..
cd "%CURRENT_DIR%"

