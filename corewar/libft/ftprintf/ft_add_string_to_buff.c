#include <stddef.h>
#include "ft_printf.h"
#include "libft.h"

void	ft_add_string_to_buff\
	(char *string, t_data *data_ptr, char **buff_ptr)
{
	int		s_len;
	char	*s;

	s = !string ? "(null)" : string;
	s_len = ft_strlen(s);
	if ((data_ptr->flags & PRECISION_IS_THERE))
		if (data_ptr->precision >= 0)
			if (data_ptr->precision < s_len)
				s_len = data_ptr->precision;
	data_ptr->width = (data_ptr->width < s_len) ? 0 : (data_ptr->width - s_len);
	if (!(data_ptr->flags & ALIGN_LEFT))
		ft_add_width_to_buff(data_ptr, buff_ptr);
	while (s_len-- != 0)
		*((*buff_ptr)++) = *s++;
	ft_add_width_to_buff(data_ptr, buff_ptr);
}
