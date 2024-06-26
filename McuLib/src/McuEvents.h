/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuEvents.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : SimpleEvents
**     Version     : Component 01.059, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-08-14, 06:24, # CodeGen: 679
**     Abstract    :
**
**     Settings    :
**          Component name                                 : McuEvents
**          SDK                                            : McuLib
**          Critical Section                               : McuCriticalSection
**          Initialize on Init                             : yes
**          Event Name List                                : (string list)
**     Contents    :
**         SetEvent      - void McuEvents_SetEvent(uint8_t event);
**         ClearEvent    - void McuEvents_ClearEvent(uint8_t event);
**         EventsPending - bool McuEvents_EventsPending(void);
**         GetEvent      - bool McuEvents_GetEvent(uint8_t event);
**         GetClearEvent - bool McuEvents_GetClearEvent(uint8_t event);
**         HandleEvent   - void McuEvents_HandleEvent(void);
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
** @file McuEvents.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup McuEvents_module McuEvents module documentation
**  @{
*/         

#ifndef __McuEvents_H
#define __McuEvents_H

/* MODULE McuEvents. */
#include "McuLib.h" /* SDK and API used */
#include "McuEventsconfig.h" /* configuration */

/* Event prototype */
void McuEvents_CONFIG_EVENT_HANDLER_NAME(uint8_t event);


#ifdef __cplusplus
extern "C" {
#endif




void McuEvents_SetEvent(uint8_t event);
/*
** ===================================================================
**     Method      :  SetEvent (component SimpleEvents)
**
**     Description :
**         Sets an event (number) be processed by the next HandleEvent()
**         call
**     Parameters  :
**         NAME            - DESCRIPTION
**         event           - The event (number) to be set so it
**                           will be called by the HandleEvent() routine
**                           later on. Note that there cannot be
**                           multiple instances of an event, and the
**                           lower the event number, the higher the
**                           priority.
**     Returns     : Nothing
** ===================================================================
*/

void McuEvents_HandleEvent(void);
/*
** ===================================================================
**     Method      :  HandleEvent (component SimpleEvents)
**
**     Description :
**         Event handler, to be called periodically.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuEvents_Init(void);
/*
** ===================================================================
**     Method      :  McuEvents_Init (component SimpleEvents)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

bool McuEvents_GetEvent(uint8_t event);
/*
** ===================================================================
**     Method      :  GetEvent (component SimpleEvents)
**
**     Description :
**         Allows to check if an event is set or not.
**     Parameters  :
**         NAME            - DESCRIPTION
**         event           - The event number to check. If the
**                           event is set, the function returns TRUE.
**     Returns     :
**         ---             - none
** ===================================================================
*/

void McuEvents_ClearEvent(uint8_t event);
/*
** ===================================================================
**     Method      :  ClearEvent (component SimpleEvents)
**
**     Description :
**         Clears one event (number). If the event is not set, then the
**         function has no effect.
**     Parameters  :
**         NAME            - DESCRIPTION
**         event           - The event number to be cleared.
**     Returns     : Nothing
** ===================================================================
*/

bool McuEvents_EventsPending(void);
/*
** ===================================================================
**     Method      :  EventsPending (component SimpleEvents)
**
**     Description :
**         Returns true if any events are pending, false otherwise
**     Parameters  : None
**     Returns     :
**         ---             - True in case any events are pending, false
**                           otherwise.
** ===================================================================
*/

bool McuEvents_GetClearEvent(uint8_t event);
/*
** ===================================================================
**     Method      :  GetClearEvent (component SimpleEvents)
**
**     Description :
**         Allows to check if an event is set or not. If set, it will
**         be automatically cleared.
**     Parameters  :
**         NAME            - DESCRIPTION
**         event           - The event number to check. If the
**                           event is set, the function returns TRUE.
**     Returns     :
**         ---             - none
** ===================================================================
*/

/* END McuEvents. */

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif
/* ifndef __McuEvents_H */
/*!
** @}
*/
