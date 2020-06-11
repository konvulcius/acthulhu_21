#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	value;

	value = n;
	if (value < 0)
	{
		ft_putchar_fd('-', fd);
		value *= -1;
	}
	if (value / 10 != 0)
	{
		ft_putnbr_fd(value / 10, fd);
		ft_putchar_fd(value % 10 + 48, fd);
	}
	else
		ft_putchar_fd(value % 10 + 48, fd);
}
