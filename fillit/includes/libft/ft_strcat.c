#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*pointer_to_s1;

	pointer_to_s1 = ft_strchr(s1, '\0');
	ft_strcpy(pointer_to_s1, s2);
	return (s1);
}
