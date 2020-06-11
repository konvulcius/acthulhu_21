#include "ft_lemin.h"

void	ft_delete_usefully_paths(t_l_data *data)
{
	t_path		*temp;
	t_path		*prev;

	temp = data->all_ways;
	while (temp && temp->next_path)
	{
		prev = temp;
		temp = temp->next_path;
		if (!ft_lemin_decrease_ways_count(data, temp))
		{
			prev->next_path = NULL;
			ft_delete_paths(temp);
			break ;
		}
	}
}

void	ft_print_paths(t_l_data *data)
{
	t_path		*temp;
	ssize_t		*node;
	size_t		count;

	temp = data->all_ways;
	count = 1;
	ft_printf("==========PATHS==========\n");
	while (temp)
	{
		node = temp->path_point;
		ft_printf("%u) path's length = %u\n  ", count++, temp->path_length);
		while ((size_t)*node != data->rooms_count - 1)
			ft_printf("%s -> ", data->table[*node++]->room->name);
		ft_printf("%s\n", data->table[*node]->room->name);
		temp = temp->next_path;
	}
	ft_putendl("");
}
