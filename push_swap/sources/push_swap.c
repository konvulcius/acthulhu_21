#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_required	values;
	int			fd;

	if (argc < 2)
		stop();
	fd = open(argv[1], O_WRONLY);
	stack_b = NULL;
	if (argc >= 3 && fd > 1)
		stack_a = arguments_reader(argc - 2, argv + 2);
	else
		stack_a = arguments_reader(argc - 1, argv + 1);
	if (fd < 1)
		fd = 1;
	if (check_accending_order(stack_a))
		stack_checker(&stack_a, &stack_b, &values, fd);
	ft_lstdel(&stack_a, content_del);
	if (fd > 1)
		close(fd);
	return (0);
}
