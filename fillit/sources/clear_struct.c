#include "monkey_cthulhu.h"

void	clear_struct(t_tetrimino **begin)
{
	t_tetrimino		*temp;

	while (*begin)
	{
		temp = (*begin)->next;
		free(*begin);
		*begin = temp;
	}
}
