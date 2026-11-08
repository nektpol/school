@echo off
setlocal
set "JAVAFX_CREATOR_DIR=%~dp0"
set "JAVAFX_PROJECT_NAME="
echo Create a JavaFX project beside this CMD file.
echo.
set /p "JAVAFX_PROJECT_NAME=Project name: "
powershell.exe -NoProfile -ExecutionPolicy Bypass -Command "$ErrorActionPreference = 'Stop'; try { $name = $env:JAVAFX_PROJECT_NAME; if ([string]::IsNullOrWhiteSpace($name)) { throw 'Enter a project name.' }; if ($name -ne $name.Trim() -or $name.EndsWith('.') -or $name.IndexOfAny([IO.Path]::GetInvalidFileNameChars()) -ge 0 -or $name -eq '.' -or $name -eq '..' -or $name -match '^(CON|PRN|AUX|NUL|COM[0-9]|LPT[0-9])([.]|$)') { throw 'Use a valid Windows folder name, without slashes or trailing dots/spaces.' }; $template = Join-Path $env:JAVAFX_CREATOR_DIR 'JavaFX-Template'; if (-not (Test-Path -LiteralPath (Join-Path $template 'src\App.java'))) { throw 'Place the JavaFX-Template folder beside this CMD file. It must contain src\App.java, lib, and .vscode.' }; foreach ($required in 'lib\javafx.controls.jar','lib\glass.dll','.vscode\launch.json','.vscode\settings.json','Open-Project.cmd','Run-Project.cmd') { if (-not (Test-Path -LiteralPath (Join-Path $template $required))) { throw ('Template is missing: ' + $required) } }; $target = Join-Path $env:JAVAFX_CREATOR_DIR $name; if (Test-Path -LiteralPath $target) { throw ('Destination already exists: ' + $target) }; New-Item -ItemType Directory -Path $target | Out-Null; Get-ChildItem -LiteralPath $template -Force | Copy-Item -Destination $target -Recurse; New-Item -ItemType Directory -Path (Join-Path $target 'bin') -Force | Out-Null; Write-Host ('Created JavaFX project: ' + $target); Write-Host ''; Write-Host 'Ready. Open the new folder and double-click Open-Project.cmd or Run-Project.cmd.'; exit 0 } catch { Write-Host ('ERROR: ' + $_.Exception.Message); exit 1 }"
if errorlevel 1 (
    echo.
    echo Project creation failed. Existing projects are never overwritten.
    pause
    exit /b 1
)
echo.
pause
exit /b 0
