#include "memory.h"
#include "../bootloader/bootservices.h"
#include "../printer/kernel_printer.h"

struct uefi_memory_region working_memory = {
	.type = LIMINE_MEMMAP_BAD_MEMORY,
	.length = 0,
	.base = 0
};

void	init_memory()
{
	printf("Loading memory...\n");
	uint64_t memory_map_entries = get_memory_map_entries();
	
	printf("Detected %d memory entries\n", memory_map_entries);
	
	uint64_t total_memory = 0;
	uint64_t usable_memory = 0;
	
	for (uint64_t i = 0; i < memory_map_entries; i++)
	{
		uint64_t type = get_memory_map_type(i);
		uint64_t length = get_memory_map_length(i);
		uint64_t base = get_memory_map_base(i);	

		printf("Memory entry %d: base=%x length=%x type=%d\n", i, length, base, type);

		total_memory += length;
		if (type == LIMINE_MEMMAP_USABLE)
			usable_memory += length;
		if (type == LIMINE_MEMMAP_USABLE)
		{
			if (length > working_memory.length)
			{
				working_memory.length = length;
				working_memory.base = base;
				working_memory.type = type;
			}

		}
	}
	printf("Total memory: %x\n", total_memory);
	printf("Usable memory: %x\n", usable_memory);
	printf("Working memory: base=%x length=%x type=%d\n", working_memory.base, working_memory.length, working_memory.type);
}