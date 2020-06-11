#ifndef VS_H
# define VS_H

# include "ft_corewar.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>

# define SW 1600
# define SH 1200
# define NO_ALPHA 0UL
# define GREY 0xFF808080UL
# define GREEN 0xFF00FF00UL
# define YELLOW 0xFF00FFFFUL
# define RED 0xFF0000FFUL
# define BLUE 0xFFFF0000UL
# define WHITE 0xFFFFFFFFUL
# define BYTE_F_SIZE 15
# define MENU_F_SIZE 25
# define MENU_X 10
# define MENU_Y 1000
# define MENU_Y_OFFSET 50
# define MUT_X 500
# define MUT_Y 1000
# define MUT_Y_OFFSET 50
# define R_X 1350
# define R_Y 0
# define R_Y_OFF 17
# define NAME_X_OFFSET 1400
# define Y_SPRTR 10
# define VS_REG_NUMBER 17
# define VS_CLAIM_WINNER "has won!"
# define WINNER_F_SIZE 48

typedef struct s_glyph	t_glyph;
typedef struct s_sp_vs	t_sp_vs;

struct				s_glyph
{
	int				x;
	int				y;
	TTF_Font		*font;
	unsigned long	*color;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	SDL_Rect		rect;
	t_glyph			*next;
};

struct				s_sp_vs
{
	SDL_Surface		*surface;
	SDL_Texture		*texture;
};

typedef struct		s_vs
{
	SDL_Event		e;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	TTF_Font		*font;
	TTF_Font		*menu_font;
	TTF_Font		*winner_font;
	unsigned long	colors[6];
	t_glyph			**array;
	uint32_t		color_is[MEM_SIZE];
	t_sp_vs			*carriages;
	t_glyph			*menu_static;
	t_glyph			*menu_mutable;
	t_glyph			*regs[4][VS_REG_NUMBER];
	int				regs_data[4][VS_REG_NUMBER];
	int				mutable_data[4];
	char			*g_menu[4];
	t_glyph			*names;
	t_glyph			*winner_name;
	t_glyph			*has_won;
}					t_vs;

/*
** init
*/
t_vs				*vs_init(t_vm *vm);
t_glyph				*init_glyph(t_vm *vm, t_vs *vs, int x, int y);
SDL_Surface			*init_srfc
	(t_vm *vm, TTF_Font *font, char *text, SDL_Color *color);
void				init_texture(t_vm *vm, t_vs *vs, t_glyph *glyph);
void				query_texture_free_surface
	(t_vm *vm, t_vs *vs, t_glyph *glyph);
t_glyph				**init_glyph_array(t_vm *vm, t_vs *vs);
void				init_menu(t_vm *vm, t_vs *vs);
void				init_mutable(t_vm *vm, t_vs *vs);
void				init_vs_regs(t_vm *vm, t_vs *vs);
void				init_names(t_vm *vm, t_vs *vs);
void				init_carriages(t_vm *vm, t_vs *vs);

/*
** update
*/
void				update_mutable(t_vm *vm, t_vs *vs);
void				update_vs_champs_regs(t_vm *vm, t_vs *vs);
void				update_pc(t_vm *vm, t_vs *vs, t_sp *sp);

/*
** utils
*/
size_t				get_champ_size(t_vm *vm, int id);
int					get_multiplier(t_vs *vs, const Uint8 *state);
void				vs_apply_arena_update(t_vm *vm, t_vs *vs, t_sp *sp);

/*
** render
*/
void				render_regs(t_vm *vm, t_vs *vs);
void				render_names(t_vs *vs);
void				render_menu(t_vs *vs);
void				render_winner(t_vm *vm, t_vs *vs);
void				render_glyph_array
	(t_glyph **array, size_t size, SDL_Renderer *renderer);
void				render_carriages(t_vm *vm, t_vs *vs);

/*
** cycle
*/
void				vs_cycle(t_vm *vm, t_vs *vs);
void				run_cycles(t_vm *vm, t_vs *vs, size_t num);

/*
** free
*/
void				vs_glyph_list_free(t_glyph **list);
void				vs_free_carriages(t_vs *vs);
void				vs_glyph_free(t_glyph **glyph);
void				vs_glyph_array_free(t_glyph **array, size_t size);
void				vs_free_regs(t_vm *vm, t_vs *vs);
void				exit_ttf_sdl(t_vs *vs);
void				vs_exit_malloc_failure(t_vm *vm, t_vs *vs);
void				exit_open_font_error(t_vm *vm, t_vs *vs);
void				vs_exit(t_vm *vm, t_vs *vs);

#endif
