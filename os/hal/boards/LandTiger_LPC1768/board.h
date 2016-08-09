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

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for Embedded Artists LPCXpresso Base Board with LPC1756 daughter
 * board.
 */

/*
 * Board identifiers.
 */
#define BOARD_LPC1768
#define BOARD_NAME "LPC1768"

/*
 * Board frequencies.
 */
#define SYSOSCCLK               12000000

/*
 * GPIO 0 initial setup.
 */
#define VAL_GPIO0DIR            0x00000000
#define VAL_GPIO0DATA           0x00000000

/*
 * GPIO 1 initial setup.
 */
#define VAL_GPIO1DIR            0x00000000
#define VAL_GPIO1DATA           0x00000000

/*
 * GPIO 2 initial setup.
 */
#define VAL_GPIO2DIR            0x000000ff
#define VAL_GPIO2DATA           0x00000000

/*
 * GPIO 3 initial setup.
 */
#define VAL_GPIO3DIR            0x00000000
#define VAL_GPIO3DATA           0x00000000

/*
 * GPIO 4 initial setup.
 */
#define VAL_GPIO4DIR            0x00000000
#define VAL_GPIO4DATA           0x00000000

/*
 * Pin definitions.
 */
#define GPIO1_LED               18

#define GPIO2_SW                4
#define GPIO2_LED0               1<<0
#define GPIO2_LED1               1<<1
#define GPIO2_LED2               1<<2
#define GPIO2_LED3               1<<3
#define GPIO2_LED4               1<<4
#define GPIO2_LED5               1<<5
#define GPIO2_LED6               1<<6
#define GPIO2_LED7               1<<7

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
