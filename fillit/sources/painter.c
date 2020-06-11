#include <monkey_cthulhu.h>

void	painter(char **board, t_position pos, t_tetrimino *element, char code)
{
	board[pos.y + element->p[0].y][pos.x + element->p[0].x] = code;
	board[pos.y + element->p[1].y][pos.x + element->p[1].x] = code;
	board[pos.y + element->p[2].y][pos.x + element->p[2].x] = code;
	board[pos.y + element->p[3].y][pos.x + element->p[3].x] = code;
}
