#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr_dst;
	unsigned char		*ptr_src;

	ptr_dst = dst;
	ptr_src = (unsigned char *)src;
	if (dst == src)
		return (dst);
	while (n > 0)
	{
		*ptr_dst++ = *ptr_src++;
		--n;
	}
	return (dst);
}
