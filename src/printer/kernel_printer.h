#ifndef KERNEL_PRINTER_H
# define KERNEL_PRINTER_H

# include "../bootloader/bootservices.h"
# include "./printf.h"
# include "../util/string.h"

void	_putchar(char c);
void	panic(const char *message);

#endif