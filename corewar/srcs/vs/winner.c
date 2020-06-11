#include "vs.h"
#include "libft.h"

static void		init_winner(t_vm *vm, t_vs *vs)
{
	t_champ		*last_hero;

	last_hero = vm->champ_list;
	while (last_hero)
	{
		if (last_hero->id == vm->last_hero)
			break ;
		last_hero = last_hero->next;
	}
	vs->winner_name = init_glyph(vm, vs, (SW / 2) -
	(ft_strlen(VS_CLAIM_WINNER) * (SW / WINNER_F_SIZE) / 2), (SH / 2));
	vs->winner_name->surface = init_srfc(vm, vs->winner_font,
	VS_CLAIM_WINNER, (SDL_Color *)&vs->colors[vm->last_hero % 6]);
	init_texture(vm, vs, vs->winner_name);
	vs->has_won = init_glyph(vm, vs, (SW / 2) -
	(ft_strlen(last_hero->header->prog_name) *
	(SW / WINNER_F_SIZE) / 2), (SH / 2) - WINNER_F_SIZE);
	vs->has_won->surface = init_srfc(vm,
	vs->winner_font, last_hero->header->prog_name,
	(SDL_Color *)&vs->colors[vm->last_hero % 6]);
	init_texture(vm, vs, vs->has_won);
}

void			render_winner(t_vm *vm, t_vs *vs)
{
	if (!vs->winner_name)
	{
		init_winner(vm, vs);
		play_win_sound();
		SDL_SetRenderDrawColor(vs->renderer, 0, 0, 0, 255);
		SDL_RenderClear(vs->renderer);
		SDL_RenderCopy(vs->renderer, vs->winner_name->texture,
		NULL, &vs->winner_name->rect);
		SDL_RenderCopy(vs->renderer, vs->has_won->texture,
		NULL, &vs->has_won->rect);
	}
}
