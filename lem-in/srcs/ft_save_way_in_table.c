#include "ft_lemin.h"

static t_single	*ft_init_single_way(t_row *row)
{
	t_single	*way;

	way = (t_single*)ft_memalloc(sizeof(t_single));
	if (!way)
		ft_allocation_error();
	way->room = row->room;
	way->len = row->len - 1;
	way->next = NULL;
	return (way);
}

static void		ft_add_room_at_start_way(t_single **start, t_single *prev)
{
	if (!start || !prev)
		return ;
	if (!*start)
		*start = prev;
	else
	{
		prev->next = *start;
		*start = prev;
	}
}

static t_single	*ft_find_new_way(t_l_data *data)
{
	t_single	*start;
	size_t		index_table;

	index_table = data->rooms_count - 1;
	if (data->table[index_table]->prev_index == MAXIMAL_INT)
		return (NULL);
	start = NULL;
	while (index_table != 0)
	{
		ft_add_room_at_start_way(&start,
								ft_init_single_way(data->table[index_table]));
		index_table = data->table[index_table]->prev_index;
	}
	ft_add_room_at_start_way(&start,
							ft_init_single_way(data->table[index_table]));
	return (start);
}

size_t			ft_save_new_way(t_l_data *data, t_single **start)
{
	t_single	*new_way;

	new_way = ft_find_new_way(data);
	if (!new_way)
		return (0);
	*start = new_way;
	while (new_way->next)
	{
		data->paths_box[new_way->room->t_row_index] = \
			ft_insert_node(data->paths_box[new_way->room->t_row_index], \
			new_way->next->room->t_row_index);
		new_way = new_way->next;
	}
	return (1);
}

void			ft_delete_single_way(t_single **start, t_single *end)
{
	t_single	*tmp;

	if (start)
	{
		while (*start != end)
		{
			tmp = *start;
			*start = (*start)->next;
			free(tmp);
		}
		if (*start)
		{
			tmp = *start;
			*start = (*start)->next;
			free(tmp);
		}
	}
}
