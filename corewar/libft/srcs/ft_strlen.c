#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	if (s)
		while (s[size])
			++size;
	return (size);
}
