/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 21:44:15 by lliza             #+#    #+#             */
/*   Updated: 2020/05/29 13:55:31 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
#include "libft.h"

SDL_Surface	*init_srfc\
	(t_vm *vm, TTF_Font *font, char *text, SDL_Color *color)
{
	SDL_Surface		*surface;
	unsigned long	sub_color;

	sub_color = GREY;
	if (!font)
	{
		ft_putendl_fd("surface null font", 2);
		vm_exit_failure(vm);
	}
	if (!text)
	{
		ft_putendl_fd("surface no text pointer", 2);
		vm_exit_failure(vm);
	}
	if (!(surface = TTF_RenderText_Solid(font, text ? text : "00",
		color ? *(SDL_Color *)color : *(SDL_Color *)&sub_color)))
	{
		ft_putendl_fd("surface malloc from init_srfc", 2);
		vm_exit_failure(vm);
	}
	return (surface);
}

void		init_texture(t_vm *vm, t_vs *vs, t_glyph *glyph)
{
	if (!(glyph->texture =
		SDL_CreateTextureFromSurface(vs->renderer, glyph->surface)))
	{
		ft_putendl_fd("texture malloc from init_texture", 2);
		vs_exit_malloc_failure(vm, vs);
	}
	if (SDL_QueryTexture(glyph->texture, NULL, NULL,
		&glyph->rect.w, &glyph->rect.h) == -1)
	{
		vs_exit(vm, vs);
		ft_putendl_fd("query texture failed", 2);
		vm_exit_failure(vm);
	}
	SDL_FreeSurface(glyph->surface);
	glyph->surface = NULL;
}

void		vs_apply_arena_update(t_vm *vm, t_vs *vs, t_sp *sp)
{
	uint8_t info[4];
	char	text[3];
	size_t	i;

	if (sp->last_change == NO_CHANGE)
		return ;
	i = 0;
	int_to_bytes(info, 0, bytes_to_int(vm->arena, sp->last_change, REG_SIZE));
	while (i < 4)
	{
		ft_bzero(text, 3);
		sprintf(text, "%02x", (int)info[i]);
		SDL_DestroyTexture(vs->array[make_pc_fit_arena(sp->last_change +
		i)]->texture);
		vs->array[make_pc_fit_arena(sp->last_change + i)]->surface =
		init_srfc(vm, vs->font, text,
		(SDL_Color *)&vs->colors[sp->stepfather_id ?
		sp->stepfather_id % 6 : sp->identifier % 6]);
		init_texture(vm, vs, vs->array[make_pc_fit_arena(sp->last_change +
		i)]);
		++i;
	}
	sp->last_change = NO_CHANGE;
}
