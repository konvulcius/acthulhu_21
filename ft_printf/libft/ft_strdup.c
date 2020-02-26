#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*box_for_string;

	box_for_string = ft_strnew(ft_strlen(s1));
	if (!box_for_string)
		return (NULL);
	ft_strcpy(box_for_string, s1);
	return (box_for_string);
}
