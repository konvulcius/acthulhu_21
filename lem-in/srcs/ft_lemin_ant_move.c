/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_ant_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:49:03 by acthulhu          #+#    #+#             */
/*   Updated: 2020/04/21 14:49:34 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

size_t		ft_lemin_decrease_ways_count(t_l_data *data, t_path *paths)
{
	t_path	*temp;
	ssize_t	sum;
	ssize_t	count;

	if (!data->ants_num || !paths)
		return (0);
	sum = 0;
	count = 0;
	temp = data->all_ways;
	while (temp != paths)
	{
		sum += paths->path_length - temp->path_length;
		temp = temp->next_path;
		count++;
	}
	if (data->ants_num >= sum + 1)
		return (1);
	return (0);
}

void		ft_lemin_ant_move(t_l_data *data, t_path *paths)
{
	size_t			length;
	static size_t	ant_count = 1;

	while (paths)
	{
		if (data->ants_num <= 0)
			ant_count = 0;
		length = paths->path_length;
		while (--length > 1)
		{
			data->table[*(paths->path_point + length)]->room->ant_num = \
				data->table[*(paths->path_point + length - 1)]->room->ant_num;
		}
		if (ft_lemin_decrease_ways_count(data, paths))
		{
			--data->ants_num;
			data->table[*(paths->path_point + 1)]->room->ant_num = ant_count++;
		}
		else
			data->table[*(paths->path_point + 1)]->room->ant_num = 0;
		paths = paths->next_path;
	}
}
