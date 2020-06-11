#include "ft_lemin.h"

size_t		ft_lemin_count_rooms(t_list *begin)
{
	size_t	count;

	count = 0;
	while (begin)
	{
		if (!ft_strncmp((char*)begin->content, "#", 1))
		{
			begin = begin->next;
			continue ;
		}
		if (!ft_parse_room((char*)begin->content))
			break ;
		++count;
		begin = begin->next;
	}
	return (count);
}

void		ft_fill_array(t_l_data *data, t_list **begin_list)
{
	size_t	index;

	index = 0;
	while (*begin_list && index < data->table_curr_size)
	{
		ft_parse_comment(data, begin_list);
		*begin_list = (*begin_list)->next;
		++index;
	}
	if (!data->start || !data->end)
		ft_error_here();
	ft_lstadd(&data->rooms, data->start);
	ft_lemin_lst_add_last(data->rooms, data->end);
}

void		ft_lemin_fill_data(t_list *begin_list, t_l_data *data)
{
	data->begin_list = begin_list;
	ft_lemin_take_number_of_ants(data, &begin_list);
	data->table_curr_size = ft_lemin_count_rooms(begin_list);
	ft_fill_array(data, &begin_list);
	data->rooms_count = data->table_curr_size * 2 - 2;
	if (!(data->table = (t_row **)ft_memalloc(sizeof(t_row *) * \
		data->rooms_count)))
		ft_allocation_error();
	ft_lemin_init_table(data);
	ft_fill_links(data, &begin_list);
	if (!((t_l_room*)data->start->content)->links_out || \
		!((t_l_room*)data->end->content)->links_out)
		ft_error_here();
}
