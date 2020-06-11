/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_fill_data_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:51:34 by acthulhu          #+#    #+#             */
/*   Updated: 2020/04/22 15:56:08 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		ft_delete_strings(char **array)
{
	if (!array || !*array)
		return ;
	while (*array)
	{
		free(*array);
		*array++ = NULL;
	}
}

void		ft_lemin_take_number_of_ants(t_l_data *data, t_list **begin_list)
{
	if (!*begin_list || !ft_only_dig_validation((char*)(*begin_list)->content))
		ft_error_here();
	data->ants_num = (size_t)ft_atoll((char*)(*begin_list)->content);
	if (data->ants_num <= 0 || data->ants_num > MAXIMAL_INT)
		ft_error_here();
	*begin_list = (*begin_list)->next;
}

void		ft_read_input(t_l_data *data)
{
	t_list	*begin_list;
	t_list	*temp;
	char	*line;

	if (read(0, NULL, 0) == -1)
		ft_error_here();
	begin_list = NULL;
	if (get_next_line(0, &line) > 0)
	{
		begin_list = ft_lstnew(line, ft_strlen(line) + 1);
		temp = begin_list;
		ft_strdel(&line);
	}
	while (get_next_line(0, &line) > 0)
	{
		temp->next = ft_lstnew(line, ft_strlen(line) + 1);
		temp = temp->next;
		ft_strdel(&line);
	}
	ft_lemin_fill_data(begin_list, data);
	if (data->print_data || data->print_path)
		ft_lemin_print_map(data);
	if (data->print_data)
		ft_lemin_print_data(data, 1);
}
