#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				counter;
	unsigned char		*object;
	unsigned char const	*source;
	unsigned char		symbol;

	if (!(dst || src))
		return (0);
	counter = -1;
	object = dst;
	source = src;
	symbol = c;
	while (++counter < n)
	{
		object[counter] = source[counter];
		if (source[counter] == symbol)
			return (&object[counter + 1]);
	}
	return (NULL);
}
