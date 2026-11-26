@echo off
setlocal
set "JAVA_TOOL_OPTIONS="
set "JDK_DIR="
if exist "C:\Program Files\Java\jdk-27.0.1.0.2\bin\javac.exe" set "JDK_DIR=C:\Program Files\Java\jdk-27.0.1.0.2"
if not defined JDK_DIR if defined JAVA_HOME if exist "%JAVA_HOME%\bin\javac.exe" set "JDK_DIR=%JAVA_HOME%"
set "JAVAC=javac.exe"
set "JAVA=java.exe"
if defined JDK_DIR set "JAVAC=%JDK_DIR%\bin\javac.exe"
if defined JDK_DIR set "JAVA=%JDK_DIR%\bin\java.exe"
pushd "%~dp0"
if not exist "bin" mkdir "bin"
if exist "bin\sources.txt" del "bin\sources.txt"
for /r "src" %%F in (*.java) do call :addSource "%%F"
"%JAVAC%" -encoding UTF-8 --module-path "lib" --add-modules javafx.controls,javafx.fxml -d "bin" @bin\sources.txt
if errorlevel 1 goto compile_failed
xcopy "src\polyzos\*.fxml" "bin\polyzos\" /Y /Q >nul
if errorlevel 1 goto compile_failed
if /I "%~1"=="--compile-only" (
    echo Compilation passed.
    popd
    exit /b 0
)
"%JAVA%" --module-path "lib" -Djava.library.path="lib" -Dprism.order=sw --add-modules javafx.controls,javafx.fxml --enable-native-access=javafx.graphics -cp "bin" polyzos.Main
if errorlevel 1 goto launch_failed
popd
exit /b 0
:compile_failed
echo Compilation failed. Check the Java compiler errors above.
popd
if /I not "%~1"=="--compile-only" pause
exit /b 1
:launch_failed
echo JavaFX launch failed. JDK 27 and the JavaFX libraries were found, but the graphics pipeline could not start.
echo Try running from the VS Code desktop window, not a headless or Remote Desktop session.
popd
if /I not "%~1"=="--compile-only" pause
exit /b 1
:addSource
set "SOURCE_FILE=%~1"
echo "%SOURCE_FILE:\=/%">>"bin\sources.txt"
exit /b 0
