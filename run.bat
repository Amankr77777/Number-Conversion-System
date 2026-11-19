@echo off
setlocal
cd /d "%~dp0"

if not exist NumberSystemConverter.exe (
    if exist bin\NumberSystemConverter.exe (
        copy bin\NumberSystemConverter.exe NumberSystemConverter.exe > nul
    ) else if exist NumberConverter.exe (
        NumberConverter.exe %*
        exit /b %ERRORLEVEL%
    ) else (
        echo Binaries not found. Building first...
        call build.bat
    )
)

if exist NumberSystemConverter.exe (
    NumberSystemConverter.exe %*
) else (
    echo [ERROR] Could not find or build NumberSystemConverter.exe.
    pause
)
