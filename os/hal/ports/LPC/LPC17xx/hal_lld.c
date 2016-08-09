/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file    LPC17xx/hal_lld.c
 * @brief   LPC17xx HAL subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "ch.h"
#include "hal.h"

/**
 * @brief   Register missing in NXP header file.
 */
#define FLASHCFG (*((volatile uint32_t *)0x4003C010))

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void) {

  
}

/**
 * @brief   LPC17xx clocks and PLL initialization.
 * @note    All the involved constants come from the file @p board.h.
 * @note    This function must be invoked only after the system reset.
 *
 * @special
 */
void LPC17xx_clock_init(void) {
    SystemInit();
    SystemCoreClockUpdate();
#if 0
  unsigned i;

  /* Flash wait states setting, the code takes care to not touch TBD bits.*/
  FLASHCFG = (FLASHCFG & ~3) | LPC17xx_FLASHCFG_FLASHTIM;

  /* System oscillator initialization if required.*/
#if LPC17xx_MAINCLK_SOURCE == SYSMAINCLKSEL_PLLOUT
#if LPC17xx_PLLCLK_SOURCE == SYSPLLCLKSEL_SYSOSC
  LPC_SYSCON->SYSOSCCTRL = LPC17xx_SYSOSCCTRL;
  LPC_SYSCON->PDRUNCFG &= ~(1 << 5);            /* System oscillator ON.    */
  for (i = 0; i < 200; i++)
    __NOP();                                    /* Stabilization delay.     */
#endif /* LPC17xx_PLLCLK_SOURCE == SYSPLLCLKSEL_SYSOSC */

  /* PLL initialization if required.*/
  LPC_SYSCON->SYSPLLCLKSEL = LPC17xx_PLLCLK_SOURCE;
  LPC_SYSCON->SYSPLLCLKUEN = 1;                 /* Really required?         */
  LPC_SYSCON->SYSPLLCLKUEN = 0;
  LPC_SYSCON->SYSPLLCLKUEN = 1;
  LPC_SYSCON->SYSPLLCTRL = LPC17xx_SYSPLLCTRL_MSEL | LPC17xx_SYSPLLCTRL_PSEL;
  LPC_SYSCON->PDRUNCFG &= ~(1 << 7);            /* System PLL ON.           */
  while ((LPC_SYSCON->SYSPLLSTAT & 1) == 0)     /* Wait PLL lock.           */
    ;
#endif /* LPC17xx_MAINCLK_SOURCE == SYSMAINCLKSEL_PLLOUT */

  /* Main clock source selection.*/
  LPC_SYSCON->MAINCLKSEL = LPC17xx_MAINCLK_SOURCE;
  LPC_SYSCON->MAINCLKUEN = 1;                   /* Really required?         */
  LPC_SYSCON->MAINCLKUEN = 0;
  LPC_SYSCON->MAINCLKUEN = 1;
  while ((LPC_SYSCON->MAINCLKUEN & 1) == 0)     /* Wait switch completion.  */
    ;

  /* ABH divider initialization, peripheral clocks are initially disabled,
     the various device drivers will handle their own setup except GPIO and
     IOCON that are left enabled.*/
  LPC_SYSCON->SYSAHBCLKDIV = LPC17xx_SYSABHCLK_DIV;
  LPC_SYSCON->SYSAHBCLKCTRL = 0x0001005F;

  /* Memory remapping, vectors always in ROM.*/
  LPC_SYSCON->SYSMEMREMAP = 2;
#endif
}

/** @} */
