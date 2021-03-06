/*
 * (C) Copyright 2012
 * Alexander Potashev, Emcraft Systems, aspotashev@emcraft.com
 * Vladimir Khusainov, Emcraft Systems, vlad@emcraft.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include "clock.h"

/*
 * Print the CPU specific information
 */
int print_cpuinfo(void)
{
	char buf[CLOCK_END][32];

	printf("CPU  : %s\n", "SmartFusion2 SoC (Cortex-M3 Hard IP)");

	strmhz(buf[CLOCK_SYSTICK], clock_get(CLOCK_SYSTICK));
	strmhz(buf[CLOCK_DDR],     clock_get(CLOCK_DDR));
	strmhz(buf[CLOCK_PCLK0],   clock_get(CLOCK_PCLK0));
	strmhz(buf[CLOCK_PCLK1],   clock_get(CLOCK_PCLK1));
	strmhz(buf[CLOCK_FIC0],    clock_get(CLOCK_FIC0));
	strmhz(buf[CLOCK_DDRFIC],  clock_get(CLOCK_DDRFIC));
	printf("Freqs: CORTEX-M3=%sMHz,DDR=%sMHz,PCLK0=%sMHz,PCLK1=%sMHz,FIC0=%sMHz,DDRFIC=%sMHz\n",
		buf[CLOCK_SYSTICK], buf[CLOCK_DDR], buf[CLOCK_PCLK0],
		buf[CLOCK_PCLK1], buf[CLOCK_FIC0], buf[CLOCK_DDRFIC]);

	return 0;
}

#ifdef CONFIG_BOOTCOUNT_LIMIT

void bootcount_store (ulong a)
{
	volatile ulong *save_addr = (volatile ulong *)(CONFIG_SYS_BOOTCOUNT_ADDR);

	save_addr[0] = a;
	save_addr[1] = BOOTCOUNT_MAGIC;
}

ulong bootcount_load (void)
{
	volatile ulong *save_addr = (volatile ulong *)(CONFIG_SYS_BOOTCOUNT_ADDR);

	if (save_addr[1] != BOOTCOUNT_MAGIC)
		return 0;
	else
		return save_addr[0];
}

#endif /* CONFIG_BOOTCOUNT_LIMIT */
