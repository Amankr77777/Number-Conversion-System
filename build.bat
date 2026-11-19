@echo off
setlocal enabledelayedexpansion

echo ===============================================================================
echo            BUILDING NUMBER SYSTEM CONVERSION USING C++
echo ===============================================================================

if not exist bin mkdir bin

echo [1/2] Compiling Standalone NumberSystemConverter.cpp ...
g++ -std=c++11 -O2 -Wall NumberSystemConverter.cpp -o NumberSystemConverter.exe
if %ERRORLEVEL% EQU 0 (
    echo   -^> SUCCESS: NumberSystemConverter.exe generated successfully!
    copy NumberSystemConverter.exe bin\NumberSystemConverter.exe > nul 2>&1
) else (
    echo   -^> [WARNING] Standalone compilation failed. Check your compiler path.
)

echo [2/2] Compiling Modular Multi-File Suite ...
g++ -std=c++14 -O2 -Wall -Iinclude ^
    src\Utils.cpp ^
    src\BaseConverter.cpp ^
    src\FractionalConverter.cpp ^
    src\BigIntConverter.cpp ^
    src\SignedRepresentation.cpp ^
    src\IEEE754Converter.cpp ^
    src\SpecialCodes.cpp ^
    src\BaseArithmetic.cpp ^
    src\StepExplainer.cpp ^
    src\TestSuite.cpp ^
    src\Menu.cpp ^
    src\main.cpp ^
    -o bin\NumberConverter.exe

if %ERRORLEVEL% EQU 0 (
    echo   -^> SUCCESS: bin\NumberConverter.exe generated successfully!
    copy bin\NumberConverter.exe NumberConverter.exe > nul 2>&1
    echo   -^> Copied to NumberConverter.exe in root directory.
) else (
    echo   -^> [WARNING] Modular suite compilation encountered an issue.
)

echo ===============================================================================
echo Build process finished!
echo Run 'run.bat' or double-click 'NumberSystemConverter.exe' to start.
echo ===============================================================================
