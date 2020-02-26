#include "visual.h"

static int	draw(t_visual *vimlx)
{
	if (*vimlx->stack_proc)
	{
		insert_instructions(vimlx->stack_a, vimlx->stack_b, vimlx->stack_proc);
		vimlx->procedure_itter->next = *vimlx->stack_proc;
		*vimlx->stack_proc = (*vimlx->stack_proc)->next;
		vimlx->procedure_itter->next->next = NULL;
		vimlx->procedure_itter = vimlx->procedure_itter->next;
		stacks_painter(vimlx);
	}
	else
	{
		ft_lstdel(&vimlx->procedure_list, content_del);
		end_of_checker(vimlx->stack_a, vimlx->stack_b, vimlx->fd);
		delete_attr(&vimlx->head);
		mlx_loop_hook(vimlx->ptr, NULL, &vimlx);
	}
	return (0);
}

static int	key_hook(int key, t_visual *vimlx)
{
	if (key == 53)
	{
		mlx_destroy_window(vimlx->ptr, vimlx->win);
		ft_lstdel(vimlx->stack_a, content_del);
		ft_lstdel(vimlx->stack_b, content_del);
		ft_lstdel(vimlx->stack_proc, content_del);
		ft_lstdel(&vimlx->procedure_list, content_del);
		stop();
	}
	return (0);
}

static int	close_win(t_visual *vimlx)
{
	mlx_destroy_window(vimlx->ptr, vimlx->win);
	exit(0);
}

void		ft_visual(t_list **stack_a, t_list **stack_b, \
				t_list **stack_proc, int fd)
{
	t_visual vimlx;

	vimlx.fd = fd;
	vimlx.stack_a = stack_a;
	vimlx.stack_b = stack_b;
	vimlx.stack_proc = stack_proc;
	vimlx.procedure_list = ft_lstnew(NULL, 0);
	vimlx.procedure_itter = vimlx.procedure_list;
	parse_min_high(&vimlx);
	if (!parse_attr(&vimlx))
		return ;
	vimlx.head = create_attr_stack(*stack_a);
	take_param(&vimlx);
	vimlx.ptr = mlx_init();
	vimlx.win = mlx_new_window(vimlx.ptr, WIN_WIDTH, WIN_LENGTH, "push_swap");
	stacks_painter(&vimlx);
	mlx_loop_hook(vimlx.ptr, draw, &vimlx);
	mlx_key_hook(vimlx.win, key_hook, &vimlx);
	mlx_hook(vimlx.win, 17, 0, close_win, &vimlx);
	mlx_loop(vimlx.ptr);
}
