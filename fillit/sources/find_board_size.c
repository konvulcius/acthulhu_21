#include "monkey_cthulhu.h"

size_t		find_board_size(size_t value)
{
	size_t a;

	a = 2;
	while (a * a < value * 4)
		a++;
	return (a);
}
