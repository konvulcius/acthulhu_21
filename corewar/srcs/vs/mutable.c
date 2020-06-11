#include "vs.h"
#include "libft.h"

int32_t	get_temp_mutable(t_vm *vm, size_t i)
{
	if (i == 0)
		return (vm->cycle_total);
	if (i == 1)
		return (vm->cycle_to_die);
	if (i == 2)
		return (vm->curr_cycle);
	return (0);
}

void	init_mutable(t_vm *vm, t_vs *vs)
{
	t_glyph		*glyph;
	size_t		i;
	char		*text;

	i = 0;
	vs->mutable_data[0] = 0;
	vs->mutable_data[1] = CYCLE_TO_DIE;
	vs->mutable_data[2] = 0;
	vs->mutable_data[3] = 0;
	vs->menu_mutable = init_glyph(vm, vs, MUT_X, MUT_Y + MUT_Y_OFFSET * i);
	glyph = vs->menu_mutable;
	while (vs->g_menu[i])
	{
		text = ft_itoa(vs->mutable_data[i]);
		glyph->surface = init_srfc(vm, vs->menu_font,
			text, (SDL_Color *)&vs->colors[5]);
		init_texture(vm, vs, glyph);
		free(text);
		i += 1;
		if (vs->g_menu[i])
		{
			glyph->next = init_glyph(vm, vs, MUT_X, MUT_Y + MUT_Y_OFFSET * i);
			glyph = glyph->next;
		}
	}
}

void	update_mutable(t_vm *vm, t_vs *vs)
{
	t_glyph		*glyph;
	size_t		i;
	int32_t		temp;
	char		*text;

	glyph = vs->menu_mutable;
	i = 0;
	while (glyph)
	{
		temp = get_temp_mutable(vm, i);
		if (temp != vs->mutable_data[i])
		{
			vs->mutable_data[i] = temp;
			SDL_DestroyTexture(glyph->texture);
			text = ft_itoa(vs->mutable_data[i]);
			glyph->surface = init_srfc(vm, vs->menu_font,
				text, (SDL_Color *)&vs->colors[5]);
			init_texture(vm, vs, glyph);
			free(text);
			text = NULL;
		}
		glyph = glyph->next;
		++i;
	}
}

void	update_pc(t_vm *vm, t_vs *vs, t_sp *sp)
{
	size_t		id;
	t_glyph		*glyph;
	char		*text;

	id = sp->identifier - 1;
	if (vs->regs_data[id][0] != sp->pc)
	{
		vs->regs_data[id][0] = sp->pc;
		glyph = vs->regs[id][0];
		SDL_DestroyTexture(glyph->texture);
		text = ft_itoa(sp->pc);
		glyph->surface = init_srfc(vm, vs->font,
			text, (SDL_Color *)&vs->colors[5]);
		init_texture(vm, vs, glyph);
		free(text);
	}
}
