#include "vs.h"
#include "libft.h"

void		init_names(t_vm *vm, t_vs *vs)
{
	t_glyph		*glyph;
	t_sp		*sp;
	size_t		id;

	sp = vm->sp_list;
	id = sp->identifier;
	vs->names = init_glyph(vm, vs, NAME_X_OFFSET, R_Y +
		(R_Y_OFF * R_Y_OFF * (id - 1)) + (id - 1) * Y_SPRTR);
	glyph = vs->names;
	while (sp)
	{
		id = sp->identifier;
		glyph->surface = init_srfc(vm, vs->font,
			sp->champ->header->prog_name, (SDL_Color *)&vs->colors[id % 6]);
		init_texture(vm, vs, glyph);
		sp = sp->next;
		if (sp)
		{
			id = sp->identifier;
			glyph->next = init_glyph(vm, vs, NAME_X_OFFSET, R_Y + R_Y +
		(R_Y_OFF * R_Y_OFF * (id - 1) + (id - 1) * Y_SPRTR));
			glyph = glyph->next;
		}
	}
}

void		render_names(t_vs *vs)
{
	t_glyph *glyph;

	glyph = vs->names;
	while (glyph)
	{
		SDL_RenderCopy(vs->renderer, glyph->texture, NULL, &glyph->rect);
		glyph = glyph->next;
	}
}
