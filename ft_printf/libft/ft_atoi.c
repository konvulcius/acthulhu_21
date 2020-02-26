#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	value;
	int					minus;

	minus = 1;
	value = 0;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + (*str - 48);
		str++;
	}
	if (value > MAX_LL && minus > 0)
		return (-1);
	if (value > MAX_LL && minus < 0)
		return (0);
	return (value * minus);
}
