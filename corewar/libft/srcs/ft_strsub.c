#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ptr;

	ptr = NULL;
	if (s)
	{
		ptr = (char *)malloc(sizeof(char) * len + 1);
		if (ptr)
		{
			ptr = ft_strncpy(ptr, &s[start], len);
			ptr[len] = '\0';
		}
	}
	return (ptr);
}
