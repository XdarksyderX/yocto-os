#ifndef MEMORY_H
#define MEMORY_H

#include "../bootloader/bootservices.h"

struct uefi_memory_region
{
	uint64_t base;
	uint64_t length;
	uint64_t type;
};

void	init_memory();

#endif