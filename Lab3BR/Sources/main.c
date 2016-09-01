/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "MK20D5.h"
#include "MK20D5_simple.h"
#include <stdbool.h>

void set_LEDS(bool r, bool g, bool b)
{
	// If true, set the corresponding PDOR to 0.
	// If false, set the corresponding bit in PDOR to 1.

	if (r)
		GPIOC_PDOR = 0;
	else
		GPIOC_PDOR = (1 << 3);

	if (g)
		GPIOD_PDOR = 0;
	else
		GPIOD_PDOR = (1 << 4);

	if (b)
		GPIOA_PDOR = 0;
	else
		GPIOA_PDOR = (1 << 2);
}

void delay()
{
	int counter;
	for (counter = 0; counter < 500000; counter++) { /* wait */ }
}


int main(void)
{
	// Enable the clock for port control
	SIM_SCGC5 |= 0x3e00;

	// Select GPIO mode for each pin
	PORTC_PCR3 = 0x100; // r
	PORTD_PCR4 = 0x100; // g
	PORTA_PCR2 = 0x100; // b

	// Select output
	GPIOC_PDDR = (1 << 3); // PTC3 to output
	GPIOD_PDDR = (1 << 4); // PTD4 to output
	GPIOA_PDDR = (1 << 2); // PTA2 to output

	// Iterate
	for(;;) {

		//       R		G		B
		set_leds(true,	false,	false); // r
		delay();

		set_leds(true,	true,	false); // combine r and g for yellow
		delay();

		set_leds(false,	true,	false); // g
		delay();

		set_leds(false,	true,	true);  // Combine green and blue for cyan
		delay();

		set_leds(false,	false,	true); // b
		delay();

		set_leds(true,	false,	true); // combine r and b for purple
		delay();

		set_leds(true,	true,	true); // combine all for white
		delay();

	}
}


////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
