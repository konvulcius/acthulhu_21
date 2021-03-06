#include "ft_printf.h"

char *g_nums_low = "0123456789abcdef";
char *g_nums_up = "0123456789ABCDEF";

void	ft_add_figures_to_buff\
	(long long num, int base, t_data *data_ptr, char **buff_ptr)
{
	char *s;

	s = (data_ptr->flags & HEX_SMALL) ? g_nums_low : g_nums_up;
	if (num >= base)
		ft_add_figures_to_buff((num / base), base, data_ptr, buff_ptr);
	if (num <= -base)
		ft_add_figures_to_buff((num / -base), base, data_ptr, buff_ptr);
	*((*buff_ptr)++) = s[(num % base) >= 0 ? (num % base) : (num % base) * -1];
}
