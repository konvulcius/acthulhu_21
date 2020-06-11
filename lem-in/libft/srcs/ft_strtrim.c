#include <stdlib.h>
#include "libft.h"

static char	*ft_strbegtrim(char const *s)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			++i;
		ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen(&s[i]) + 1));
		if (!ptr)
			return (NULL);
		ptr = ft_strcpy(ptr, &s[i]);
	}
	return (ptr);
}

char		*ft_strtrim(char const *s)
{
	char	*ptr;
	int		len;

	ptr = NULL;
	if (s)
	{
		ptr = ft_strbegtrim(s);
		if (!ptr)
			return (NULL);
		len = ft_strlen(ptr);
		if (ptr[len - 1] == ' ' || ptr[len - 1] == '\t' || ptr[len - 1] == '\n')
			ptr = ft_strrev(ft_strbegtrim(ft_strrev(ptr)));
	}
	return (ptr);
}
