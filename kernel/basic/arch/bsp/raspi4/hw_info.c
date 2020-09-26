#include <kernel/hw_info.h>
#include <kernel/system.h>
#include <kstring.h>

sys_info_t _sys_info;

void sys_info_init(void) {
	memset(&_sys_info, 0, sizeof(sys_info_t));

	strcpy(_sys_info.machine, "raspi4");
	_sys_info.phy_mem_size = 1024*MB;
	_sys_info.mmio.phy_base = 0xfe000000;
	_sys_info.mmio.v_base = MMIO_BASE;
	_sys_info.mmio.size = 16*MB;
}

void arch_vm(page_dir_entry_t* vm) {
	uint32_t offset = 0x40000000 - _sys_info.mmio.phy_base; //CORE0_ROUTING
	uint32_t vbase = MMIO_BASE + offset;
	uint32_t pbase = _sys_info.mmio.phy_base + offset;
	map_pages(vm, vbase, pbase, pbase+16*KB, AP_RW_D, 1);

	offset = 0x00201000; //UART_OFFSET
	vbase = MMIO_BASE + offset;
	pbase = _sys_info.mmio.phy_base + offset;
	map_page(vm, vbase, pbase, AP_RW_D, 0);
}

