#include "vs.h"
#include "libft.h"

static void	update_vs_champ_regs(t_vm *vm, t_vs *vs, t_sp *sp, size_t i)
{
	int32_t	temp;
	t_glyph	*glyph;
	char	*text;

	update_pc(vm, vs, sp);
	while (i < VS_REG_NUMBER)
	{
		if ((temp = sp->reg[i]) !=
			vs->regs_data[sp->identifier - 1][i])
		{
			vs->regs_data[sp->identifier - 1][i] = temp;
			glyph = vs->regs[sp->identifier - 1][i];
			if (glyph->texture)
			{
				SDL_DestroyTexture(glyph->texture);
				glyph->texture = NULL;
			}
			text = ft_itoa(temp);
			glyph->surface = init_srfc(vm, vs->font,
				text, (SDL_Color *)&vs->colors[5]);
			init_texture(vm, vs, glyph);
			free(text);
		}
		++i;
	}
}

void		update_vs_champs_regs(t_vm *vm, t_vs *vs)
{
	t_sp	*sp;
	size_t	i;

	sp = vm->sp_list;
	while (sp)
	{
		i = 1;
		if (sp->identifier <= (size_t)vm->champs_num)
			update_vs_champ_regs(vm, vs, sp, i);
		sp = sp->next;
	}
}

void		render_regs(t_vm *vm, t_vs *vs)
{
	t_sp	*sp;
	size_t	i;

	sp = vm->sp_list;
	while (sp)
	{
		i = 0;
		if (sp->identifier <= (size_t)vm->champs_num)
		{
			while (i < VS_REG_NUMBER)
			{
				SDL_RenderCopy(vs->renderer,
				vs->regs[sp->identifier - 1][i]->texture,
				NULL,
				&vs->regs[sp->identifier - 1][i]->rect);
				++i;
			}
		}
		sp = sp->next;
	}
}
