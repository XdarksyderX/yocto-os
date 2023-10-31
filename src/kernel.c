#include "printer/kernel_printer.h"
#include "memory/memory.h"
#include "io/interrupts.h"
void	print(const	char *str)
{
	void (*writer)(const char*, uint64_t) = get_terminal_writer();
	writer(str, strlen(str));
}

void	hlt()
{
	while(1)
		__asm__("hlt");
}

void	_start()
{
	printf("BOOTLOADER NAME: %s\n", get_bootloader_name());
	printf("BOOTLOADER VERSION: %s\n", get_bootloader_version());
	print("############### WELCOME TO YOCTO-OS SIMPLE KERNEL! ###############\n\n");
	init_memory();
	init_interrupts();
	hlt();
}