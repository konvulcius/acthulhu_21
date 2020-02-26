#include "libft.h"

void	ft_strdel(char **as)
{
	if (as && *as)
		ft_memdel((void**)as);
}
