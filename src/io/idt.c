#include "idt.h"

void	set_offset(struct idt_descriptor_entry *entry, uint64_t offset)
{
	entry->offset_1 = (uint16_t) offset & 0x000000000000FFFF;
	entry->offset_2 = (uint16_t) offset & (0x00000000FFFF0000 >> 16);
	entry->offset_3 = (uint32_t) offset & (0xFFFFFFFF00000000 >> 32);
}

void	get_offset(struct idt_descriptor_entry *entry)
{
	uint64_t	offset;
	offset = entry->offset_1;
	offset |= entry->offset_2 << 16;
	offset |= entry->offset_3 << 32;
	return offset;
}
