#include <stdlib.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		while (*s1 && n)
		{
			if (*s1 != *s2)
				return (0);
			++s1;
			++s2;
			--n;
		}
		if (n && *s2)
			return (0);
	}
	return (1);
}
