#include "vs.h"

void	vs_glyph_free(t_glyph **glyph)
{
	t_glyph *ptr;

	ptr = NULL;
	if (glyph && *glyph)
	{
		ptr = *glyph;
		if (ptr->surface)
			SDL_FreeSurface(ptr->surface);
		if (ptr->texture)
			SDL_DestroyTexture(ptr->texture);
		free(ptr);
	}
	*glyph = NULL;
}

void	vs_glyph_list_free(t_glyph **list)
{
	if (list && *list)
		if ((*list)->next)
			vs_glyph_list_free(&(*list)->next);
	vs_glyph_free(list);
}

void	vs_sp_free(t_sp_vs *carriage)
{
	if (carriage)
	{
		if (carriage->surface)
			SDL_FreeSurface(carriage->surface);
		if (carriage->texture)
			SDL_DestroyTexture(carriage->texture);
	}
}

void	vs_free_carriages(t_vs *vs)
{
	size_t i;

	i = 0;
	if (vs->carriages)
	{
		while (i < MEM_SIZE)
		{
			vs_sp_free(&vs->carriages[i]);
			++i;
		}
		free(vs->carriages);
		vs->carriages = NULL;
	}
}

void	vs_free_regs(t_vm *vm, t_vs *vs)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (size_t)vm->champs_num)
	{
		j = 0;
		while (j < VS_REG_NUMBER)
		{
			vs_glyph_free(&vs->regs[i][j]);
			++j;
		}
		++i;
	}
}
