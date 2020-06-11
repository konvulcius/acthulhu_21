#include "vs.h"
#include "libft.h"

static void	init_glyph_array_colors(t_vm *vm, t_vs *vs)
{
	size_t i;
	size_t color_i;
	size_t offset;
	size_t end;

	i = 0;
	color_i = 0;
	offset = MEM_SIZE / vm->champs_num;
	while (i < MEM_SIZE)
	{
		if (i % offset == 0)
		{
			color_i += 1;
			end = get_champ_size(vm, color_i);
			while (end > 0)
			{
				vs->color_is[i++] = color_i % 6;
				end -= 1;
			}
		}
		else
			vs->color_is[i] = 0;
		++i;
	}
}

t_glyph		**init_glyph_array(t_vm *vm, t_vs *vs)
{
	size_t	zij[3];
	char	text[3];
	t_glyph	**array;

	if (!(array = (t_glyph **)malloc(sizeof(t_glyph *) * MEM_SIZE)))
		vs_exit_malloc_failure(vm, vs);
	ft_bzero(zij, 3 * sizeof(size_t));
	init_glyph_array_colors(vm, vs);
	while (zij[1] < MEM_SIZE)
	{
		ft_bzero(text, 3);
		sprintf(text, "%02x", (int)vm->arena[zij[1]]);
		array[zij[1]] = init_glyph(vm, vs, 5 + zij[0]++ * 20, 5 + zij[2]);
		array[zij[1]]->surface = init_srfc(vm, vs->font,
			text, (SDL_Color *)&vs->colors[vs->color_is[zij[1]] % 6]);
		init_texture(vm, vs, array[zij[1]]);
		zij[1]++;
		if (zij[0] > 63)
		{
			zij[2] += 15;
			zij[0] = 0;
		}
	}
	return (array);
}

void		render_glyph_array\
	(t_glyph **array, size_t size, SDL_Renderer *renderer)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		SDL_RenderCopy(renderer, array[i]->texture, NULL, &array[i]->rect);
		++i;
	}
}

void		vs_glyph_array_free(t_glyph **array, size_t size)
{
	size_t	i;

	if (array)
	{
		i = 0;
		while (i < size)
		{
			if (array[i])
				vs_glyph_free(&array[i]);
			++i;
		}
	}
}
