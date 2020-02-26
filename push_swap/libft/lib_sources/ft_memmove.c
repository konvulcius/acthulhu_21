#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*object;
	unsigned char const	*source;

	if (!(dst || src))
		return (0);
	object = dst;
	source = src;
	if (source > object)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len-- > 0)
			object[len] = source[len];
	}
	return (object);
}
