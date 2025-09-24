/*
 * Copyright (c) 2009-2021 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __CORE_CM7_H_GENERIC
    #define __CORE_CM7_H_GENERIC

    #include <stdint.h>

    #ifdef __cplusplus
        extern "C" {
    #endif

    /* ##########################  Core Function Access  ########################### */
    /** \ingroup  CMSIS_Core_FunctionInterface
      \defgroup  CMSIS_Core_RegAccFunctions CMSIS Core Register Access Functions
      @{
    */

    /**
      \brief   Enable IRQ Interrupts
      \details Enables IRQ interrupts by clearing the I-bit in the CPSR.
               Can only be executed in Privileged modes.
    */
    __attribute__( ( always_inline ) ) __STATIC_INLINE void __enable_irq( void )
    {
        __ASM volatile ( "cpsie i" : : : "memory" );
    }


    /**
      \brief   Disable IRQ Interrupts
      \details Disables IRQ interrupts by setting the I-bit in the CPSR.
               Can only be executed in Privileged modes.
    */
    __attribute__( ( always_inline ) ) __STATIC_INLINE void __disable_irq( void )
    {
        __ASM volatile ( "cpsid i" : : : "memory" );
    }

    /**
      \brief   Get Main Stack Pointer
      \details Returns the current value of the Main Stack Pointer (MSP).
      \return               MSP Register value
    */
    __attribute__( ( always_inline ) ) __STATIC_INLINE uint32_t __get_MSP( void )
    {
        register uint32_t result;

        __ASM volatile ( "mrs %0, msp\n" : "=r" ( result ) );
        return ( result );
    }


    /**
      \brief   Set Main Stack Pointer
      \details Assigns the value to the Main Stack Pointer (MSP).
      \param [in]    topOfMainStack  Main Stack Pointer value to set
    */
    __attribute__( ( always_inline ) ) __STATIC_INLINE void __set_MSP( uint32_t topOfMainStack )
    {
        __ASM volatile ( "msr msp, %0\n" : : "r" ( topOfMainStack ) : "sp" );
    }


    /**
      \brief   Get Priority Mask
      \details Returns the current state of the priority mask bit from the Priority Mask Register.
      \return               Priority Mask value
    */
    __attribute__( ( always_inline ) ) __STATIC_INLINE uint32_t __get_PRIMASK( void )
    {
        uint32_t result;

        __ASM volatile ( "mrs %0, primask" : "=r" ( result ) );
        return ( result );
    }


    /**
      \brief   Set Priority Mask
      \details Assigns the given value to the Priority Mask Register.
      \param [in]    priMask  Priority Mask
    */
    __attribute__( ( always_inline ) ) __STATIC_INLINE void __set_PRIMASK( uint32_t priMask )
    {
        __ASM volatile ( "msr primask, %0" : : "r" ( priMask ) : "memory" );
    }

    #ifdef __cplusplus
    }
    #endif

#endif /* __CORE_CM7_H_GENERIC */
