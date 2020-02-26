#include "push_swap.h"

void	clear_window(t_visual *vimlx)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_LENGTH)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (x <= 1 || y <= 1 || \
				(y >= WIN_LENGTH / 2 - 1 && y <= WIN_LENGTH / 2 && \
				x < WIN_WIDTH - 200) || \
				y >= WIN_LENGTH - 2 || x >= WIN_WIDTH - 2 || \
				(x >= WIN_WIDTH - 201 && x <= WIN_WIDTH - 200))
				mlx_pixel_put(vimlx->ptr, vimlx->win, x, y, WHITE);
			++x;
		}
		++y;
	}
}

void	print_stack_length(t_visual *vimlx)
{
	int		y_a_stack;
	int		y_b_stack;
	int		x;
	int		value;
	char	*string;

	x = 50;
	y_a_stack = WIN_LENGTH / 2 - 70 - parse_length(vimlx, vimlx->max);
	y_b_stack = WIN_LENGTH - 70 - parse_length(vimlx, vimlx->max);
	value = (int)*(long long*)vimlx->max->content;
	string = ft_itoa(value);
	mlx_string_put(vimlx->ptr, vimlx->win, x, y_a_stack, WHITE, string);
	mlx_string_put(vimlx->ptr, vimlx->win, x, y_b_stack, WHITE, string);
	ft_strdel(&string);
	y_a_stack = WIN_LENGTH / 2 - 70;
	y_b_stack = WIN_LENGTH - 70;
	value = (int)*(long long*)vimlx->min->content;
	string = ft_itoa(value);
	mlx_string_put(vimlx->ptr, vimlx->win, x, y_a_stack, WHITE, string);
	mlx_string_put(vimlx->ptr, vimlx->win, x, y_b_stack, WHITE, string);
	ft_strdel(&string);
}

void	print_stack_name(t_visual *vimlx)
{
	int x;
	int y;

	x = WIN_WIDTH / 2 - 200;
	y = 10;
	mlx_string_put(vimlx->ptr, vimlx->win, x, y, WHITE, "Stack A");
	y = WIN_LENGTH / 2 + 10;
	mlx_string_put(vimlx->ptr, vimlx->win, x, y, WHITE, "Stack B");
}

void	print_procedure(t_visual *vimlx, t_list *start, int x, int y)
{
	if (start && start->next)
		print_procedure(vimlx, start->next, x, y - 40);
	if (start && start->next && !start->next->next)
	{
		mlx_string_put(vimlx->ptr, vimlx->win, x, y, GREEN, \
			(char*)start->next->content);
	}
	else if (start && start->next && y < WIN_LENGTH)
	{
		mlx_string_put(vimlx->ptr, vimlx->win, x, y, WHITE, \
			(char*)start->next->content);
	}
}

void	print_count_proc(t_visual *vimlx, t_list *proc_list)
{
	int		count;
	char	*string;

	count = 0;
	while (proc_list)
	{
		proc_list = proc_list->next;
		++count;
	}
	mlx_string_put(vimlx->ptr, vimlx->win, WIN_WIDTH - 500, 10, WHITE, \
			"Number of instructions:");
	string = ft_itoa(count);
	mlx_string_put(vimlx->ptr, vimlx->win, WIN_WIDTH - 260, 10, WHITE, \
			string);
	ft_strdel(&string);
}
