# S32K3xx Development Environment Setup Script (PowerShell)
# This script sets up the development environment for S32K312/S32K344

Write-Host "Setting up S32K3xx development environment..." -ForegroundColor Green

# Check for required tools
Write-Host "Checking for required tools..." -ForegroundColor Yellow

# Check for ARM GCC toolchain
try {
    $gccVersion = & arm-none-eabi-gcc --version 2>$null | Select-Object -First 1
    if ($gccVersion) {
        Write-Host "✓ ARM GCC toolchain found: $gccVersion" -ForegroundColor Green
    } else {
        Write-Host "✗ ARM GCC toolchain not found - please install ARM GNU Toolchain" -ForegroundColor Red
    }
} catch {
    Write-Host "✗ ARM GCC toolchain not found - please install ARM GNU Toolchain" -ForegroundColor Red
}

# Check for GDB
try {
    $gdbVersion = & arm-none-eabi-gdb --version 2>$null | Select-Object -First 1
    if ($gdbVersion) {
        Write-Host "✓ ARM GDB found: $gdbVersion" -ForegroundColor Green
    } else {
        Write-Host "✗ ARM GDB not found - please install ARM GNU Toolchain" -ForegroundColor Red
    }
} catch {
    Write-Host "✗ ARM GDB not found - please install ARM GNU Toolchain" -ForegroundColor Red
}

# Check for CMake
try {
    $cmakeVersion = & cmake --version 2>$null | Select-Object -First 1
    if ($cmakeVersion) {
        Write-Host "✓ CMake found: $cmakeVersion" -ForegroundColor Green
    } else {
        Write-Host "✗ CMake not found - please install CMake" -ForegroundColor Red
    }
} catch {
    Write-Host "✗ CMake not found - please install CMake" -ForegroundColor Red
}

# Check for Python and pytest
try {
    $pythonVersion = & python --version 2>$null
    if ($pythonVersion) {
        Write-Host "✓ Python found: $pythonVersion" -ForegroundColor Green
        try {
            & python -c "import pytest" 2>$null
            Write-Host "✓ pytest found" -ForegroundColor Green
        } catch {
            Write-Host "✗ pytest not found - run: pip install -r test/pyTest/requirements.txt" -ForegroundColor Red
        }
    } else {
        Write-Host "✗ Python not found - please install Python 3" -ForegroundColor Red
    }
} catch {
    Write-Host "✗ Python not found - please install Python 3" -ForegroundColor Red
}

Write-Host ""
Write-Host "S32K3xx development environment setup complete!" -ForegroundColor Green
Write-Host ""
Write-Host "Next steps:" -ForegroundColor Yellow
Write-Host "1. Build for S32K312: cmake -DOPENBSW_PLATFORM=s32k3xx -DCPU_S32K312=1 .."
Write-Host "2. Build for S32K344: cmake -DOPENBSW_PLATFORM=s32k3xx -DCPU_S32K344=1 .."
Write-Host "3. Start gdbserver: pegdbserver_console -startserver -device=NXP_S32K3xx_S32K312F2M0M11"
Write-Host "4. Run tests: pytest --target=s32k312"
