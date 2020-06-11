#include "ft_printf.h"

void	ft_union_ldbl_bitmove_right(union u_ldbl *un, int shift)
{
	un->bytes[3] = un->bytes[3] << shift | un->bytes[2] >> (16 - shift);
	un->bytes[2] = un->bytes[2] << shift | un->bytes[1] >> (16 - shift);
	un->bytes[1] = un->bytes[1] << shift | un->bytes[0] >> (16 - shift);
	un->bytes[0] = un->bytes[0] << shift;
}
