#include <stddef.h>
#include "ft_printf.h"
#include "libft.h"

static void		ft_add_sign(t_data *data_ptr, char **buff_ptr, long long num)
{
	if (num < 0)
		*((*buff_ptr)++) = '-';
	else
	{
		if (data_ptr->flags & PLUS)
			*((*buff_ptr)++) = '+';
		else if (data_ptr->flags & BLANK)
			*((*buff_ptr)++) = ' ';
	}
}

static void		ft_add_sign_and_hex\
	(t_data *data_ptr, char **buff_ptr, long long num)
{
	if (!(data_ptr->flags & ALIGN_LEFT))
	{
		if (data_ptr->flags & ZERO)
		{
			ft_add_sign(data_ptr, buff_ptr, num);
			ft_add_hex_to_buff(data_ptr, buff_ptr, num);
			ft_add_width_to_buff(data_ptr, buff_ptr);
		}
		else
		{
			ft_add_width_to_buff(data_ptr, buff_ptr);
			ft_add_sign(data_ptr, buff_ptr, num);
			ft_add_hex_to_buff(data_ptr, buff_ptr, num);
		}
	}
	else
	{
		ft_add_sign(data_ptr, buff_ptr, num);
		ft_add_hex_to_buff(data_ptr, buff_ptr, num);
	}
}

static void		ft_add_to_buff\
	(long long num, int base, t_data *data_ptr, char **buff_ptr)
{
	ft_add_sign_and_hex(data_ptr, buff_ptr, num);
	ft_calculate_precision(data_ptr, ft_num_len(num, base));
	ft_add_int_precision(data_ptr, buff_ptr);
	if (!((data_ptr->flags & PRECISION_IS_THERE) &&
		data_ptr->precision == 0 && num == 0))
		ft_add_figures_to_buff(num, base, data_ptr, buff_ptr);
	else if ((data_ptr->flags & HASH) &&
		(data_ptr->type == 'o' || data_ptr->type == 'p'))
		ft_add_figures_to_buff(num, base, data_ptr, buff_ptr);
	ft_add_width_to_buff(data_ptr, buff_ptr);
}

void			ft_add_num_to_buff\
	(long long num, int base, t_data *data_ptr, char **buff_ptr)
{
	size_t	len;

	len = ft_num_len(num, base);
	ft_calculate_width(data_ptr, len, num);
	ft_add_to_buff(num, base, data_ptr, buff_ptr);
}
