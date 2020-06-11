#include "ft_printf.h"

void	ft_add_width_to_buff(t_data *data_ptr, char **buff_ptr)
{
	char fill;

	if (data_ptr->width > 0)
	{
		if ((data_ptr->flags & ALIGN_LEFT) || data_ptr->precision > 0)
			fill = ' ';
		else
			fill = (data_ptr->flags & ZERO) ? '0' : ' ';
		while (data_ptr->width != 0)
		{
			*((*buff_ptr)++) = fill;
			data_ptr->width--;
		}
	}
}
