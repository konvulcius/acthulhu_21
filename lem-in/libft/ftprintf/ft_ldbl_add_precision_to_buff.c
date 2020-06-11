#include "ft_printf.h"

static int		ft_ldbl_add_less_than_18\
	(union u_ldbl *un, char *fraction_ptr, int precision)
{
	__uint128_t			temp;
	int					round_up;
	long long int		multiplyer;

	round_up = precision;
	multiplyer = 1;
	round_up = precision;
	while (round_up >= 0)
	{
		multiplyer *= 10;
		--round_up;
	}
	temp = un->dbl * multiplyer;
	round_up = (temp % 10 > 4) ? 1 : 0;
	temp = temp / 10;
	while (precision > 0)
	{
		precision--;
		fraction_ptr[precision] = (temp % 10) + '0';
		temp /= 10;
	}
	return (round_up);
}

void			ft_ldbl_add_precision_to_buff\
	(union u_ldbl *un, char *buff_int, char *buff_fraction, int precision)
{
	char	*fraction_ptr;
	int		round_up;

	fraction_ptr = buff_fraction;
	round_up = 0;
	if (precision < 18)
		round_up = ft_ldbl_add_less_than_18(un, buff_fraction, precision);
	else
	{
		while (precision > 0)
		{
			un->dbl *= 10;
			*fraction_ptr++ = (int)un->dbl + '0';
			un->dbl -= (int)un->dbl;
			precision--;
		}
		un->dbl *= 10;
		if (((int)un->dbl > 4 || (int)un->dbl < -4) &&
			un->bytes[4] != 65535 && un->bytes[4] != 32767)
			round_up = 1;
	}
	if (round_up == 1)
		ft_round_ldbl_up(buff_int, buff_fraction);
}
