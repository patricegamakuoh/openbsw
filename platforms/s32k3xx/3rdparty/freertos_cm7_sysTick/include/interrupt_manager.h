/*
 * FreeRTOS Kernel V10.6.2
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

#ifndef INTERRUPT_MANAGER_H
    #define INTERRUPT_MANAGER_H

/* *INDENT-OFF* */
#ifdef __cplusplus
    extern "C" {
#endif
/* *INDENT-ON* */

/*-----------------------------------------------------------
 * Port specific definitions.
 *
 * The settings in this file configure FreeRTOS correctly for the
 * given hardware and compiler.
 *
 * These settings should not be altered.
 *-----------------------------------------------------------
 */

/* Scheduler includes. */
    #include "FreeRTOS.h"
    #include "task.h"

    #ifdef __cplusplus
        extern "C" {
    #endif

/*-----------------------------------------------------------*/

/* Interrupt nesting behaviour configuration. Cortex-M7 specific. */
    #define configINTERRUPT_CONTROLLER_BASE_ADDRESS     ( 0xe000e000UL )
    #define configINTERRUPT_CONTROLLER_CPU_INTERFACE_OFFSET ( 0xd00UL )
    #define configINTERRUPT_CONTROLLER_CPU_INTERFACE_ADDRESS ( configINTERRUPT_CONTROLLER_BASE_ADDRESS + configINTERRUPT_CONTROLLER_CPU_INTERFACE_OFFSET )

/*-----------------------------------------------------------*/

/* Constants required to manipulate the NVIC. */
    #define portNVIC_SYSTICK_CTRL_REG                  ( *( ( volatile uint32_t * ) 0xe000e010 ) )
    #define portNVIC_SYSTICK_LOAD_REG                  ( *( ( volatile uint32_t * ) 0xe000e014 ) )
    #define portNVIC_SYSTICK_CURRENT_VALUE_REG         ( *( ( volatile uint32_t * ) 0xe000e018 ) )
    #define portNVIC_SYSPRI2_REG                       ( *( ( volatile uint32_t * ) 0xe000ed20 ) )
    #define portNVIC_SYSPRI3_REG                       ( *( ( volatile uint32_t * ) 0xe000ed20 ) )
    #define portNVIC_SYSHNDLER_CTRL_REG                ( *( ( volatile uint32_t * ) 0xe000ed24 ) )
    #define portNVIC_PENDSV_PRI                        ( ( ( uint32_t ) configKERNEL_INTERRUPT_PRIORITY ) << 16UL )
    #define portNVIC_SYSTICK_PRI                       ( ( ( uint32_t ) configKERNEL_INTERRUPT_PRIORITY ) << 24UL )

/* Constants required to set up the initial stack. */
    #define portINITIAL_XPSR                           ( 0x01000000 )

/* The system clock is the frequency of the SysTick. */
    #define portSYSTICK_CLOCK_HZ                       configSYSTICK_CLOCK_HZ
    #define portSYSTICK_INTERRUPT_PRIORITY             ( configKERNEL_INTERRUPT_PRIORITY << ( 8 - configPRIO_BITS ) )

/*-----------------------------------------------------------*/

/* Each task maintains its own interrupt status in the critical nesting
 * variable. */
    static UBaseType_t uxCriticalNesting = 0xaaaaaaaa;

/*-----------------------------------------------------------*/

/* The number of SysTick increments that make up one tick period. */
    #if ( configUSE_TICKLESS_IDLE == 1 )
        static uint32_t ulTimerCountsForOneTick = 0;
    #endif /* configUSE_TICKLESS_IDLE */

/* The maximum number of tick periods that can be suppressed is limited by the
 * 24 bit resolution of the SysTick timer. */
    #if ( configUSE_TICKLESS_IDLE == 1 )
        static uint32_t xMaximumPossibleSuppressedTicks = 0;
    #endif /* configUSE_TICKLESS_IDLE */

/*-----------------------------------------------------------*/

/*-----------------------------------------------------------*/

/* *INDENT-OFF* */
#ifdef __cplusplus
    }
#endif
/* *INDENT-ON* */

#endif /* INTERRUPT_MANAGER_H */
