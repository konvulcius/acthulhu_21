#include <unistd.h>

void	ft_putnbr(int n)
{
	char		c;
	long int	m;

	m = n;
	if (m < 0)
	{
		m = -m;
		write(1, "-", 1);
	}
	else
		m = n;
	if (m >= 10)
	{
		ft_putnbr(m / 10);
		ft_putnbr(m % 10);
	}
	if (m < 10)
	{
		c = m + '0';
		write(1, &c, 1);
	}
}
