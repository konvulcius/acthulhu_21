#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	--s;
	while (*++s)
		if (*s == (char)c)
			return ((char *)s);
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
