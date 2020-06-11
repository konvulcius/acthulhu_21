#include "ft_printf.h"

void	ft_add_flag(char **s, t_data *data_ptr)
{
	if (**s == '-')
		data_ptr->flags |= ALIGN_LEFT;
	if (**s == '0')
		data_ptr->flags |= ZERO;
	if (**s == '+')
		data_ptr->flags |= PLUS;
	if (**s == ' ')
		data_ptr->flags |= BLANK;
	if (**s == '#')
		data_ptr->flags |= HASH;
}
