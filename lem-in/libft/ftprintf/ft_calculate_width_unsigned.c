#include <stddef.h>
#include "ft_printf.h"
#include "libft.h"

static void		ft_pos_num_witdh(t_data *data_ptr, int num_len)
{
	int additional;

	additional = 0;
	if (data_ptr->precision > data_ptr->width)
	{
		data_ptr->width = 0;
		return ;
	}
	if (data_ptr->flags & PLUS || data_ptr->flags & BLANK)
		data_ptr->width -= 1;
	if (data_ptr->flags & HASH)
	{
		if (data_ptr->type == 'p' || ft_strchr("xX", data_ptr->type))
			additional = 2;
		else if (data_ptr->type == 'o')
			if (data_ptr->precision < num_len + 1)
				additional = 1;
	}
	data_ptr->width -= num_len + additional;
	if (data_ptr->precision - num_len > 0)
		data_ptr->width -= data_ptr->precision - num_len;
}

static void		ft_zero_num_witdh(t_data *data_ptr, int num_len)
{
	int additional;

	additional = 0;
	if ((data_ptr->flags & PRECISION_IS_THERE))
	{
		if (data_ptr->precision)
			data_ptr->width -= data_ptr->precision;
		else if (data_ptr->flags & HASH)
		{
			if (data_ptr->type == 'o')
				if (data_ptr->precision < num_len + 1)
					additional = 1;
			if (data_ptr->type == 'p')
			{
				additional = 2 + (num_len ? num_len : 1);
			}
			data_ptr->width -= additional;
		}
	}
	else if (!((data_ptr->flags & PRECISION_IS_THERE) &&
				(data_ptr->precision <= 0)))
		data_ptr->width -= 1;
	if (data_ptr->flags & PLUS || data_ptr->flags & BLANK)
		data_ptr->width -= 1;
}

void			ft_calculate_width_unsigned\
	(t_data *data_ptr, int num_len, unsigned long long num)
{
	if (data_ptr->width > 0)
	{
		if (num > 0)
			ft_pos_num_witdh(data_ptr, num_len);
		else
			ft_zero_num_witdh(data_ptr, num_len);
	}
}
