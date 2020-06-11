#include "ft_lemin.h"

static void	ft_delete_paths_box(t_l_data *data)
{
	ssize_t	index;

	index = data->rooms_count - 1;
	while (index >= 0)
		ft_avl_full_delete(&data->paths_box[index--]);
	free(data->paths_box);
}

static void	ft_delete_table(t_l_data *data)
{
	ssize_t	index;

	index = data->rooms_count - 1;
	while (index >= 0)
		free(data->table[index--]);
	free(data->table);
}

static void	ft_delete_rooms(t_l_data *data)
{
	t_list		*delete;

	while (data->rooms)
	{
		ft_avl_full_delete(&((t_l_room*)data->rooms->content)->links_out);
		free(data->rooms->content);
		delete = data->rooms;
		data->rooms = data->rooms->next;
		free(delete);
	}
}

static void	ft_delete_ways(t_l_data *data)
{
	t_path	*delete;

	while (data->all_ways)
	{
		free(data->all_ways->path_point);
		delete = data->all_ways;
		data->all_ways = data->all_ways->next_path;
		free(delete);
	}
}

void		ft_lemin_clear_data(t_l_data **data)
{
	ft_delete_paths_box(*data);
	ft_delete_table(*data);
	ft_delete_rooms(*data);
	ft_delete_ways(*data);
	free(*data);
}
