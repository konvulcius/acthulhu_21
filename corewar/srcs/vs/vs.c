#include "vs.h"
#include "libft.h"
#include "ft_printf.h"

static void	update_renderer(t_vm *vm, t_vs *vs)
{
	update_mutable(vm, vs);
	update_vs_champs_regs(vm, vs);
	SDL_SetRenderDrawColor(vs->renderer, 0, 0, 0, 255);
	SDL_RenderClear(vs->renderer);
	render_glyph_array(vs->array, MEM_SIZE, vs->renderer);
	render_carriages(vm, vs);
	render_menu(vs);
	render_regs(vm, vs);
	render_names(vs);
}

void		apply_events(t_vm *vm, t_vs *vs, const Uint8 *state, t_bool *pause)
{
	int			multiplier;

	if ((vs->e.type == SDL_KEYUP || vs->e.type == SDL_KEYDOWN))
	{
		if (state[SDL_SCANCODE_SPACE])
			*pause ^= 1;
		else if (state[SDL_SCANCODE_RIGHT])
		{
			if (state[SDL_SCANCODE_LSHIFT])
			{
				run_cycles(vm, vs, 100);
				update_renderer(vm, vs);
			}
			else if ((multiplier = get_multiplier(vs, state)))
			{
				run_cycles(vm, vs, 10 * multiplier);
				update_renderer(vm, vs);
			}
			else
			{
				vs_cycle(vm, vs);
				update_renderer(vm, vs);
			}
		}
	}
}

void		render_cycle(t_vm *vm, t_vs *vs, t_bool pause)
{
	if (!pause)
	{
		vs_cycle(vm, vs);
		update_renderer(vm, vs);
	}
}

void		vs(t_vm *vm)
{
	t_vs		*vs;
	t_bool		pause;
	const Uint8	*state;

	vs = vs_init(vm);
	pause = TRUE;
	state = SDL_GetKeyboardState(NULL);
	update_renderer(vm, vs);
	while (TRUE)
	{
		if (SDL_PollEvent(&vs->e))
		{
			if (vs->e.type == SDL_QUIT)
				break ;
			else if (vm->sp_list)
				apply_events(vm, vs, state, &pause);
		}
		if (vm->sp_list)
			render_cycle(vm, vs, pause);
		else
			render_winner(vm, vs);
		SDL_RenderPresent(vs->renderer);
	}
	vs_exit(vm, vs);
}
