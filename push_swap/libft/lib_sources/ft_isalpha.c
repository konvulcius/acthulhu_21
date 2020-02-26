#include "libft.h"

int		ft_isalpha(int c)
{
	if (ft_tolower(c) >= 97 && ft_tolower(c) <= 122)
		return (1);
	return (0);
}
