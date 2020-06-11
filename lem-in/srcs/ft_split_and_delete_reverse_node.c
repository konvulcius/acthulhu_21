/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_and_delete_reverse_node.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:11:18 by acthulhu          #+#    #+#             */
/*   Updated: 2020/04/21 14:38:19 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static size_t	ft_find_in_room(t_l_data *data, t_single *way_node, t_avl *root)
{
	size_t	left;
	size_t	right;

	if (root)
	{
		if (data->table[root->index]->room->out ==
			data->table[way_node->room->t_row_index]->room)
			return (data->table[root->index]->room->t_row_index);
		left = ft_find_in_room(data, way_node, root->left);
		if (left)
			return (left);
		right = ft_find_in_room(data, way_node, root->right);
		if (right)
			return (right);
	}
	return (0);
}

static void		ft_split(t_l_data *data, t_single *way_node, size_t index)
{
	if (way_node->room->out)
	{
		ft_lemin_avl_find_node(way_node->next->room->links_out,
			way_node->room->t_row_index)->value = 0;
	}
	else
	{
		ft_lemin_avl_find_node(way_node->next->room->links_out,
			way_node->room->t_row_index)->value = -1;
	}
	if (index == 0 || (way_node->next->next &&
	way_node->next->next->room->t_row_index == data->rooms_count - 1))
	{
		way_node->next->next->room->links_out =
			ft_remove_node(way_node->next->next->room->links_out,
			way_node->room->t_row_index);
	}
	else if (way_node->next->next && way_node->next->next->room->out)
	{
		way_node->next->next->room->out->links_out =
			ft_remove_node(way_node->next->next->room->out->links_out,
			way_node->room->t_row_index);
	}
}

static void		ft_remove_cross_tube_sub(t_l_data *data, t_avl **paths_box,
			t_single **way_node)
{
	if (data->table[(*way_node)->room->t_row_index]->room->out)
	{
		if (ft_check_exit(paths_box, (*way_node)->next))
		{
			(*way_node)->room->out->links_out =
				ft_insert_node((*way_node)->room->out->links_out,
				(*way_node)->next->next->room->t_row_index);
		}
		else
		{
			(*way_node)->room->out->links_out =
				ft_insert_node((*way_node)->room->out->links_out,
				ft_find_in_room(data, (*way_node)->next,
				(*way_node)->next->next->next->room->links_out));
		}
	}
}

static void		ft_remove_cross_tube(t_l_data *data, t_avl **paths_box,
			t_single **way_node)
{
	while (ft_check_exit(paths_box, *way_node))
	{
		if (!(*way_node)->room->out)
		{
			ft_lemin_avl_find_node((*way_node)->next->room->links_out,
				(*way_node)->room->t_row_index)->value = 0;
		}
		ft_delete_reverse_node(paths_box, (*way_node)->room->t_row_index,
			(*way_node)->next->room->t_row_index);
		ft_remove_cross_tube_sub(data, paths_box, way_node);
		*way_node = (*way_node)->next;
		(*way_node)->room->links_out =
			ft_remove_node((*way_node)->room->links_out,
			(*way_node)->next->room->t_row_index);
		(*way_node)->next->room->links_out =
			ft_insert_node((*way_node)->next->room->links_out,
			(*way_node)->room->t_row_index);
	}
}

void			ft_2_and_3_step(t_l_data *data, t_avl **paths_box,
			t_single *way_node)
{
	size_t		index;

	while (way_node && way_node->next)
	{
		way_node->room->links_out =
		ft_remove_node(way_node->room->links_out,
			way_node->next->room->t_row_index);
		way_node->next->room->links_out =
		ft_insert_node(way_node->next->room->links_out,
			way_node->room->t_row_index);
		index = way_node->room->t_row_index;
		if (index == 0 || (paths_box[index] && !paths_box[index]->left &&
			!paths_box[index]->right))
			ft_split(data, way_node, index);
		else
		{
			ft_remove_cross_tube(data, paths_box, &way_node);
			way_node->next->next->room->links_out =
				ft_remove_node(way_node->next->next->room->links_out,
				ft_find_in_room(data, way_node,
				way_node->next->next->room->links_out));
		}
		way_node = way_node->next;
	}
}
