#include "ft_printf.h"
#include "libft.h"

void	ft_get_int_part(long double n)
{
	int				exp;
	union u_ldbl	num;
	int				i;

	num.dbl = n;
	exp = ft_get_exponent(n);
	while (exp >= 0)
	{
		i = 15;
		while (i >= 0 && exp >= 0)
		{
			ft_printf("%d\n", (num.bytes[4] & (1 << i)) ?
					ft_num_to_power(2, exp) : 0);
			--i;
			--exp;
		}
	}
}
