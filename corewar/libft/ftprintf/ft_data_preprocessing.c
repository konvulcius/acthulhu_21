#include "ft_printf.h"

void	ft_data_preprocessing(t_data *data_ptr)
{
	if (data_ptr->flags & ALIGN_LEFT)
	{
		data_ptr->flags &= ~(1 << 1);
		if (data_ptr->flags & PLUS)
			data_ptr->flags &= ~(1 << 3);
	}
	else if (data_ptr->precision > 0)
		data_ptr->flags &= ~(1 << 1);
	if (data_ptr->flags & PLUS && data_ptr->flags & PRECISION_IS_THERE)
		data_ptr->flags &= ~(1 << 1);
	if (data_ptr->type == 'u')
	{
		data_ptr->flags &= ~(1 << 3);
		data_ptr->flags &= ~(1 << 2);
	}
}
