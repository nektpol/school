@echo off
setlocal
set "JAVA_TOOL_OPTIONS="
set "JDK_DIR="
if defined JAVA_HOME if exist "%JAVA_HOME%\bin\javac.exe" set "JDK_DIR=%JAVA_HOME%"
if not defined JDK_DIR if exist "C:\Program Files\Java\jdk-27.0.1.0.2\bin\javac.exe" set "JDK_DIR=C:\Program Files\Java\jdk-27.0.1.0.2"
set "JAVAC=javac.exe"
set "JAVA=java.exe"
if defined JDK_DIR set "JAVAC=%JDK_DIR%\bin\javac.exe"
if defined JDK_DIR set "JAVA=%JDK_DIR%\bin\java.exe"
pushd "%~dp0"
if not exist "bin" mkdir "bin"
if exist "bin\sources.txt" del "bin\sources.txt"
for /r "src" %%F in (*.java) do call :addSource "%%F"
"%JAVAC%" --module-path "lib" --add-modules javafx.controls,javafx.fxml -d "bin" @bin\sources.txt
if errorlevel 1 goto failed
if /I "%~1"=="--compile-only" (
    echo Compilation passed.
    popd
    exit /b 0
)
"%JAVA%" --module-path "lib" -Djava.library.path="lib" --add-modules javafx.controls,javafx.fxml --enable-native-access=javafx.graphics -cp "bin" App
if errorlevel 1 goto failed
popd
exit /b 0
:failed
echo Build or launch failed. This template requires JDK 27 and the included JavaFX libraries.
popd
if /I not "%~1"=="--compile-only" pause
exit /b 1
:addSource
set "SOURCE_FILE=%~1"
echo "%SOURCE_FILE:\=/%">>"bin\sources.txt"
exit /b 0
