#include "ft_printf.h"
#include "libft.h"

void	ft_add_width_to_data(char **s, t_data *data_ptr)
{
	if (**s == '*')
	{
		data_ptr->width = va_arg(data_ptr->args, int);
		if (data_ptr->width < 0)
		{
			data_ptr->flags |= ALIGN_LEFT;
			data_ptr->width = -data_ptr->width;
		}
		++*s;
	}
	if (ft_isdigit(**s))
	{
		data_ptr->width = 0;
		while (ft_isdigit(**s))
		{
			if (data_ptr->width)
				data_ptr->width *= 10;
			data_ptr->width += **s - '0';
			++*s;
		}
	}
}
