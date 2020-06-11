#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*pointer_to_s1;

	pointer_to_s1 = ft_strchr(s1, '\0');
	ft_memccpy(pointer_to_s1, s2, '\0', n);
	if (n < ft_strlen(s2))
		pointer_to_s1[n] = '\0';
	return (s1);
}
