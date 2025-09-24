// Copyright 2024 Accenture.

#pragma once

#include "sci/SciDevice.h"

// Baud rate configurations for S32K3xx
// Using LPUART0 for console output
sciBaudRate const sciBaudRateConfig[] = {
    {(LPUART_BAUD_OSR(15)) + LPUART_BAUD_SBR(26)}, // = 115200 @ 48MHz FIRC
    {(LPUART_BAUD_OSR(9)) + LPUART_BAUD_SBR(8)}    // = 2MBit @ 80MHz PLL
};

SciConfig const sciConfiguration
    = {(LPUART0),
       bios::Io::UART0_TX,
       bios::Io::UART0_RX,
       static_cast<uint8_t>(sizeof(sciBaudRateConfig) / sizeof(sciBaudRate)),
       sciBaudRateConfig};
