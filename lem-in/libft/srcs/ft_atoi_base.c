#include "libft.h"

static int		ft_isatof(char c)
{
	return ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

int				ft_atoi_base(const char *str, int base)
{
	unsigned long	r;
	int				is_negative;

	is_negative = 0;
	r = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			++is_negative;
	}
	while (ft_isdigit(*str) || ft_isatof(*str))
	{
		r = r * base + (ft_isdigit(*str) ?
			(*str - '0') : (10 + (ft_toupper(*str) - 'A')));
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
