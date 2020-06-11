#include "monkey_cthulhu.h"

int		allowed_to_insert(char **board, t_position pos, t_tetrimino *element,
		size_t size)
{
	int		count;

	count = 0;
	while (count < 4)
	{
		if (pos.y + element->p[count].y < 0 || pos.x + element->p[count].x < 0
				|| pos.y + element->p[count].y >= (int)size
				|| pos.x + element->p[count].x >= (int)size ||
				board[pos.y + element->p[count].y][pos.x + element->p[count].x]
				!= '.')
			return (0);
		count++;
	}
	element->point.x = pos.x + element->p[0].x;
	element->point.y = pos.y + element->p[0].y;
	painter(board, pos, element, element->alpha);
	return (1);
}
