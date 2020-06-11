/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_find_way_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:56:35 by acthulhu          #+#    #+#             */
/*   Updated: 2020/04/21 14:57:14 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static void	ft_change_reverse_node(t_avl **paths_box, size_t index, \
				size_t next_index, ssize_t value)
{
	t_avl	*cur;

	if (paths_box && *paths_box)
	{
		if (paths_box[next_index])
		{
			if ((cur = ft_lemin_avl_find_node(paths_box[next_index], \
				index)))
			{
				cur->value = value;
				cur = ft_lemin_avl_find_node(paths_box[index], \
					next_index);
				cur->value = value;
			}
		}
	}
}

void		ft_change_cross_tube(t_avl **paths_box, t_single *way_node, \
				ssize_t value)
{
	if (paths_box && *paths_box && way_node)
	{
		while (way_node && way_node->next)
		{
			ft_change_reverse_node(paths_box, \
				way_node->room->t_row_index, \
				way_node->next->room->t_row_index, value);
			way_node = way_node->next;
		}
	}
}

void		ft_delete_nodes_from_way(t_avl **paths_box, t_single *start)
{
	while (start->next)
	{
		paths_box[start->room->t_row_index] = \
			ft_remove_node(paths_box[start->room->t_row_index], \
			start->next->room->t_row_index);
		start = start->next;
	}
}

void		ft_delete_reverse_node(t_avl **paths_box, size_t index, \
				size_t next_index)
{
	if (paths_box[next_index])
	{
		if (ft_lemin_avl_find_node(paths_box[next_index], index))
		{
			paths_box[next_index] = \
				ft_remove_node(paths_box[next_index], index);
			paths_box[index] = \
				ft_remove_node(paths_box[index], next_index);
		}
	}
}

size_t		ft_check_exit(t_avl **paths_box, t_single *way_node)
{
	if (!paths_box[way_node->next->room->t_row_index]->left &&
		!paths_box[way_node->next->room->t_row_index]->right)
		return (0);
	return (1);
}
