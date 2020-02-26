#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	length;

	length = ft_strlen(src);
	if (length < len)
	{
		ft_memcpy(dst, src, length);
		ft_bzero(&dst[length], len - length);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
