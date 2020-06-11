#include "ft_lemin.h"

ssize_t	ft_find_position(t_l_data *data, char *name)
{
	ssize_t	index;

	index = 0;
	while (index < (ssize_t)data->rooms_count)
	{
		if (!data->table[index]->room)
		{
			++index;
			continue ;
		}
		if (!ft_strcmp(data->table[index]->room->name, name))
			break ;
		++index;
	}
	if (index == (ssize_t)data->rooms_count)
		return (-1);
	return (index);
}

size_t	ft_parse_links(t_l_data *data, t_list **begin_list)
{
	char	**names;
	char	check;
	ssize_t	link_1;
	ssize_t	link_2;

	names = ft_strsplit((char*)(*begin_list)->content, '-');
	check = 0;
	if (names && *names && **names && names[1] && !names[2])
	{
		link_1 = ft_find_position(data, names[0]);
		link_2 = ft_find_position(data, names[1]);
		if (link_1 > -1 && link_2 > -1)
		{
			data->table[link_1]->room->links_out = \
				ft_insert_node(data->table[link_1]->room->links_out, link_2);
			data->table[link_2]->room->links_out = \
				ft_insert_node(data->table[link_2]->room->links_out, link_1);
			check = 1;
		}
	}
	ft_delete_strings(names);
	free(names);
	return (check);
}

void	ft_fill_links(t_l_data *data, t_list **begin_list)
{
	t_list	*temp;

	temp = data->begin_list;
	while (*begin_list)
	{
		if (!ft_strncmp((char*)(*begin_list)->content, "#", 1))
		{
			if (!ft_strcmp((char*)(*begin_list)->content, "##start"))
				ft_error_here();
			else if (!ft_strcmp((char*)(*begin_list)->content, "##end"))
				ft_error_here();
		}
		else if (!ft_parse_links(data, begin_list))
		{
			while (temp->next != (*begin_list))
				temp = temp->next;
			temp->next = NULL;
			break ;
		}
		*begin_list = (*begin_list)->next;
	}
	ft_lstdel(begin_list, ft_delete_content);
}
