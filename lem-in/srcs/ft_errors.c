#include "ft_lemin.h"

void	ft_allocation_error(void)
{
	write(2, "Memory is over\n", 15);
	exit(1);
}

void	ft_error_here(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}
