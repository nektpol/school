# JavaFX starter

Based on TestJava. Requires JDK 27 on Windows; JavaFX 27.0.1 is included in `lib` with its native DLLs.

- Double-click `Open-Project.cmd` to open this folder in VS Code. Close all existing VS Code windows first. Wait for Java to activate, then press F5 and select Launch Java Program.
- Double-click `Run-Project.cmd` to compile and run without VS Code.
- Edit `src/App.java`. Compiled classes go in `bin`.

The launchers clear the broken global `JAVA_TOOL_OPTIONS` value only for their own process. They do not change Windows environment settings.

For a different JDK location, set JAVA_HOME to a compatible JDK 27 installation. No JSON editing is necessary for a new project folder or name.

The original TestJava VS Code JSON files are preserved. SDK license notices are in `legal` and `LICENSE`.
