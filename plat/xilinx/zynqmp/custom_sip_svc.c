/*
 * Copyright (c) 2022-2023, Advanced Micro Devices Inc. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <common/bl_common.h>
#include <common/debug.h>
#include <smccc_helpers.h>
#include <lib/mmio.h>

uint64_t custom_smc_handler(uint32_t smc_fid, uint64_t x1, uint64_t x2,
			    uint64_t x3, uint64_t x4, void *cookie,
			    void *handle, uint64_t flags)
{
	WARN("Unimplemented SiP Service Call: 0x%x\n", smc_fid);
	SMC_RET1(handle, SMC_UNK);
}

void custom_early_setup(void)
{
	/* GPIO Bank1, MIO26 - DEAD_BATTERY */
	mmio_setbits_32(0xff0a0244, BIT(0));    // DIRM_1
	mmio_setbits_32(0xff0a0044, BIT(0));    // DATA_1
	mmio_setbits_32(0xff0a0248, BIT(0));    // OEN_1

	/* GPIO Bank0, MIO19 - SHUTDOWN */
	mmio_setbits_32(0xff0a0204, BIT(19));   // DIRM_0
	mmio_setbits_32(0xff0a0040, BIT(19));   // DATA_0
	mmio_setbits_32(0xff0a0208, BIT(19));   // OEN_0
}

void custom_mmap_add(void)
{
}

void custom_runtime_setup(void)
{
}
