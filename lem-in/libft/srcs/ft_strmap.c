#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	if (s && f)
	{
		ptr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!ptr)
			return (NULL);
		while (s[i])
		{
			ptr[i] = f(s[i]);
			++i;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
