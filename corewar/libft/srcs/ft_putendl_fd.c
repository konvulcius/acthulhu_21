#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	char end;

	end = '\n';
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, &end, 1);
	}
}
