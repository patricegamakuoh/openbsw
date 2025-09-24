# S32K3xx Platform Configuration
# Target: S32K312/S32K344 with Cortex-M7

# Platform-specific compiler definitions
add_compile_definitions(
    S32K3XX
    CORE_M7
    CPU_S32K312  # or CPU_S32K344 depending on target
    BSP_IO_PIN_CONFIGURATION=1
)

# Platform-specific compiler flags
add_compile_options(
    -mcpu=cortex-m7
    -mthumb
    -mfpu=fpv5-d16
    -mfloat-abi=hard
    -ffunction-sections
    -fdata-sections
)

# 3rdparty modules
add_subdirectory(3rdparty/freertos_cm7_sysTick)

# BSP modules
add_subdirectory(bsp)

# Other modules
add_subdirectory(hardFaultHandler)
