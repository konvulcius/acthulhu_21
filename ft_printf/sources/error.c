#include "ft_printf.h"

void	error(void)
{
	write(1, "Memory allocation error\n", 24);
	exit(11);
}
