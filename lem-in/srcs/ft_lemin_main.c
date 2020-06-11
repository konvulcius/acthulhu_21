#include "ft_lemin.h"

static void	ft_subfunc_main(t_l_data *data)
{
	ft_lemin_get_all_ways(data);
	if (!data->print_data && !data->print_path)
		ft_lemin_print_map(data);
	if (data->all_in_one)
		ft_lemin_print_all_in_one(data);
	else
		ft_lemin_print_ants_move(data);
}

static void	ft_read_flags(t_l_data *data, int ac, char **av)
{
	int		i;

	if (ac == 0)
		return ;
	i = 0;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if (ft_strchr(av[i], 'a'))
				data->every_move = 1;
			if (ft_strchr(av[i], 'd'))
				data->print_data = 1;
			if (ft_strchr(av[i], 'p'))
				data->print_path = 1;
			if (ft_strchr(av[i], 'h'))
				data->print_help = 1;
		}
		i++;
	}
}

static void	ft_print_help(void)
{
	ft_printf("%{yellow}usage:%{eoc}\n\t%{blue}./lem-in [flags] < map%{eoc}\n");
	ft_printf("\t%{blue}./lem-in [flags] <type by hands> <Ctrl+D>%{eoc}\n\n");
	ft_printf("%{yellow}example:%{eoc}\n\t%{blue}./lem-in < some.map%{eoc}\n");
	ft_printf("\t%{blue}./lem-in -a < some.map%{eoc}\n");
	ft_printf("\t%{blue}./lem-in -d < some.map%{eoc}\n");
	ft_printf("\t%{blue}./lem-in -ad < some.map%{eoc}\n\n");
	ft_printf("%{yellow}flags:%{eoc}\n");
	ft_printf("\t%{blue}%-6s- print every move of each ant%{eoc}\n", "a");
	ft_printf("\t%{blue}%-6s- print input data%{eoc}\n", "d");
	ft_printf("\t%{blue}%-6s- print paths found%{eoc}\n", "p");
	ft_printf("\t%{blue}%-6s- help%{eoc}\n", "h");
	exit(0);
}

int			main(int ac, char **av)
{
	t_l_data	*data_bf;

	if (!(data_bf = ft_lemin_init_data()))
		ft_allocation_error();
	ft_read_flags(data_bf, ac - 1, av + 1);
	if (data_bf->print_help)
		ft_print_help();
	ft_read_input(data_bf);
	ft_lemin_suurballe(data_bf, bf);
	ft_subfunc_main(data_bf);
	ft_lstdel(&data_bf->begin_list, ft_delete_content);
	ft_lemin_clear_data(&data_bf);
	return (0);
}
