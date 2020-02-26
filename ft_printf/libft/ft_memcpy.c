#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				counter;
	unsigned char		*object;
	unsigned char const	*source;

	if (!(dest || src))
		return (0);
	counter = -1;
	object = dest;
	source = src;
	while (++counter < n)
		object[counter] = source[counter];
	return (object);
}
