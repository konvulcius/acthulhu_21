/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <marvin@fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 03:50:29 by lliza             #+#    #+#             */
/*   Updated: 2020/04/22 03:50:51 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		ft_lemin_reset_table(t_l_data *data)
{
	size_t		i;

	i = 0;
	while (i < data->rooms_count)
	{
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
		++i;
	}
}

void		ft_lemin_lst_add_second(t_list *head, t_l_room *new)
{
	t_list	*temp;

	if (head && new)
	{
		temp = head->next;
		if (!(head->next = ft_lstnew(NULL, 0)))
			ft_allocation_error();
		head->next->content = new;
		head->next->content_size = sizeof(t_l_room*);
		head->next->next = temp;
	}
}
