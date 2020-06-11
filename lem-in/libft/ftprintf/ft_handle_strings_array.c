#include "ft_printf.h"

void	ft_handle_strings_array(t_data *d_ptr, char **b_ptr)
{
	char **arr;
	char *delimiter;

	arr = (char **)va_arg(d_ptr->args, void *);
	delimiter = va_arg(d_ptr->args, char *);
	if (arr)
	{
		while (*arr)
		{
			ft_add_string_to_buff(*arr, d_ptr, b_ptr);
			if (*(arr + 1))
				if (delimiter)
					ft_add_string_to_buff(delimiter, d_ptr, b_ptr);
			++arr;
		}
	}
}
