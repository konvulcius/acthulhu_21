#include "ft_printf.h"

void	ft_convert_ldbl_to_fraction(union u_ldbl *un)
{
	int border;

	border = 64;
	if (ft_get_exponent(un->dbl) > 16382)
		un->bytes[4] = 16382;
	while (border > 0)
	{
		if (un->bytes[3] & (1 << 15))
			break ;
		ft_union_ldbl_bitmove_right(un, 1);
		un->bytes[4] -= 1;
		--border;
	}
}
