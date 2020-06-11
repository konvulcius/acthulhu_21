#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;

	if (!dest && !src)
		if (n)
			return (NULL);
	ptr_dst = dest;
	ptr_src = src;
	if (ptr_dst > ptr_src)
		while (n-- > 0)
			*(ptr_dst + n) = *(ptr_src + n);
	else
		while (n-- > 0)
			*ptr_dst++ = *ptr_src++;
	return (dest);
}
