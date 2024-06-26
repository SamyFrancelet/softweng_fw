/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuTimeout.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : Timeout
**     Version     : Component 01.038, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-08-14, 06:24, # CodeGen: 679
**     Abstract    :
**
The module implements timeout functionality. With this implementation,
it is possible to wait for a given time, and the time is counted by
a periodic interrupt.
**     Settings    :
**          Component name                                 : McuTimeout
**          Maximum counters                               : 1
**          Counter tick period (ms)                       : 10
**          RTOS                                           : Disabled
**     Contents    :
**         GetCounter     - McuTimeout_CounterHandle McuTimeout_GetCounter(McuTimeout_CounterType nofTicks);
**         LeaveCounter   - void McuTimeout_LeaveCounter(McuTimeout_CounterHandle handle);
**         Value          - McuTimeout_CounterType McuTimeout_Value(McuTimeout_CounterHandle handle);
**         SetCounter     - McuTimeout_CounterType McuTimeout_SetCounter(McuTimeout_CounterHandle handle,...
**         CounterExpired - bool McuTimeout_CounterExpired(McuTimeout_CounterHandle handle);
**         AddTick        - void McuTimeout_AddTick(void);
**         Init           - void McuTimeout_Init(void);
**
** * Copyright (c) 2011-2020, Erich Styger
**  * Web:         https://mcuoneclipse.com
**  * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**  * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**  * All rights reserved.
**  *
**  * Redistribution and use in source and binary forms, with or without modification,
**  * are permitted provided that the following conditions are met:
**  *
**  * - Redistributions of source code must retain the above copyright notice, this list
**  *   of conditions and the following disclaimer.
**  *
**  * - Redistributions in binary form must reproduce the above copyright notice, this
**  *   list of conditions and the following disclaimer in the documentation and/or
**  *   other materials provided with the distribution.
**  *
**  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**  * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file McuTimeout.h
** @version 01.00
** @brief
**
The module implements timeout functionality. With this implementation,
it is possible to wait for a given time, and the time is counted by
a periodic interrupt.
*/         
/*!
**  @addtogroup McuTimeout_module McuTimeout module documentation
**  @{
*/         

#ifndef __McuTimeout_H
#define __McuTimeout_H

/* MODULE McuTimeout. */
#include "McuLib.h" /* SDK and API used */
#include "McuTimeoutconfig.h" /* configuration */

/* Include inherited components */
#include "McuLib.h"
#include "McuCriticalSection.h"


#ifndef __BWUserType_McuTimeout_CounterType
#define __BWUserType_McuTimeout_CounterType
  typedef uint32_t McuTimeout_CounterType ; /* Base type of counter which holds the counting value */
#endif
#ifndef __BWUserType_McuTimeout_CounterHandle
#define __BWUserType_McuTimeout_CounterHandle
  typedef uint8_t McuTimeout_CounterHandle ; /* Type for the timeout counter handle. */
#endif

#define McuTimeout_OUT_OF_HANDLE 0xff  /* special handle to indicate that we were running out of handlers */
#define McuTimeout_TICK_PERIOD_MS  \
  10                                    /* Tick period of timeout counter in milliseconds, as specified in component properties */


McuTimeout_CounterHandle McuTimeout_GetCounter(McuTimeout_CounterType nofTicks);
/*
** ===================================================================
**     Method      :  GetCounter (component Timeout)
**
**     Description :
**         Initializes a new timeout counter and returns the handle to
**         it. At the end, use LeaveCounter() to free up the resource.
**     Parameters  :
**         NAME            - DESCRIPTION
**         nofTicks        - Number of ticks for the counter
**                           until it expires.
**     Returns     :
**         ---             - Handle to the counter, to be used for
**                           further API calls.
** ===================================================================
*/

void McuTimeout_LeaveCounter(McuTimeout_CounterHandle handle);
/*
** ===================================================================
**     Method      :  LeaveCounter (component Timeout)
**
**     Description :
**         To be called to return the counter. Note that a counter
**         always should be returned so it can be reused.
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - Counter handle
**     Returns     : Nothing
** ===================================================================
*/

bool McuTimeout_CounterExpired(McuTimeout_CounterHandle handle);
/*
** ===================================================================
**     Method      :  CounterExpired (component Timeout)
**
**     Description :
**         Returns true if the timeout counter has been expired
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - The timeout handle retrieved using
**                           GetCounter()
**     Returns     :
**         ---             - Returns TRUE if the counter has been
**                           expired, FALSE otherwise
** ===================================================================
*/

void McuTimeout_AddTick(void);
/*
** ===================================================================
**     Method      :  AddTick (component Timeout)
**
**     Description :
**         Method to be called from a periodic timer or interrupt. It
**         will decrement all current counters by one down to zero.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuTimeout_Init(void);
/*
** ===================================================================
**     Method      :  Init (component Timeout)
**
**     Description :
**         Initialization of the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

McuTimeout_CounterType McuTimeout_Value(McuTimeout_CounterHandle handle);
/*
** ===================================================================
**     Method      :  Value (component Timeout)
**
**     Description :
**         Return the current value of the counter (in ticks)
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - Handle of the timeout counter
**     Returns     :
**         ---             - Returns the value of the timeout counter.
** ===================================================================
*/

McuTimeout_CounterType McuTimeout_SetCounter(McuTimeout_CounterHandle handle, McuTimeout_CounterType nofTicks);
/*
** ===================================================================
**     Method      :  SetCounter (component Timeout)
**
**     Description :
**         Sets the counter to a new value and returns the value just
**         prior to the call.
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - Counter handle which shall get a new
**                           value.
**         nofTicks        - New value (tick count) of the
**                           timeout counter. Pass zero to have it
**                           expire immediately.
**     Returns     :
**         ---             - Value of counter before reset.
** ===================================================================
*/

/* END McuTimeout. */

#endif
/* ifndef __McuTimeout_H */
/*!
** @}
*/
