#include "ft_printf.h"

void	count_print(t_parse *storage, va_list *arg)
{
	int		*printed;

	printed = va_arg(*arg, int*);
	*printed = storage->printed + storage->string_length;
}
