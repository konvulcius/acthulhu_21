#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n-- > 0)
	{
		*((unsigned char *)dst) = *((unsigned char *)src);
		if (*((unsigned char *)src) == (unsigned char)c)
		{
			dst = (unsigned char *)dst + 1;
			return (dst);
		}
		dst = (unsigned char *)dst + 1;
		src = (unsigned char *)src + 1;
	}
	return (NULL);
}
