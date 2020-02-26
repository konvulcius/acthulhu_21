#include "ft_printf.h"

void	flag_cleaner(t_parse *storage)
{
	storage->current = 0;
	storage->width = 0;
	storage->precision = -1;
	storage->flags.hash = 0;
	storage->token = POSITIVE;
	storage->flags.image = NOTHING;
	storage->flags.sign = EMPTY;
}
