#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			ch;
	const unsigned char		*ptr;

	ptr = s;
	ch = c;
	while (n-- > 0)
	{
		if (*ptr == ch)
			return ((void *)ptr);
		++ptr;
	}
	return (NULL);
}
