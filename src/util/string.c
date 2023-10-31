#include "string.h"
#include <stdint.h>

uint64_t	strlen(const char *str)
{
	uint64_t len = 0;
	while (str[len] && len < STRING_MAX_SIZE)
		len++;
	return len;
}

void	memset(void *str, char c, uint64_t size)
{
	uint64_t i = 0;
	while (i < size)
	{
		((char *) str)[i] = c;
		i++;
	}
}