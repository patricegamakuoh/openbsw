# Visual Studio Code settings

This directory contains example settings files for Visual Studio Code
based on the setup described in ``doc/learning/setup/setup_vscode.rst``.
Assuming you have opened Visual Studio Code from the base of the code (let's call this ``[WORKSPACE_DIR]``),
then Visual Studio Code will look for settings files in ``[WORKSPACE_DIR]/.vscode/``.

Files in the subdirectory ``tools/vscode/dot_vscode/`` can be copied to ``[WORKSPACE_DIR]/.vscode/``
but note that these files will need to be adjusted depending on your local setup.
For example, ``settings.json`` has settings for the 
[Cortex-Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug)
extension including where to find the ARM Toolchain...
```
"cortex-debug.armToolchainPath": "/home/username/gcc-arm-none-eabi-10.3-2021.10/bin/"
```
so this needs to be adjusted for your local setup if you wish to use this extension.

Similarly, if you wish to use the
[CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
extension then
``tools/vscode/executables/referenceApp/CMakePresets.json`` can be copied to ``executables/referenceApp/CMakePresets.json``

## Supported Platforms

The VS Code configuration supports the following platforms:

- **posix**: Linux/Unix simulation environment
- **s32k148**: S32K148 evaluation board (S32K1xx family)
- **s32k312**: S32K312 evaluation board (S32K3xx family) 
- **s32k344**: S32K344 evaluation board (S32K3xx family)

### S32K3xx Platform Support

For S32K3xx platforms (s32k312, s32k344), the configuration includes:

- **IntelliSense**: ARM GCC configuration for Cortex-M7
- **Debugging**: Cortex-Debug extension support with P&E Micro gdbserver
- **CMake Presets**: Pre-configured build presets for S32K3xx
- **Compile Commands**: Automatic generation for code completion

### Usage

1. Copy the configuration files to your workspace `.vscode/` directory
2. Adjust toolchain paths in `settings.json` for your local setup
3. Select the appropriate platform configuration in VS Code
4. Use CMake presets to build for your target platform
5. Use the debug configurations to debug on hardware