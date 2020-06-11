#include <stdlib.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *ptr;

	ptr = s1;
	while (*ptr)
		++ptr;
	while (*s2 && n-- > 0)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (s1);
}
