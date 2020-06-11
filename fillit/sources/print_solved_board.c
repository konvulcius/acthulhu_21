#include "monkey_cthulhu.h"

void	print_solved_board(char **p)
{
	while (*p)
	{
		ft_putstr(*p);
		write(1, "\n", 1);
		p++;
	}
}
