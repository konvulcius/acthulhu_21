#include "ft_lemin.h"

static size_t	ft_print_last_move(t_l_data *data, t_path *start, size_t *ants)
{
	size_t	space;
	size_t	length;

	space = 0;
	while (start)
	{
		length = start->path_length - 1;
		if (data->table[*(start->path_point + length)]->room->ant_num != 0)
		{
			--(*ants);
			if (space)
				ft_printf(" ");
			ft_printf("L%u-%s", \
			data->table[*(start->path_point + length)]->room->ant_num, \
			data->table[data->rooms_count - 1]->room->name);
			space = 1;
		}
		start = start->next_path;
	}
	return (space);
}

static void		ft_print_every_move(t_l_data *data, t_path *start, size_t space)
{
	ssize_t	*node;

	while (start)
	{
		node = start->path_point + 1;
		while (*node != (ssize_t)data->rooms_count - 1)
		{
			if (data->table[*node]->room->ant_num != 0)
			{
				if (space && *(node + 1) != MAXIMAL_INT)
					ft_printf(" ");
				ft_printf("L%u-%s", \
				data->table[*node]->room->ant_num, \
				data->table[*node]->room->name);
				space = 1;
			}
			node++;
		}
		start = start->next_path;
	}
}

void			ft_lemin_print_ants_move(t_l_data *data)
{
	size_t	space;
	size_t	ants;

	ants = data->ants_num;
	while (1)
	{
		if (data->every_move)
			ft_print_every_ant(data);
		space = ft_print_last_move(data, data->all_ways, &ants);
		ft_lemin_ant_move(data, data->all_ways);
		if (!ants)
		{
			ft_printf("\n");
			break ;
		}
		ft_print_every_move(data, data->all_ways, space);
		ft_printf("\n");
	}
}

void			ft_lemin_print_all_in_one(t_l_data *data)
{
	ssize_t	count;

	count = 0;
	while (count++ < data->ants_num)
	{
		ft_printf("L%u-%s", count, \
			data->table[data->rooms_count - 1]->room->name);
		if (count != data->ants_num)
			ft_printf(" ");
	}
	ft_printf("\n");
}
