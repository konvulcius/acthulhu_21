#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char *r;

	r = NULL;
	--s;
	while (*++s)
		if (*s == (char)c)
			r = (char *)s;
	if (*s == (char)c)
		r = (char *)s;
	return (r);
}
