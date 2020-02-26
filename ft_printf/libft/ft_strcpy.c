#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	length;

	length = ft_strlen(src);
	ft_memcpy(dst, src, length);
	dst[length] = '\0';
	return (dst);
}
