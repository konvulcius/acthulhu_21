#include "ft_printf.h"

void	handle_g(t_parse *storage, t_float_point *container)
{
	if (storage->precision > container->exp_10 && container->exp_10 >= -4)
	{
		storage->precision -= 1 + container->exp_10;
		handle_f(storage, container);
	}
	else
	{
		storage->precision -= 1;
		handle_e(storage, container);
	}
}
