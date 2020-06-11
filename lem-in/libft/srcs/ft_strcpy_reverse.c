#include "libft.h"

void	ft_strcpy_reverse(char *dest, char *src)
{
	int		len_src;

	len_src = ft_strlen(src);
	while (len_src > 0)
	{
		*dest++ = *(src + len_src - 1);
		--len_src;
	}
}
