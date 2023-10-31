#include "kernel_printer.h"

void	_putchar(char c)
{
	void (*writer)(const char*, uint64_t) = get_terminal_writer();
	writer(&c, 1);
}

void	panic(const char *message)
{
	printf("PANIC: %s\n", message);
	while (1)
		__asm__("hlt");
}