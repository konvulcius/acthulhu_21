#include "push_swap.h"

static void	read_flags(int argc, char **argv, t_args *flags)
{
	if (argc < 2)
		stop();
	flags->fd = open(argv[1], O_RDONLY);
	if (flags->fd > 1 && argc > 2)
	{
		flags->visual = ft_strcmp(argv[2], "-v");
	}
	else
	{
		flags->visual = ft_strcmp(argv[1], "-v");
		if (!flags->visual && argc > 2)
			flags->fd = open(argv[2], O_RDONLY);
	}
}

int			main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack_proc;
	t_args	flags;

	read_flags(argc, argv, &flags);
	if (argc > 2 && flags.fd > 1 && !flags.visual)
		stack_a = arguments_reader(argc - 3, argv + 3);
	else if (argc > 2 && (flags.fd > 1 || !flags.visual))
		stack_a = arguments_reader(argc - 2, argv + 2);
	else
		stack_a = arguments_reader(argc - 1, argv + 1);
	if (flags.fd < 2)
		flags.fd = 0;
	stack_proc = instructions_reader(flags.fd);
	stack_b = NULL;
	if (!flags.visual)
		ft_visual(&stack_a, &stack_b, &stack_proc, flags.fd);
	procedure_itter(&stack_a, &stack_b, &stack_proc, flags.fd);
	return (0);
}
