@echo off
setlocal
 tasklist /FI "IMAGENAME eq Code.exe" /NH 2>nul | find /I "Code.exe" >nul
if not errorlevel 1 (
    echo Please close ALL Visual Studio Code windows first, then run this file again.
    echo VS Code must fully exit so it can receive the corrected Java environment.
    pause
    exit /b 1
)
set "JAVA_TOOL_OPTIONS="
start "" "C:\Program Files\Microsoft VS Code\Code.exe" --new-window "C:\school\C Eksamino\JavaFX\TestJava"
endlocal
