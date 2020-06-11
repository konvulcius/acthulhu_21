#include "ft_lemin.h"

static t_path	*ft_init_path(t_l_data *data)
{
	t_path	*path;

	if (!(path = (t_path *)ft_memalloc(sizeof(t_path))))
		ft_allocation_error();
	if (!(path->path_point = (ssize_t *)ft_memalloc(sizeof(ssize_t) * \
			(data->paths_max_len + 2))))
		ft_allocation_error();
	return (path);
}

static t_path	*ft_lemin_get_one_way(t_l_data *data)
{
	t_path	*path;
	size_t	index;
	size_t	prev;
	size_t	i;

	path = ft_init_path(data);
	index = 0;
	i = 0;
	path->path_point[i++] = index;
	while (index != data->rooms_count - 1)
	{
		prev = index;
		index = data->paths_box[index]->index;
		path->path_point[i] = index;
		if (data->table[prev]->room->out == data->table[index]->room)
		{
			index = data->paths_box[index]->index;
			path->path_point[i] = index;
		}
		i++;
	}
	path->path_point[i] = MAXIMAL_INT;
	path->path_length = i - 1;
	path->next_path = NULL;
	return (path);
}

static void		ft_sort_paths(t_path **new_path)
{
	t_path	*temp;
	t_path	*first;

	first = *new_path;
	temp = NULL;
	while (first && first->next_path)
	{
		if (first->path_length > first->next_path->path_length)
		{
			if (*new_path == first)
				*new_path = first->next_path;
			if (temp)
				temp->next_path = first->next_path;
			temp = first->next_path;
			first->next_path = first->next_path->next_path;
			temp->next_path = first;
			first = *new_path;
			temp = NULL;
			continue ;
		}
		temp = first;
		first = first->next_path;
	}
}

void			ft_lemin_get_all_ways(t_l_data *data)
{
	t_path	*temp;

	if (data->all_in_one)
		return ;
	if (data->paths_box[0] == NULL)
		ft_error_here();
	data->all_ways = ft_lemin_get_one_way(data);
	data->paths_box[0] = \
		ft_remove_node(data->paths_box[0], \
		data->paths_box[0]->index);
	temp = data->all_ways;
	while (data->paths_box[0])
	{
		temp->next_path = ft_lemin_get_one_way(data);
		data->paths_box[0] = \
			ft_remove_node(data->paths_box[0], \
			data->paths_box[0]->index);
		temp = temp->next_path;
	}
	ft_sort_paths(&data->all_ways);
	ft_delete_usefully_paths(data);
	if (data->print_path)
		ft_print_paths(data);
}

void			ft_delete_paths(t_path *paths)
{
	t_path	*cur_path;

	while (paths)
	{
		cur_path = paths;
		paths = paths->next_path;
		free(cur_path->path_point);
		free(cur_path);
	}
}
