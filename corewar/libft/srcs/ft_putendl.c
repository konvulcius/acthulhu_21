#include "libft.h"
#include <unistd.h>

void	ft_putendl(char const *s)
{
	char lf;

	lf = '\n';
	if (s)
	{
		write(1, s, ft_strlen(s));
		write(1, &lf, 1);
	}
}
