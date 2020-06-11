#include "ft_printf.h"

void		ft_handle_size_t(t_data *d_ptr, char **b_ptr)
{
	if (d_ptr->subtype == 'x')
	{
		d_ptr->flags |= HEX_SMALL;
		ft_add_u_num_to_buff(va_arg(d_ptr->args, unsigned long int),
							16, d_ptr, b_ptr);
	}
	else if (d_ptr->subtype == 'd' || d_ptr->subtype == 'u')
		ft_add_u_num_to_buff(va_arg(d_ptr->args, size_t), 10, d_ptr, b_ptr);
}
