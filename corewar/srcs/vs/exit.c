/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 21:43:26 by lliza             #+#    #+#             */
/*   Updated: 2020/05/28 21:43:27 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
#include "libft.h"
#include "ft_printf.h"

void	exit_ttf_sdl(t_vs *vs)
{
	if (vs->font)
		TTF_CloseFont(vs->font);
	if (vs->menu_font)
		TTF_CloseFont(vs->menu_font);
	if (vs->winner_font)
		TTF_CloseFont(vs->winner_font);
	if (vs->renderer)
		SDL_DestroyRenderer(vs->renderer);
	if (vs->window)
		SDL_DestroyWindow(vs->window);
	TTF_Quit();
	SDL_Quit();
}

void	exit_open_font_error(t_vm *vm, t_vs *vs)
{
	exit_ttf_sdl(vs);
	free(vs);
	ft_printf("%WTTF_OpenFont: %s\n", 2, "font not found");
	vm_exit_failure(vm);
}

void	vs_exit_malloc_failure(t_vm *vm, t_vs *vs)
{
	exit_ttf_sdl(vs);
	free(vs);
	vm_exit_malloc_failure(vm);
}

void	vs_exit(t_vm *vm, t_vs *vs)
{
	exit_ttf_sdl(vs);
	vs_glyph_list_free(&vs->names);
	vs_glyph_list_free(&vs->winner_name);
	vs_glyph_list_free(&vs->has_won);
	vs_glyph_list_free(&vs->menu_static);
	vs_glyph_list_free(&vs->menu_mutable);
	vs_free_carriages(vs);
	vs_glyph_array_free(vs->array, MEM_SIZE);
	if (vs->array)
	{
		free(vs->array);
		vs->array = NULL;
	}
	vs_free_regs(vm, vs);
	free(vs);
}
