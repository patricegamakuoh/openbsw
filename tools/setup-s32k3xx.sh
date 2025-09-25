#!/bin/bash
# S32K3xx Development Environment Setup Script
# This script sets up the development environment for S32K312/S32K344

echo "Setting up S32K3xx development environment..."

# Set up CAN interface
echo "Setting up CAN interface..."
if command -v ip &> /dev/null; then
    if ip link show can0 | grep "state DOWN" > /dev/null; then
        sudo ip link set can0 up type can bitrate 500000
        echo "CAN0 interface configured for 500kbps"
    elif ip link show can0 | grep "state UP" > /dev/null; then
        echo "CAN0 interface already up"
    else
        echo "CAN0 interface not found - please set up CAN interface manually"
    fi
else
    echo "ip command not found - please set up CAN interface manually"
fi

# Check for required tools
echo "Checking for required tools..."

# Check for ARM GCC toolchain
if command -v arm-none-eabi-gcc &> /dev/null; then
    echo "✓ ARM GCC toolchain found: $(arm-none-eabi-gcc --version | head -n1)"
else
    echo "✗ ARM GCC toolchain not found - please install ARM GNU Toolchain"
fi

# Check for GDB
if command -v arm-none-eabi-gdb &> /dev/null; then
    echo "✓ ARM GDB found: $(arm-none-eabi-gdb --version | head -n1)"
else
    echo "✗ ARM GDB not found - please install ARM GNU Toolchain"
fi

# Check for CMake
if command -v cmake &> /dev/null; then
    echo "✓ CMake found: $(cmake --version | head -n1)"
else
    echo "✗ CMake not found - please install CMake"
fi

# Check for Python and pytest
if command -v python3 &> /dev/null; then
    echo "✓ Python3 found: $(python3 --version)"
    if python3 -c "import pytest" &> /dev/null; then
        echo "✓ pytest found"
    else
        echo "✗ pytest not found - run: pip install -r test/pyTest/requirements.txt"
    fi
else
    echo "✗ Python3 not found - please install Python 3"
fi

# Check for P&E Micro gdbserver
if command -v pegdbserver_console &> /dev/null; then
    echo "✓ P&E Micro gdbserver found"
else
    echo "✗ P&E Micro gdbserver not found - please install P&E Micro tools"
fi

echo ""
echo "S32K3xx development environment setup complete!"
echo ""
echo "Next steps:"
echo "1. Build for S32K312: cmake -DOPENBSW_PLATFORM=s32k3xx -DCPU_S32K312=1 .."
echo "2. Build for S32K344: cmake -DOPENBSW_PLATFORM=s32k3xx -DCPU_S32K344=1 .."
echo "3. Start gdbserver: sudo pegdbserver_console -startserver -device=NXP_S32K3xx_S32K312F2M0M11"
echo "4. Run tests: pytest --target=s32k312"
