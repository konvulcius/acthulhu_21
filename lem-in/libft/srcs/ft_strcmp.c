#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (!s1)
	{
		if (!s2)
			return (0);
		else
			return (1);
	}
	while (*s1)
	{
		if (*s1 != *s2)
			break ;
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
