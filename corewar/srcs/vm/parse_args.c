#include "ft_corewar.h"
#include "libft.h"

static int		parse_n(t_vm *vm, int ac, char **av, int *i)
{
	int32_t		temp;

	if (*i + 2 < ac && ft_only_dig_validation(av[*i + 1]) &&
		file_is_champ(av[*i + 2]))
	{
		temp = ft_atoi(av[*i + 1]);
		if (temp > vm->champs_num || temp < 0)
			usage_exit(vm);
		*i += 2;
		return (temp);
	}
	else
		usage_exit(vm);
	return (0);
}

static void		parse_dump(t_vm *vm, int ac, char **av, int *i)
{
	if (*i + 1 < ac && ft_only_dig_validation(av[*i + 1]))
	{
		vm->cycle_to_dump = ft_atoi(av[*i + 1]);
		if (av[*i][1] == 's')
		{
			vm->rise_dump = vm->cycle_to_dump;
			vm->flags |= DUMP_GO;
		}
		else if (av[*i][1] == 'd' && av[*i][2] == '\0')
			vm->flags |= DUMP_64;
		*i += 1;
	}
	else
		usage_exit(vm);
}

static void		parse_instr(t_vm *vm, int ac, char **av, int *i)
{
	if (*i + 1 < ac && ft_only_dig_validation(av[*i + 1]))
	{
		vm->instructions = ft_atoi(av[*i + 1]);
		*i += 1;
	}
	else
		usage_exit(vm);
}

static int		parse_flags(t_vm *vm, int ac, char **av, int *i)
{
	while (*i < ac)
	{
		if (file_is_champ(av[*i]))
			return (0);
		if (!(ft_strcmp(av[*i], "-n")))
			return (parse_n(vm, ac, av, i));
		else if (!(ft_strcmp(av[*i], "-dump")) || !(ft_strcmp(av[*i], "-d")) ||
				!(ft_strcmp(av[*i], "-s")))
			parse_dump(vm, ac, av, i);
		else if (!(ft_strcmp(av[*i], "-v")))
			parse_instr(vm, ac, av, i);
		else if (av[*i][0] == '-')
		{
			if (ft_strchr(av[*i], 'a'))
				vm->flags |= AFF;
			if (ft_strchr(av[*i], 'q'))
				vm->flags |= NCURSES;
			if (ft_strchr(av[*i], 'h'))
				vm->flags |= USAGE;
		}
		else
			vm_exit_sys_failure(vm, "Error: Some file is not champ\n");
		*i += 1;
	}
	return (0);
}

void			parse(t_vm *vm, int ac, char **av)
{
	t_sp	*sp;
	int32_t	i;
	int32_t	champ_num;

	i = 1;
	if (ac < 2)
		usage_exit(vm);
	while (i < ac)
	{
		champ_num = parse_flags(vm, ac, av, &i);
		if (i >= ac)
			break ;
		sp = init_sp(vm, parse_champ(vm, av[i], champ_num));
		add_sp_to_list(vm, sp, 0);
		i++;
	}
	vm->new_sp_num = vm->champs_num + 1;
	sort_champ(vm);
}
