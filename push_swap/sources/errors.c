#include "push_swap.h"

void	stop(void)
{
	exit(0);
}

void	allocation_error(void)
{
	write(2, "Error\n", 6);
	exit(2);
}

void	the_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
