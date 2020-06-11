#include "ft_printf.h"
#include <stddef.h>

void	ft_add_int_precision(t_data *data_ptr, char **buff_ptr)
{
	if (data_ptr->precision > 0)
		while (data_ptr->precision-- != 0)
			*((*buff_ptr)++) = '0';
}
