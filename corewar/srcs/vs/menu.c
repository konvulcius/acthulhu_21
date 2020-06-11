/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 21:43:46 by lliza             #+#    #+#             */
/*   Updated: 2020/05/28 22:47:48 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

t_glyph	*init_glyph(t_vm *vm, t_vs *vs, int x, int y)
{
	t_glyph	*glyph;

	if (!(glyph = (t_glyph *)malloc(sizeof(t_glyph))))
		vs_exit_malloc_failure(vm, vs);
	glyph->rect.x = x;
	glyph->rect.y = y;
	glyph->next = NULL;
	glyph->surface = NULL;
	glyph->texture = NULL;
	return (glyph);
}

void	init_menu(t_vm *vm, t_vs *vs)
{
	t_glyph	*glyph;
	size_t	i;

	i = 0;
	vs->menu_static = init_glyph(vm, vs, MENU_X, MENU_Y + MENU_Y_OFFSET * i);
	glyph = vs->menu_static;
	while (vs->g_menu[i])
	{
		glyph->surface = init_srfc(vm,
									vs->menu_font,
									(char *)vs->g_menu[i],
									(SDL_Color *)&vs->colors[5]);
		init_texture(vm, vs, glyph);
		i += 1;
		if (vs->g_menu[i])
		{
			glyph->next = init_glyph(vm, vs,
				MENU_X, MENU_Y + MENU_Y_OFFSET * i);
			glyph = glyph->next;
		}
	}
}

void	render_menu(t_vs *vs)
{
	t_glyph *start_static;
	t_glyph *start_mutable;

	start_static = vs->menu_static;
	start_mutable = vs->menu_mutable;
	while (start_static)
	{
		SDL_RenderCopy(vs->renderer, start_static->texture,
			NULL, &start_static->rect);
		SDL_RenderCopy(vs->renderer, start_mutable->texture,
			NULL, &start_mutable->rect);
		start_static = start_static->next;
		start_mutable = start_mutable->next;
	}
}
