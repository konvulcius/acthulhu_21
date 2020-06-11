/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <marvin@fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 03:45:57 by lliza             #+#    #+#             */
/*   Updated: 2020/04/22 14:07:17 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

t_l_data		*ft_lemin_init_data(void)
{
	t_l_data	*data;

	if (!(data = (t_l_data *)malloc(sizeof(t_l_data))))
		return (NULL);
	data->start = NULL;
	data->end = NULL;
	data->begin_list = NULL;
	data->ants_num = 0;
	data->rooms = NULL;
	data->table = NULL;
	data->table_curr_size = 0;
	data->num_of_paths = 0;
	data->rooms_count = 0;
	data->paths_box = NULL;
	data->paths_max_len = 0;
	data->all_ways = NULL;
	data->all_in_one = 0;
	data->every_move = 0;
	data->print_data = 0;
	data->print_path = 0;
	data->print_help = 0;
	data->paths_sum = MAXIMAL_INT;
	return (data);
}

static t_list	*ft_lemin_init_table_inner(t_l_data *data, size_t *j)
{
	size_t	i;
	t_list	*rooms;

	rooms = data->rooms;
	i = *j - 1;
	while (++i < data->table_curr_size - 1)
	{
		if (!(data->table[i] = (t_row *)malloc(sizeof(t_row))))
			ft_allocation_error();
		data->table[i]->room = rooms->content;
		data->table[i]->room->t_row_index = i;
		if (i == 0)
		{
			data->table[i]->len = 0;
			data->table[i]->prev_index = 0;
		}
		else
		{
			data->table[i]->len = MAXIMAL_INT;
			data->table[i]->prev_index = MAXIMAL_INT;
		}
		rooms = rooms->next;
	}
	*j = i;
	return (rooms);
}

static t_list	*ft_lemin_ways_box_init(t_l_data *data, size_t *j)
{
	size_t	i;

	data->paths_box = (t_avl**)ft_memalloc(sizeof(t_avl*) * \
		data->rooms_count);
	if (data->paths_box == NULL)
		ft_allocation_error();
	i = 0;
	while (i < data->rooms_count)
	{
		data->paths_box[i] = NULL;
		i++;
	}
	return (ft_lemin_init_table_inner(data, j));
}

t_l_room		*ft_lemin_init_room(char *name, int x, int y)
{
	t_l_room *room;

	if (!(room = (t_l_room *)malloc(sizeof(t_l_room))))
		return (NULL);
	room->name = (char *)ft_memalloc(ft_strlen(name) + 1);
	if (!room->name)
		return (NULL);
	room->ant_num = 0;
	room->links_out = NULL;
	room->val = 0;
	room->type = 0;
	room->x = x;
	room->y = y;
	room->t_row_index = 0;
	ft_strcpy(room->name, name);
	room->out = NULL;
	return (room);
}

void			ft_lemin_init_table(t_l_data *data)
{
	size_t	i;
	t_list	*rooms;

	i = 0;
	rooms = ft_lemin_ways_box_init(data, &i);
	while (i < data->table_curr_size * 2 - 3)
	{
		if (!(data->table[i] = (t_row *)malloc(sizeof(t_row))))
			ft_allocation_error();
		data->table[i]->room = NULL;
		data->table[i]->len = MAXIMAL_INT;
		data->table[i]->prev_index = MAXIMAL_INT;
		++i;
	}
	data->table_curr_size--;
	if (!(data->table[i] = (t_row *)malloc(sizeof(t_row))))
		ft_allocation_error();
	data->table[i]->room = rooms->content;
	data->table[i]->room->t_row_index = i;
	data->table[i]->len = MAXIMAL_INT;
	data->table[i]->prev_index = MAXIMAL_INT;
}
