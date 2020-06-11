/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 21:44:10 by lliza             #+#    #+#             */
/*   Updated: 2020/05/28 21:44:12 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

void		init_colors(t_vs *vs)
{
	vs->colors[0] = GREY;
	vs->colors[1] = GREEN;
	vs->colors[2] = YELLOW;
	vs->colors[3] = RED;
	vs->colors[4] = BLUE;
	vs->colors[5] = WHITE;
}

void		init_g_menu(t_vs *vs)
{
	vs->g_menu[0] = "cycle total:";
	vs->g_menu[1] = "cycle to die:";
	vs->g_menu[2] = "current cycle:";
	vs->g_menu[3] = NULL;
}

void		init_vs_data(t_vm *vm, t_vs *vs)
{
	init_colors(vs);
	vs->array = init_glyph_array(vm, vs);
	init_g_menu(vs);
	init_menu(vm, vs);
	init_carriages(vm, vs);
	init_mutable(vm, vs);
	init_vs_regs(vm, vs);
	init_names(vm, vs);
}

static void	vs_init_null(t_vs *vs)
{
	vs->array = NULL;
	vs->menu_static = NULL;
	vs->menu_mutable = NULL;
	vs->names = NULL;
	vs->winner_name = NULL;
	vs->has_won = NULL;
	vs->font = NULL;
	vs->menu_font = NULL;
	vs->winner_font = NULL;
}

t_vs		*vs_init(t_vm *vm)
{
	t_vs	*vs;

	if (SDL_Init(SDL_INIT_VIDEO))
		vm_exit_failure(vm);
	if (TTF_Init())
		vm_exit_failure(vm);
	if (!(vs = (t_vs *)malloc(sizeof(t_vs))))
		vm_exit_malloc_failure(vm);
	vs_init_null(vs);
	if (!(vs->font = TTF_OpenFont("assets/ClassCoder.ttf", BYTE_F_SIZE)))
		exit_open_font_error(vm, vs);
	if (!(vs->menu_font = TTF_OpenFont("assets/AgentOrange.ttf", MENU_F_SIZE)))
		exit_open_font_error(vm, vs);
	if (!(vs->winner_font = TTF_OpenFont("assets/ebola.ttf", WINNER_F_SIZE)))
		exit_open_font_error(vm, vs);
	if (!(vs->window = SDL_CreateWindow("COREWAR",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SW, SH, 0)) ||
		!(vs->renderer = SDL_CreateRenderer(vs->window, -1, 0)))
		exit_ttf_sdl(vs);
	init_vs_data(vm, vs);
	return (vs);
}
