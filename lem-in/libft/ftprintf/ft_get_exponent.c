#include "ft_printf.h"
#include "libft.h"

int		ft_get_exponent(long double n)
{
	union u_ldbl	num;
	unsigned short	exp;

	num.dbl = n;
	ft_memcpy(&exp, &num.bytes[4], 15);
	exp <<= 1;
	exp >>= 1;
	return (int)(exp - EXP_BIAS);
}
