#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	index;
	char	*pointer_to_new_string;

	if (!s)
		return (NULL);
	pointer_to_new_string = ft_strnew(ft_strlen(s));
	if (!pointer_to_new_string)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		pointer_to_new_string[index] = f(s[index]);
		index++;
	}
	return (pointer_to_new_string);
}
