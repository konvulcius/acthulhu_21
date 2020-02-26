#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	symbol;

	if (!s)
		return (NULL);
	symbol = c;
	while (*s)
	{
		if (*s == symbol)
			return ((char*)s);
		s++;
	}
	if (symbol == '\0' && *s == symbol)
		return ((char*)s);
	return (NULL);
}
