/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_fill_rooms.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <marvin@fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:11:18 by acthulhu          #+#    #+#             */
/*   Updated: 2020/04/22 03:34:11 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	ft_lemin_lst_add_last(t_list *lst, t_list *new_end)
{
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
		}
		lst->next = new_end;
	}
}

size_t	ft_lemin_check_room_parameters_duplicate\
	(t_list *lst, char *name, char *x, char *y)
{
	while (lst)
	{
		if (!ft_strcmp(((t_l_room *)lst->content)->name, name))
			return (1);
		if (((t_l_room *)lst->content)->x == ft_atoll(x) &&
			((t_l_room *)lst->content)->y == ft_atoll(y))
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	ft_insert_room_in_list_sub(t_l_data *data, char **line, size_t type)
{
	t_list		*new_room_list;

	if ((new_room_list = ft_lstnew(NULL, 0)))
	{
		new_room_list->content = ft_lemin_init_room(line[0],
													ft_atoll(line[1]),
													ft_atoll(line[2]));
		new_room_list->content_size = sizeof(t_l_room*);
	}
	else
		ft_allocation_error();
	if (type == 4)
		data->end = new_room_list;
	else if (type == 2)
		data->start = new_room_list;
	else
		ft_lstadd(&data->rooms, new_room_list);
}

void	ft_insert_room_in_list(t_l_data *data, char *s, size_t type)
{
	char		**line;

	line = ft_strsplit(s, ' ');
	if (!line)
		ft_allocation_error();
	if (line[0] && line[1] && line[2] && !line[3])
	{
		if (ft_only_dig_validation(line[1]) && \
			ft_only_dig_validation(line[2]) && \
			ft_digit_compare(ft_atoll(line[1])) && \
			ft_digit_compare(ft_atoll(line[2])) &&
			!ft_lemin_check_room_parameters_duplicate(data->rooms,
													line[0],
													line[1],
													line[2]))
		{
			ft_insert_room_in_list_sub(data, line, type);
		}
		else
			ft_error_here();
	}
	ft_delete_strings(line);
	free(line);
}

void	ft_parse_comment(t_l_data *data, t_list **begin_list)
{
	size_t	room_type;

	room_type = 3;
	while (*begin_list && !ft_strncmp((char*)(*begin_list)->content, "#", 1))
	{
		if (!ft_strcmp((char*)(*begin_list)->content, "##start"))
		{
			if (data->start)
				ft_error_here();
			room_type = 2;
		}
		else if (!ft_strcmp((char*)(*begin_list)->content, "##end"))
		{
			if (data->end)
				ft_error_here();
			room_type = 4;
		}
		*begin_list = (*begin_list)->next;
	}
	ft_insert_room_in_list(data, (*begin_list)->content, room_type);
}
