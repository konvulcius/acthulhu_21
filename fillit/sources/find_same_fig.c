#include "monkey_cthulhu.h"

void	find_same_fig(t_tetrimino *first)
{
	t_tetrimino *check;

	check = first->next;
	while (check)
	{
		if (first->p[0].x == check->p[0].x && first->p[0].y == check->p[0].y
			&& first->p[1].x == check->p[1].x && first->p[1].y == check->p[1].y
			&& first->p[2].x == check->p[2].x && first->p[2].y == check->p[2].y
			&& first->p[3].x == check->p[3].x && first->p[3].y == check->p[3].y)
		{
			check->same = first;
			first = first->next;
			check = first;
		}
		check = check->next;
	}
}
