# PowerShell Runner for Number System Conversion Using C++
if (Test-Path ".\NumberSystemConverter.exe") {
    & ".\NumberSystemConverter.exe" $args
} elseif (Test-Path ".\NumberConverter.exe") {
    & ".\NumberConverter.exe" $args
} else {
    Write-Host "Binaries not found. Building with build.bat..." -ForegroundColor Yellow
    cmd /c .\build.bat
    if (Test-Path ".\NumberSystemConverter.exe") {
        & ".\NumberSystemConverter.exe" $args
    }
}
