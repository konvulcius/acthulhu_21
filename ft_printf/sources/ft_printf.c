#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	t_parse	storage;

	va_start(arg, format);
	storage.format_ptr = format;
	begin_func(&storage, &arg);
	va_end(arg);
	return (storage.printed);
}
