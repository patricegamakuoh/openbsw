.. _s32k3xx_overview:

S32K3xx Evaluation Boards
=========================

Overview
--------

- The S32K3xx family of microcontrollers from NXP Semiconductors is designed for automotive and industrial applications, featuring ARM Cortex-M7 cores with advanced peripherals and safety features.
- Eclipse OpenBSW provides reference applications for S32K312 and S32K344 platforms which can be built
  out-of-the-box and flashed onto evaluation boards, enabling users to test working features
  straight away, thus immediately providing a starting point for further development and learning.

Supported Devices
-----------------

- **S32K312**: Entry-level device with 256KB Flash, 32KB SRAM, Cortex-M7 @ 80MHz
- **S32K344**: Mid-range device with 1MB Flash, 128KB SRAM, Cortex-M7 @ 80MHz

Reference Links
---------------

1. **S32K3xx Evaluation Board Product Pages**:
    - `S32K3xx Evaluation Board <https://www.nxp.com/design/development-boards/s32k3xx-evaluation-board:S32K3XXEVB>`_

2. **S32K3xx Evaluation Board Documentation**:
    - `User Manual: S32K3xx Evaluation Board User Manual (login required) <https://www.nxp.com/webapp/Download?colCode=S32K3XX-UM>`_
    - `Quick Start Guide: S32K3xx Evaluation Board Quick Start Guide <https://www.nxp.com/document/guide/getting-started-with-the-s32k3xx-evaluation-board:NGS-S32K3XXEVB>`_

3. **S32K3xx MCU Documentation**:
    - `Reference Manual: S32K3xx Reference Manual (login required) <https://www.nxp.com/webapp/Download?colCode=S32K3XXRM>`_
    - `Data Sheet: S32K3xx Data Sheet <https://www.nxp.com/docs/en/data-sheet/S32K3xx.pdf>`_

4. **S32K3xx Software and Tools**:
    - `S32 Design Studio for ARM <https://www.nxp.com/design/design-center/software/development-software/s32-design-studio-ide/s32-design-studio-for-arm:S32DS-ARM>`_
    - `S32K3xx SDK <https://www.nxp.com/design/software/development-software/s32k3xx-development-package:S32K3XX-DP>`_

5. **Development Tools**:
    - `P&E Micro Debugger <https://www.pemicro.com/products/viewproducts.cfm?producttype=debugger&productsubtype=multilink>`_
    - `ARM GNU Toolchain <https://developer.arm.com/downloads/-/gnu-rm>`_

Hardware Features
-----------------

- **Processor**: ARM Cortex-M7 @ 80MHz
- **Memory**: 
  - S32K312: 256KB Flash, 32KB SRAM
  - S32K344: 1MB Flash, 128KB SRAM
- **Peripherals**:
  - Multiple LPUART interfaces for console communication
  - FLEXCAN interfaces for CAN communication
  - ADC channels for analog input
  - FTM modules for PWM output
  - GPIO pins for digital I/O
  - Watchdog timer
  - Real-time clock

Software Features
-----------------

- **Real-time Operating System**: FreeRTOS with Cortex-M7 port
- **Console Interface**: UART-based console for debugging and diagnostics
- **CAN Communication**: Support for CAN 2.0A/B protocols
- **Logging System**: Comprehensive logging with different severity levels
- **Lifecycle Management**: Application startup and shutdown management
- **Safety Features**: Watchdog timer and memory protection

Getting Started
---------------

1. **Hardware Setup**:
   - Connect the S32K3xx evaluation board to your computer via USB
   - Connect a debugger (P&E Micro or compatible) to the debug connector
   - Connect a serial terminal to the UART interface for console output

2. **Software Setup**:
   - Install ARM GNU Toolchain
   - Install P&E Micro debugger software
   - Clone the OpenBSW repository
   - Build the reference application for your target device

3. **Building and Flashing**:
   - For S32K312: ``cmake -DOPENBSW_PLATFORM=s32k3xx -DCPU_S32K312=1 ..``
   - For S32K344: ``cmake -DOPENBSW_PLATFORM=s32k3xx -DCPU_S32K344=1 ..``
   - Build: ``cmake --build . --target app.referenceApp``
   - Flash using your preferred debugger

4. **Testing**:
   - Run pytest tests: ``pytest --target=s32k312`` or ``pytest --target=s32k344``
   - Use the console interface for interactive testing
   - Monitor CAN communication using appropriate tools

Troubleshooting
---------------

- **Build Issues**: Ensure ARM GNU Toolchain is properly installed and in PATH
- **Debugging Issues**: Verify P&E Micro debugger connection and configuration
- **Console Issues**: Check UART baud rate and pin configuration
- **CAN Issues**: Verify CAN transceiver and termination resistors

For more detailed information, see the platform-specific documentation in the ``platforms/s32k3xx/`` directory.
