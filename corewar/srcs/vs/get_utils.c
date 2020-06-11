#include "vs.h"

size_t	get_champ_size(t_vm *vm, int id)
{
	t_sp *temp;

	temp = vm->sp_list;
	while (temp)
	{
		if (temp->champ->id == id)
			return (temp->champ->header->prog_size);
		temp = temp->next;
	}
	return (0);
}

int		get_multiplier(t_vs *vs, const Uint8 *state)
{
	if (vs->e.type == SDL_KEYDOWN)
	{
		if (state[SDL_SCANCODE_1])
			return (1);
		if (state[SDL_SCANCODE_2])
			return (2);
		if (state[SDL_SCANCODE_3])
			return (3);
		if (state[SDL_SCANCODE_4])
			return (4);
		if (state[SDL_SCANCODE_5])
			return (5);
		if (state[SDL_SCANCODE_6])
			return (6);
		if (state[SDL_SCANCODE_7])
			return (7);
		if (state[SDL_SCANCODE_8])
			return (8);
		if (state[SDL_SCANCODE_9])
			return (9);
	}
	return (0);
}
