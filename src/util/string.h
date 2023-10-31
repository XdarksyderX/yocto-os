#ifndef STRING_H
#define STRING_H

#include <stdint.h>

uint64_t	strlen(const char *str);
void	memset(void *str, char c, uint64_t size);

#define STRING_MAX_SIZE 65536

#endif