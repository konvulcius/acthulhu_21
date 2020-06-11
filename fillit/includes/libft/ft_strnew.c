#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;
	size_t	length;

	length = size + 1;
	if (length < size)
		return (NULL);
	if (!(string = (char*)ft_memalloc(length)))
		return (NULL);
	return (string);
}
