@echo off
setlocal
tasklist /FI "IMAGENAME eq Code.exe" /NH 2>nul | find /I "Code.exe" >nul
if not errorlevel 1 (
    echo Close ALL Visual Studio Code windows, then run this file again.
    echo VS Code must fully exit to receive the clean Java environment.
    pause
    exit /b 1
)
set "JAVA_TOOL_OPTIONS="
if exist "%ProgramFiles%\Microsoft VS Code\Code.exe" (
    start "" "%ProgramFiles%\Microsoft VS Code\Code.exe" --new-window "%~dp0."
    exit /b 0
)
if exist "%LocalAppData%\Programs\Microsoft VS Code\Code.exe" (
    start "" "%LocalAppData%\Programs\Microsoft VS Code\Code.exe" --new-window "%~dp0."
    exit /b 0
)
where code.cmd >nul 2>nul
if not errorlevel 1 (
    call code.cmd --new-window "%~dp0."
    exit /b
)
echo Visual Studio Code was not found. Open this folder in VS Code manually.
pause
exit /b 1
