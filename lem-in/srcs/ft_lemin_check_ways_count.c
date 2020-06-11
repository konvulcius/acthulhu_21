/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_check_ways_count.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:51:34 by acthulhu          #+#    #+#             */
/*   Updated: 2020/04/21 14:51:34 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static t_avl	*ft_choose_node(t_l_data *data, t_avl *root)
{
	t_avl	*left;
	t_avl	*right;

	if (root)
	{
		if (root->value == 1)
			return (root);
		else
		{
			left = ft_choose_node(data, root->left);
			if (left)
				return (left);
			right = ft_choose_node(data, root->right);
			if (right)
				return (right);
		}
	}
	return (NULL);
}

static void		ft_lst_sort(t_list **start)
{
	t_list	*temp;
	t_list	*first;

	first = *start;
	temp = NULL;
	while (first && first->next)
	{
		if (*(size_t*)first->content > *(size_t*)first->next->content)
		{
			if (*start == first)
				*start = first->next;
			if (temp)
				temp->next = first->next;
			temp = first->next;
			first->next = first->next->next;
			temp->next = first;
			first = *start;
			temp = NULL;
			continue ;
		}
		temp = first;
		first = first->next;
	}
}

static size_t	ft_len_calculating(t_l_data *d, t_avl *next, t_list **start)
{
	size_t	left;
	size_t	right;
	size_t	length;
	t_avl	*prev;

	if (!next)
		return (0);
	left = ft_len_calculating(d, next->left, start);
	right = ft_len_calculating(d, next->right, start);
	length = 1;
	while (next->index != d->rooms_count - 1)
	{
		length++;
		prev = next;
		next = ft_choose_node(d, d->paths_box[next->index]);
		if (d->table[prev->index]->room->out == d->table[next->index]->room)
			next = ft_choose_node(d, d->paths_box[next->index]);
	}
	if (left != 0)
		ft_lstadd(start, ft_lstnew(&left, sizeof(size_t*)));
	if (right != 0)
		ft_lstadd(start, ft_lstnew(&right, sizeof(size_t*)));
	return (length);
}

ssize_t			ft_check_new_way(t_l_data *data)
{
	t_single	*start;
	t_list		*sort_len;
	size_t		length;

	if (!ft_save_new_way(data, &start))
		return (0);
	ft_change_cross_tube(data->paths_box, start->next, 0);
	sort_len = NULL;
	length = ft_len_calculating(data, \
		data->paths_box[start->room->t_row_index], &sort_len);
	ft_lstadd(&sort_len, ft_lstnew(&length, sizeof(size_t*)));
	ft_lst_sort(&sort_len);
	if (ft_check_path_usefully(data, sort_len))
	{
		ft_lstdel(&sort_len, ft_delete_content);
		ft_2_and_3_step(data, data->paths_box, start);
		ft_delete_single_way(&start, NULL);
		return (1);
	}
	ft_lstdel(&sort_len, ft_delete_content);
	ft_change_cross_tube(data->paths_box, start->next, 1);
	ft_delete_nodes_from_way(data->paths_box, start);
	ft_delete_single_way(&start, NULL);
	return (0);
}
