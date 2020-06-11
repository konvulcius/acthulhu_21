#include "ft_printf.h"

void	ft_multiply_buff_by_two(char *buff)
{
	int sum;

	sum = 2 * (*buff ? *buff - '0' : 0);
	if (sum > 9)
	{
		*buff = sum % 10 + '0';
		ft_multiply_buff_by_two(buff + 1);
		ft_add_figure_to_buff(buff + 1, 1);
	}
	else
	{
		*buff = sum + '0';
		if (*(buff + 1))
			ft_multiply_buff_by_two(buff + 1);
	}
}
