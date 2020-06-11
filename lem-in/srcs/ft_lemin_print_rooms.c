/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_print_rooms.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 03:29:33 by lliza             #+#    #+#             */
/*   Updated: 2020/04/22 14:16:10 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	ft_lemin_traverse_tree\
	(t_l_data *data, t_avl *root, void (*f)(t_l_data *, t_avl *))
{
	if (root)
	{
		f(data, root);
		if (root->left)
			ft_lemin_traverse_tree(data, root->left, f);
		if (root->right)
			ft_lemin_traverse_tree(data, root->right, f);
	}
}

void	ft_lemin_print_node(t_l_data *data, t_avl *node)
{
	t_l_room	*room;

	if (node)
	{
		if (node->index < data->rooms_count)
		{
			room = data->table[node->index]->room;
			ft_printf("| room: %-5s edge_val: %2d, index: %4d |", \
					room->name, \
					node->value, \
					node->index);
		}
		else
			ft_putendl("| NODE INDEX ERROR from ft_lemin_print_node |");
	}
}

void	ft_lemin_print_room(t_l_data *data, void *room)
{
	t_l_room *r;

	if (room)
	{
		r = room;
		ft_printf("%4zu: Name: %-5s links_out: ", \
					r->t_row_index, \
					r->name);
		if (r->links_out)
			ft_lemin_traverse_tree(data, r->links_out, ft_lemin_print_node);
		else
			ft_printf("None");
		ft_putendl("");
	}
}

void	ft_lemin_print_rooms(t_l_data *data)
{
	t_list		*lst;
	size_t		i;
	t_l_room	*curr;

	lst = data->rooms;
	i = 0;
	while (lst)
	{
		curr = lst->content;
		ft_lemin_print_room(data, data->table[curr->t_row_index]->room);
		lst = lst->next;
	}
	ft_putendl("");
}
