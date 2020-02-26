#include "push_swap.h"

void	draw_stack(t_visual *vimlx, t_list *stack)
{
	int	y_start;
	int x;
	int	y;
	int color;
	int	width;

	if (stack == *vimlx->stack_a)
		y_start = WIN_LENGTH / 2 - 50;
	else
		y_start = WIN_LENGTH - 50;
	x = (WIN_WIDTH - 200) / 10;
	while (stack)
	{
		y = y_start - parse_length(vimlx, stack);
		color = parse_color(vimlx, stack);
		while (y++ < y_start)
		{
			width = vimlx->width;
			while (width-- > 0)
				mlx_pixel_put(vimlx->ptr, vimlx->win, x + width, y, color);
		}
		x += vimlx->width;
		stack = stack->next;
	}
}

int		choose_sleep_time(t_visual *vimlx)
{
	if (vimlx->count > 100)
		return (1000);
	if (vimlx->count > 50)
		return (50000);
	if (vimlx->count > 25)
		return (150000);
	return (300000);
}

void	stacks_painter(t_visual *vimlx)
{
	int		y;
	t_list	*temp;

	usleep((useconds_t)choose_sleep_time(vimlx));
	mlx_clear_window(vimlx->ptr, vimlx->win);
	clear_window(vimlx);
	print_stack_name(vimlx);
	print_stack_length(vimlx);
	draw_stack(vimlx, *vimlx->stack_a);
	draw_stack(vimlx, *vimlx->stack_b);
	print_count_proc(vimlx, vimlx->procedure_list);
	temp = vimlx->procedure_list;
	y = -30;
	while (temp->next)
	{
		temp = temp->next;
		y += 40;
	}
	print_procedure(vimlx, vimlx->procedure_list, WIN_WIDTH - 120, y);
}
