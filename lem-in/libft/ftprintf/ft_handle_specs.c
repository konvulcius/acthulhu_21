#include <stddef.h>
#include "ft_printf.h"
#include "libft.h"

char *g_types = "%dioOxXucsfpbzQW";
char *g_subtypes = "uxd";

static void	ft_handle_specs_with_subtypes(char **s, t_data *d_ptr, char **b_ptr)
{
	if (d_ptr->type == 'z')
		if (ft_strchr(g_subtypes, *(*s + 1)))
		{
			d_ptr->subtype = *(++(*s));
			ft_data_processing(d_ptr, b_ptr);
		}
}

void		ft_handle_specs(char **s, t_data *data_ptr, char **buff_ptr)
{
	while (**s && ft_is_flag(*s))
	{
		ft_add_flag(s, data_ptr);
		++*s;
	}
	ft_add_width_to_data(s, data_ptr);
	if (**s == '.')
		ft_add_precision_to_data(s, data_ptr);
	if (ft_is_length(*s))
	{
		ft_add_length(s, data_ptr);
		++*s;
	}
	if (ft_strchr(g_types, **s))
	{
		data_ptr->type = **s;
		if (data_ptr->type == 'z')
			ft_handle_specs_with_subtypes(s, data_ptr, buff_ptr);
		else if (data_ptr->type == 'W')
			data_ptr->fd = va_arg(data_ptr->args, int);
		else
			ft_data_processing(data_ptr, buff_ptr);
	}
	if (**s == '{')
		ft_color_input(s, buff_ptr);
}
