#include "ft_printf.h"

void	ft_add_length(char **s, t_data *data_ptr)
{
	if (**s == 'l')
	{
		if (*(*s + 1) == 'l')
		{
			data_ptr->flags |= LL;
			++*s;
		}
		else
			data_ptr->flags |= L_LOWER;
	}
	else if (**s == 'h')
	{
		if (*(*s + 1) == 'h')
		{
			data_ptr->flags |= HH;
			++*s;
		}
		else
			data_ptr->flags |= H;
	}
	else if (**s == 'L')
		data_ptr->flags |= L_UPPER;
}
