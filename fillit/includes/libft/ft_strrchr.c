#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	symbol;
	size_t			length;

	symbol = c;
	length = ft_strlen(s) + 1;
	while (length--)
	{
		if (s[length] == symbol)
			return ((char*)s + length);
	}
	return (NULL);
}
