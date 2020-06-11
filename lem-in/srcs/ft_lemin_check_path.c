/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_check_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:50:47 by acthulhu          #+#    #+#             */
/*   Updated: 2020/04/22 14:33:24 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static size_t	ft_lemin_decrease_paths_count
	(ssize_t ants_num, t_list *start, t_list *last)
{
	ssize_t	sum;

	sum = 0;
	while (start != last)
	{
		sum += *(ssize_t*)last->content - *(ssize_t*)start->content;
		start = start->next;
	}
	if (ants_num && ants_num >= sum + 1)
		return (1);
	return (0);
}

static ssize_t	ft_string_count(t_l_data *data, t_list *sort_len)
{
	t_list	*temp;
	ssize_t	ants_num;
	ssize_t	count;

	ants_num = data->ants_num;
	count = *(ssize_t*)sort_len->content - 1;
	while (ants_num)
	{
		temp = sort_len;
		while (temp && ft_lemin_decrease_paths_count(ants_num, sort_len, temp))
		{
			ants_num--;
			temp = temp->next;
		}
		count++;
	}
	return (count);
}

size_t			ft_check_path_usefully(t_l_data *data, t_list *start)
{
	t_list	*max;
	ssize_t	sum;

	sum = ft_string_count(data, start);
	if (sum > data->paths_sum)
		return (0);
	data->paths_sum = sum;
	max = start;
	while (max->next)
		max = max->next;
	if (*(size_t*)max->content > data->paths_max_len)
		data->paths_max_len = *(size_t*)max->content;
	return (1);
}
