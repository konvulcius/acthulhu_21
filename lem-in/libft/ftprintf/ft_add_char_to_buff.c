#include "ft_printf.h"
#include <stddef.h>

void	ft_add_char_to_buff(unsigned char c, t_data *data_ptr, char **buff_ptr)
{
	if (data_ptr->width)
		data_ptr->width--;
	if (!(data_ptr->flags & ALIGN_LEFT))
		ft_add_width_to_buff(data_ptr, buff_ptr);
	*((*buff_ptr)++) = c;
	ft_add_width_to_buff(data_ptr, buff_ptr);
}
