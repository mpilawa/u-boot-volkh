/*
 * m2s.h
 *
 * (C) Copyright 2012
 * Emcraft Systems, <www.emcraft.com>
 * Alexander Potashev <aspotashev@emcraft.com>
 * Vladimir Khusainov, <vlad@emcraft.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _MACH_M2S_H_
#define _MACH_M2S_H_

#include <linux/types.h>

/*
 * SYSREG registers. Refer to Microsemi's SF2 User's Guide for details.
 */
struct m2s_sysreg {
	unsigned int	esram_cr;
	unsigned int	esram_max_lat;
	unsigned int	ddr_cr;
	unsigned int	envm_cr;
	unsigned int	envm_remap_base_cr;
	unsigned int	envm_remap_fab_cr;
	unsigned int	cc_cr;
	unsigned int	cc_region_cr;
	unsigned int	cc_lock_base_addr_cr;
	unsigned int	cc_flush_indx_cr;
	unsigned int	ddrb_buf_timer_cr;
	unsigned int	ddrb_nb_addr_cr;
	unsigned int	ddrb_nb_size_cr;
	unsigned int	ddrb_cr;
	unsigned int	edac_cr;
	unsigned int	master_weight0_cr;
	unsigned int	master_weight_cr;
	unsigned int	soft_irq_cr;
	unsigned int	soft_reset_cr;
	unsigned int	m3_cr;
	unsigned int	fab_if_cr;
	unsigned int	loopback_cr;
	unsigned int	gpio_sysreset_sel_cr;
	unsigned int	gpin_src_sel_cr;
	unsigned int	mddr_cr;
	unsigned int	usb_io_input_sel_cr;
	unsigned int	periph_clk_mux_sel_cr;
	unsigned int	wdog_cr;
	unsigned int	mddr_io_calib_cr;
	unsigned int	reserved1;
	unsigned int	edac_irq_enable_cr;
	unsigned int	usb_cr;
	unsigned int	esram_pipeline_cr;
	unsigned int	mss_irq_enable_cr;
	unsigned int	rtc_wakeup_cr;
	unsigned int	mac_cr;
	unsigned int	mssddr_pll_status_low_cr;
	unsigned int	mssddr_pll_status_high_cr;
	unsigned int	mssddr_facc1_cr;
	unsigned int	mssddr_facc2_cr;
	unsigned int	reserved_A0_B0[4];
	unsigned int	reset_source_cr;
	unsigned int	reserved_B4_150[39];
	unsigned int	mssddr_pll_status;
};

/*
 * SYSREG access handle
 */
#define M2S_SYSREG_BASE			0x40038000
#define M2S_SYSREG			((volatile struct m2s_sysreg *)\
					(M2S_SYSREG_BASE))

#define SYSREG_FPGA_SOFTRESET_MASK	(1 << 16)

struct m2s_coresf2config {
    unsigned int   config_done;
    unsigned int   init_done;
    unsigned int   clr_init_done;
};

#define CORE_SF2_CFG_BASE		0x40022000u
#define CORE_SF2_CFG			\
	((volatile struct m2s_coresf2config *)CORE_SF2_CFG_BASE)

#define CONFIG_1_DONE			(1 << 0)
#define CONFIG_2_DONE			(1 << 1)
#define INIT_DONE_MASK			(1 << 0)

/*
 * Reference clocks enumeration
 */
enum clock {
	CLOCK_SYSREF,
	CLOCK_DDR,
	CLOCK_A,
	CLOCK_SYSTICK,
	CLOCK_PCLK0,
	CLOCK_PCLK1,
	CLOCK_FIC0,
	CLOCK_FIC1,
	CLOCK_DDRFIC,
	CLOCK_END
};

/*
 * Return a clock value for the specified reference clock
 * @param clck		reference clock
 * @returns		clock value
 */
extern ulong clock_get(enum clock clck);

#endif /* _MACH_M2S_H_ */
