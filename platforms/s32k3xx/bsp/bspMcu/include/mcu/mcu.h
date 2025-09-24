// Copyright 2024 Accenture.

#pragma once

// Include S32K3xx RTD headers - adjust path based on your RTD installation
// This assumes the RTD is installed at the path you provided
#include "S32K312.h"  // or S32K344.h depending on your target
#if defined(__MPU_PRESENT) && (__MPU_PRESENT == 1U)
// NXP has their own MPU, so we must not use the cmsis one.
#undef __MPU_PRESENT
#define INCLUDE_CORE_CM7_IN_MCU_H
#include "3rdparty/cmsis/core_cm7.h"
#undef INCLUDE_CORE_CM7_IN_MCU_H
#define __MPU_PRESENT 1
#else
#include "mcu/core_cm7.h"
#endif /* defined (__MPU_PRESENT) && (__MPU_PRESENT == 1U) */
#include "mcu/typedefs.h"

// interrupt locking and nvic info used by freertos cm7 systick
#define ENABLE_INTERRUPTS()  __enable_irq()
#define DISABLE_INTERRUPTS() __disable_irq()

#define FEATURE_NVIC_PRIO_BITS (4U)

// watchdog magic values
#define FEATURE_WDOG_UNLOCK_VALUE  (0xD928C520U)
#define FEATURE_WDOG_TRIGGER_VALUE (0xB480A602U)

// FIRCERR bit mask not defined in S32K148 header file
#define SCG_FIRCCSR_FIRCERR_MASK 0x4000000u

// IP/device remapping for S32K3xx, extend as needed
#define LMEM           IP_LMEM
#define WDOG           IP_WDOG
#define LPUART0        IP_LPUART0
#define LPUART1        IP_LPUART1
#define LPUART2        IP_LPUART2
#define LPUART3        IP_LPUART3
#define LPIT0          IP_LPIT0
#define ADC0           IP_ADC0
#define ADC1           IP_ADC1
#define FLEXCAN0       IP_FLEXCAN0
#define FLEXCAN1       IP_FLEXCAN1
#define FLEXCAN2       IP_FLEXCAN2
#define FTM0           IP_FTM0
#define FTM1           IP_FTM1
#define FTM2           IP_FTM2
#define FTM3           IP_FTM3
#define FTM4           IP_FTM4
#define FTM5           IP_FTM5
#define FTM6           IP_FTM6
#define FTM7           IP_FTM7
#define SIM            IP_SIM
#define RCM            IP_RCM
#define SCG            IP_SCG
#define PCC            IP_PCC
#define GPIO_BASE_PTRS IP_GPIO_BASE_PTRS
#define PORT_BASE_PTRS IP_PORT_BASE_PTRS
