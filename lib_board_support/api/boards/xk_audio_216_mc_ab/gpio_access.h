// Copyright 2024 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

/// API to access the 8bit gpio port on audio XU216 multi channel board.

#pragma once

#ifdef __XC__
extern "C" {
#endif

#ifndef XCORE_200_MC_AUDIO_HW_VERSION
#define XCORE_200_MC_AUDIO_HW_VERSION 2
#endif


#if XCORE_200_MC_AUDIO_HW_VERSION == 2

/* General output port bit definitions */
#define P_GPIO_DSD_MODE         (1 << 0) /* DSD mode select 0 = 8i/8o I2S, 1 = 8o DSD*/
#define P_GPIO_DAC_RST_N        (1 << 1)
#define P_GPIO_USB_SEL0         (1 << 2)
#define P_GPIO_USB_SEL1         (1 << 3)
#define P_GPIO_VBUS_EN          (1 << 4)
#define P_GPIO_PLL_SEL          (1 << 5) /* 1 = CS2100, 0 = Phaselink clock source */
#define P_GPIO_ADC_RST_N        (1 << 6)
#define P_GPIO_MCLK_FSEL        (1 << 7) /* Select frequency on Phaselink clock. 0 = 24.576MHz for 48k, 1 = 22.5792MHz for 44.1k.*/

#else

/* General output port bit definitions */
#define P_GPIO_DSD_MODE         (1 << 0) /* DSD mode select 0 = 8i/8o I2S, 1 = 8o DSD*/
#define P_GPIO_DAC_RST_N        (1 << 1)
#define P_GPIO_ADC_RST_N        (1 << 2)
#define P_GPIO_USB_SEL0         (1 << 3)
#define P_GPIO_USB_SEL1         (1 << 4)
#define P_GPIO_VBUS_EN          (1 << 5)
#define P_GPIO_MCLK_FSEL        (1 << 6) /* Select frequency on Phaselink clock. 0 = 24.576MHz for 48k, 1 = 22.5792MHz for 44.1k.*/
#define P_GPIO_PLL_SEL          (1 << 7) /* 1 = CS2100, 0 = Phaselink clock source */

#endif


/*LED array defines*/
#define LED_ALL_ON              0xf00f
#define LED_SQUARE_BIG          0x9009
#define LED_SQUARE_SML          0x6006
#define LED_ROW_1               0xf001
#define LED_ROW_2               0xf003
#define LED_ROW_3               0xf007
#define ALL_OFF                 0x0000
// LED array masks
#define LED_MASK_COL_OFF        0x7fff
#define LED_MASK_DISABLE        0xffff

void aud_216_p_gpio_lock();
void aud_216_p_gpio_unlock();

/// Read the port
unsigned aud_216_p_gpio_peek();

/// write to the port
void aud_216_p_gpio_out(unsigned x);

/// set individual bits
void aud_216_set_gpio(unsigned bit, unsigned value);

#ifdef __XC__
}
#endif
