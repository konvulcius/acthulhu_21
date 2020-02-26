#include "ft_printf.h"

int		handle_sign(t_parse *storage)
{
	if (storage->token == NEGATIVE)
		move_to_print(storage, storage->token);
	else if (storage->flags.sign != EMPTY)
		move_to_print(storage, storage->flags.sign);
	else
		return (0);
	--storage->width;
	return (1);
}

void	handle_image(t_parse *storage, int len)
{
	if (storage->flags.image == ZERO)
	{
		handle_sign(storage);
		while (storage->width-- > len)
			move_to_print(storage, '0');
	}
	else
	{
		while (storage->width-- > len + 1)
			move_to_print(storage, ' ');
		if (!handle_sign(storage) && ++storage->width > len)
			move_to_print(storage, ' ');
	}
}
