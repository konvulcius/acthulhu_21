#include "ft_printf.h"

void	unsigned_solver(t_parse *storage, va_list *arg)
{
	if (storage->format_ptr[storage->specfr_len] == 'u')
		handle_u(storage, arg);
	else if (storage->format_ptr[storage->specfr_len] == 'p')
		handle_p(storage, arg);
	else if (storage->format_ptr[storage->specfr_len] == 'o')
		handle_octet(storage, arg);
	else if (storage->format_ptr[storage->specfr_len] == 'x' || \
		storage->format_ptr[storage->specfr_len] == 'X')
		handle_hex(storage, arg);
}
