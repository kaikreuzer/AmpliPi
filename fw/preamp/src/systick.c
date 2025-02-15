/*
 * AmpliPi Home Audio
 * Copyright (C) 2021 MicroNova LLC
 *
 * Control for front panel LEDs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "systick.h"
#include <stm32f0xx.h>

// Initialize the system ticks. Change CPU_FREQ according to the frequency being used. (E.g. 8 MHz, 48 MHz, etc)
void systickInit ()
{
#define CPU_FREQ 8000000
#define SYSTICK_FREQ 1000 // 1000 Hz = 1 ms ticks
   SysTick_Config (CPU_FREQ / SYSTICK_FREQ);
}

// The actual tick counter
volatile uint32_t systick_count_ = 0;
extern void SysTick_Handler (void)
 {
	systick_count_++;
 }

// Return the system clock as a number of milliseconds
inline uint32_t millis (void)
{
   return systick_count_;
}

// Synchronous delay in milliseconds
void delay_ms (uint32_t t)
{
  uint32_t start, end;
  start = millis();
  end = start + t;
  if (start < end) {
  	while ((millis() >= start) && (millis() < end)) {
  	  // do nothing
  	}
  } else {
    while ((millis() >= start) || (millis() < end)) {
      // do nothing
    };
  }
}

