#include "printer/kernel_printer.h"
#include "memory/memory.h"
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
	init_memory();

	printf("Kernel Looping");
	hlt();
}