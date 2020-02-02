/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:32:43 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/30 21:34:45 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_string(t_list **start, char *string)
{
	char	**splited_arg;
	int		i;
	int		value;

	if (!(splited_arg = ft_strsplit(string, ' ')))
		allocation_error();
	i = 0;
	while (splited_arg[i])
	{
		only_dig_validation(splited_arg[i]);
		value = ft_atoll(splited_arg[i]);
		ft_lstadd(start, ft_lstnew(&value, sizeof(long long)));
		ft_strdel(&splited_arg[i++]);
	}
	free(splited_arg);
	splited_arg = NULL;
}

t_list		*arguments_reader(int last, char **argv)
{
	int			num;
	long long	value;
	t_list		*start;

	num = 0;
	start = NULL;
	if (last == 1)
		split_string(&start, argv[num]);
	else
	{
		while (num < last)
		{
			only_dig_validation(argv[num]);
			value = ft_atoll(argv[num]);
			ft_lstadd(&start, ft_lstnew(&value, sizeof(long long)));
			++num;
		}
	}
	ft_lstiter(start, check_same);
	return (ft_lstrev(start));
}

t_list		*instructions_reader(void)
{
	t_list	*start;
	char	*instruction;

	start = NULL;
	while (get_next_line(0, &instruction))
	{
		ft_lstadd(&start, ft_lstnew(instruction, ft_strlen(instruction) + 1));
		ft_strdel(&instruction);
	}
	instructions_validation(start);
	return (ft_lstrev(start));
}