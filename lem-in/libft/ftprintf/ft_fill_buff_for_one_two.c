#include "ft_printf.h"

void	ft_fill_buff_for_one_two(char *buff, int exp)
{
	char *buff_ptr;

	buff_ptr = buff;
	ft_add_figure_to_buff(buff_ptr, 1);
	while (exp > 0)
	{
		ft_multiply_buff_by_two(buff_ptr);
		exp--;
	}
}
