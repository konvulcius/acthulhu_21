/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:40:48 by acthulhu          #+#    #+#             */
/*   Updated: 2020/04/22 15:55:21 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	ft_lemin_print_data(t_l_data *data, int show_input_rooms_data)
{
	if (data)
	{
		ft_putendl("<===== LEMIN DATA ======>");
		ft_printf("Ants: %d\n", data->ants_num);
		if (show_input_rooms_data)
		{
			ft_putendl("ROOMS");
			ft_lemin_print_rooms(data);
		}
	}
}

void	ft_lemin_print_map(t_l_data *data)
{
	t_list	*temp;

	temp = data->begin_list;
	while (temp)
	{
		ft_printf("%s\n", (char*)temp->content);
		temp = temp->next;
	}
	ft_printf("\n");
}

void	ft_print_every_ant(t_l_data *data)
{
	t_path	*temp;
	ssize_t	*path;

	temp = data->all_ways;
	while (temp)
	{
		path = temp->path_point;
		ft_printf("\"%s\"", data->table[*path++]->room->name);
		while ((size_t)*path != data->rooms_count - 1)
		{
			ft_printf(" -> %3u", data->table[*path]->room->ant_num);
			path++;
		}
		ft_printf(" -> \"%s\"\n", data->table[*path]->room->name);
		temp = temp->next_path;
	}
	ft_putendl("");
}
