#include "libft.h"

char	*find_between(const char *s1, const char *s2, int c)
{
	unsigned char	ch;

	if (!s1 || !s2)
		return (NULL);
	ch = c;
	if (s1 <= s2)
	{
		while (s1 <= s2)
		{
			if (*s1 == ch)
				return ((char*)s1);
			s1++;
		}
		return (NULL);
	}
	else
	{
		while (s1 > s2)
		{
			if (*s1 == ch)
				return ((char*)s1);
			s1--;
		}
		return (NULL);
	}
}
