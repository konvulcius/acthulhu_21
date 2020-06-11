#include "monkey_cthulhu.h"

void	no_valid(void)
{
	write(1, "error\n", 6);
	exit(11);
}

void	memory_allocation_error(void)
{
	write(1, "error\n", 6);
	exit(13);
}
