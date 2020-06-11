/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_regs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 21:43:40 by lliza             #+#    #+#             */
/*   Updated: 2020/05/28 22:46:42 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
#include "libft.h"

static void	init_regs_data_for_one(t_vs *vs, t_sp *sp, size_t id)
{
	size_t i;

	i = 1;
	while (i < VS_REG_NUMBER)
	{
		vs->regs_data[id][i] = sp->reg[i];
		++i;
	}
}

static void	init_regs_data(t_vm *vm, t_vs *vs)
{
	t_sp	*sp;

	sp = vm->sp_list;
	while (sp)
	{
		init_regs_data_for_one(vs, sp, sp->identifier);
		sp = sp->next;
	}
}

static void	init_reg_glyphs_for_one(t_vm *vm, t_vs *vs, t_sp *sp, int id)
{
	size_t	i;
	t_glyph *glyph;
	char	*t;

	i = 1;
	vs->regs[id - 1][0] = init_glyph(vm, vs, R_X, R_Y +
	(R_Y_OFF * R_Y_OFF * (id - 1)) + (id - 1) * Y_SPRTR);
	glyph = vs->regs[id - 1][0];
	t = ft_itoa(sp->pc);
	glyph->surface = init_srfc(vm, vs->font, t, (SDL_Color *)&vs->colors[5]);
	free(t);
	init_texture(vm, vs, glyph);
	while (i < VS_REG_NUMBER)
	{
		vs->regs[id - 1][i] = init_glyph(vm, vs, R_X, R_Y +
		(R_Y_OFF * R_Y_OFF * (id - 1)) + R_Y_OFF * i + (id - 1) * Y_SPRTR);
		glyph = vs->regs[id - 1][i];
		t = ft_itoa(sp->reg[i++]);
		glyph->surface =
			init_srfc(vm, vs->font, t, (SDL_Color *)&vs->colors[5]);
		init_texture(vm, vs, glyph);
		free(t);
	}
}

void		init_vs_regs_null(t_vs *vs, size_t i)
{
	size_t j;

	j = 0;
	while (j < VS_REG_NUMBER)
	{
		vs->regs[i][j]->surface = NULL;
		vs->regs[i][j]->texture = NULL;
		++j;
	}
}

void		init_vs_regs(t_vm *vm, t_vs *vs)
{
	t_sp	*sp;

	sp = vm->sp_list;
	init_regs_data(vm, vs);
	while (sp)
	{
		init_reg_glyphs_for_one(vm, vs, sp, sp->identifier);
		sp = sp->next;
	}
}
