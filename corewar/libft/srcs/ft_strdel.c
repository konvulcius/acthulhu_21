#include "libft.h"

void	ft_strdel(char **as)
{
	if (as)
		if (*as)
		{
			free(*as);
			*as = NULL;
		}
}
