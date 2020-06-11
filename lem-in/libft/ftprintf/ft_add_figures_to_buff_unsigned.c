#include "ft_printf.h"

extern char *g_nums_low;
extern char *g_nums_up;

void	ft_add_figures_to_buff_unsigned\
	(unsigned long long num, unsigned int base, t_data *d_ptr, char **buff_ptr)
{
	char *s;

	s = (d_ptr->flags & HEX_SMALL) ? g_nums_low : g_nums_up;
	if (num >= base)
		ft_add_figures_to_buff((num / base), base, d_ptr, buff_ptr);
	*((*buff_ptr)++) = s[(num % base)];
}
