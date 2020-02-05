/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:02:52 by acthulhu          #+#    #+#             */
/*   Updated: 2020/02/02 21:08:47 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	content_del(void *content, size_t size)
{
	if (size)
		free(content);
}

int			main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_required	values;
	int			fd;

	if (argc < 2)
		stop();
	fd = open(argv[1], O_RDWR);
	stack_b = NULL;
	if (argc > 3 && fd > 1)
		stack_a = arguments_reader(argc - 2, argv + 2);
	else
		stack_a = arguments_reader(argc - 1, argv + 1);
	if (fd < 1)
		fd = 1;
	find_required(stack_a, &values);
	stack_checker(&stack_a, &stack_b, &values, fd);
	ft_lstdel(&stack_a, content_del);
	if (fd > 1)
		close (fd);
	return (0);
}