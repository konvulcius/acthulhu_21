/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_suurballe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <marvin@fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 11:23:53 by lliza             #+#    #+#             */
/*   Updated: 2020/04/22 14:07:33 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

t_avl		*ft_avl_tree_init_with_value(size_t index, int value)
{
	t_avl	*new_node;

	new_node = (t_avl*)ft_memalloc(sizeof(t_avl));
	if (!new_node)
		ft_allocation_error();
	new_node->index = index;
	new_node->value = value;
	new_node->height = 1;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

t_avl		*ft_insert_node_with_value(t_avl *node, size_t index, int value)
{
	if (!node)
		return (ft_avl_tree_init_with_value(index, value));
	if (index < node->index)
		node->left = ft_insert_node(node->left, index);
	else
		node->right = ft_insert_node(node->right, index);
	return (ft_balance(node));
}

t_l_room	*ft_lemin_make_in_2(t_l_data *data, t_row *row)
{
	t_l_room	*in_copy;
	size_t		prev_i;

	prev_i = row->prev_index;
	in_copy = (t_l_room *)malloc(sizeof(t_l_room));
	if (!in_copy)
		ft_allocation_error();
	ft_memcpy(in_copy, row->room, sizeof(t_l_room));
	in_copy->type = 1;
	in_copy->out = row->room;
	in_copy->links_out = NULL;
	in_copy->t_row_index = data->table_curr_size;
	data->table[data->table_curr_size]->room = in_copy;
	data->table[data->table_curr_size]->len = MAXIMAL_INT;
	data->table[data->table_curr_size]->prev_index = MAXIMAL_INT;
	data->table_curr_size += 1;
	ft_lemin_lst_add_second(data->rooms, in_copy);
	return (in_copy);
}

void		ft_lemin_split_all(t_l_data *data, t_l_room *end)
{
	t_l_room	*room;
	t_l_room	*out_cpy;
	t_l_room	*in_cpy;
	t_list		*lst;

	lst = data->rooms;
	while (lst)
	{
		room = lst->content;
		if (!room->type && room != data->start->content && room != end)
		{
			out_cpy = room;
			out_cpy->type = 2;
			in_cpy = ft_lemin_make_in_2(data,
				data->table[out_cpy->t_row_index]);
			in_cpy->links_out = ft_insert_node_with_value(in_cpy->links_out,
				out_cpy->t_row_index, 0);
			ft_lemin_avl_change_neighbours_links_out(data->table,
				out_cpy->links_out, out_cpy->t_row_index, in_cpy->t_row_index);
		}
		lst = lst->next;
	}
}

void		ft_lemin_suurballe(t_l_data *data, void (*algo)(t_l_data *data))
{
	ft_lemin_split_all(data, data->end->content);
	algo(data);
	if (data->table[data->rooms_count - 1]->prev_index == 0)
	{
		data->all_in_one = 1;
		return ;
	}
	while (ft_check_new_way(data))
	{
		ft_lemin_reset_table(data);
		algo(data);
	}
}
