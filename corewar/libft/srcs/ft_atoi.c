#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	r;
	int				is_negative;

	is_negative = 0;
	r = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			++is_negative;
		++str;
	}
	while (ft_isdigit(*str))
	{
		r = r * 10 + (*str - '0');
		++str;
	}
	if (is_negative)
		if (r >= 9223372036854775808UL)
			return (0);
	if (r > 9223372036854775807UL)
		return (-1);
	r = is_negative ? -r : r;
	return (r);
}
