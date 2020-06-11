/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 21:43:00 by lliza             #+#    #+#             */
/*   Updated: 2020/05/28 21:43:03 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
#include "libft.h"

static void		init_carriage(t_vm *vm, t_vs *vs, t_sp *sp, t_sp_vs *carriage)
{
	unsigned long	no_alpha;

	no_alpha = NO_ALPHA;
	if (!(carriage->surface = TTF_RenderText_Shaded(vs->font, "  ",
	*(SDL_Color *)&no_alpha,
	*(SDL_Color *)(sp->stepfather_id ? &vs->colors[sp->stepfather_id] :
	&vs->colors[sp->identifier]))))
		vs_exit_malloc_failure(vm, vs);
	if (!(carriage->texture = SDL_CreateTextureFromSurface(vs->renderer,
	carriage->surface)))
		vs_exit_malloc_failure(vm, vs);
	if (SDL_QueryTexture(carriage->texture, NULL, NULL,
	&vs->array[0]->rect.w, &vs->array[0]->rect.h) == -1)
	{
		vs_exit(vm, vs);
		vm_exit_failure(vm);
	}
	SDL_FreeSurface(carriage->surface);
	carriage->surface = NULL;
}

void			init_carriages(t_vm *vm, t_vs *vs)
{
	size_t			i;

	if (!(vs->carriages = (t_sp_vs *)malloc(sizeof(t_sp_vs) * MEM_SIZE)))
		vs_exit_malloc_failure(vm, vs);
	i = 0;
	while (i < MEM_SIZE)
	{
		vs->carriages[i].surface = NULL;
		vs->carriages[i].texture = NULL;
		++i;
	}
}

static void		place_carriages(t_vm *vm, t_vs *vs)
{
	t_sp	*sp;
	size_t	i;

	sp = vm->sp_list;
	while (sp)
	{
		i = make_pc_fit_arena(sp->pc);
		if (!vs->carriages[i].texture)
			init_carriage(vm, vs, sp, &vs->carriages[i]);
		else
		{
			SDL_DestroyTexture(vs->carriages[i].texture);
			vs->carriages[i].texture = NULL;
			init_carriage(vm, vs, sp, &vs->carriages[i]);
		}
		sp = sp->next;
	}
}

void			render_carriages(t_vm *vm, t_vs *vs)
{
	size_t	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (vs->carriages[i].texture)
		{
			SDL_DestroyTexture(vs->carriages[i].texture);
			vs->carriages[i].texture = NULL;
		}
		++i;
	}
	place_carriages(vm, vs);
	i = 0;
	while (i < MEM_SIZE)
	{
		if (vs->carriages[i].texture)
		{
			SDL_RenderCopy(vs->renderer, vs->carriages[i].texture, NULL,
			&vs->array[i]->rect);
		}
		++i;
	}
}
