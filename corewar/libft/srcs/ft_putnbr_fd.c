#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	long int	num;

	num = n;
	if (num < 0)
	{
		num = -num;
		write(fd, "-", 1);
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	if (num < 10)
	{
		c = num + '0';
		write(fd, &c, 1);
	}
}
