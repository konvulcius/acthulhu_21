#include "ft_printf.h"
#include <stddef.h>

void	ft_add_hex_to_buff(t_data *data_ptr, char **buff_ptr, long long num)
{
	if ((data_ptr->flags & HASH) &&
		(data_ptr->type == 'x' || data_ptr->type == 'X'))
	{
		if (num)
		{
			*((*buff_ptr)++) = '0';
			*((*buff_ptr)++) = data_ptr->type;
		}
	}
	else if (data_ptr->type == 'p')
	{
		*((*buff_ptr)++) = '0';
		*((*buff_ptr)++) = 'x';
	}
}
