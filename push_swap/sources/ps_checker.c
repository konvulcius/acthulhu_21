/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:09:56 by acthulhu          #+#    #+#             */
/*   Updated: 2020/02/01 23:06:14 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_instructions(t_list **stack_a, t_list **stack_b, \
			t_list **stack_proc)
{
	if (!ft_strcmp((char*)(*stack_proc)->content, "sa"))
			procedure_swap(stack_a);
		else if (!ft_strcmp((char*)(*stack_proc)->content, "sb"))
			procedure_swap(stack_b);
		else if (!ft_strcmp((char*)(*stack_proc)->content, "ss"))
			double_procedure(stack_a, stack_b, procedure_swap);
		else if (!ft_strcmp((char*)(*stack_proc)->content, "pa"))
			procedure_push(stack_a, stack_b);
		else if (!ft_strcmp((char*)(*stack_proc)->content, "pb"))
			procedure_push(stack_b, stack_a);
		else if (!ft_strcmp((char*)(*stack_proc)->content, "ra"))
			procedure_rotate(stack_a);
		else if (!ft_strcmp((char*)(*stack_proc)->content, "rb"))
			procedure_rotate(stack_b);
		else if (!ft_strcmp((char*)(*stack_proc)->content, "rr"))
			double_procedure(stack_a, stack_b, procedure_rotate);
		else if (!ft_strcmp((char*)(*stack_proc)->content, "rra"))
			procedure_reverse_rotate(stack_a);
		else if (!ft_strcmp((char*)(*stack_proc)->content, "rrb"))
			procedure_reverse_rotate(stack_b);
		else if (!ft_strcmp((char*)(*stack_proc)->content, "rr"))
			double_procedure(stack_a, stack_b, procedure_reverse_rotate);
}

static void	content_del(void *content, size_t size)
{
	if (size)
		free(content);
}

static void	procedure_itter(t_stacks *container)
{
	t_list	*worked_procedure;

	while (container->stack_proc)
	{
		insert_instructions(&container->stack_a, &container->stack_b, \
			&container->stack_proc);
		worked_procedure = container->stack_proc;
		container->stack_proc = container->stack_proc->next;
		ft_lstdelone(&worked_procedure, content_del);
	}
}

int			main(int argc, char **argv)
{
	t_stacks	container;
	int			fd;

	if (argc < 2)
		stop();
	fd = open(argv[1], O_RDWR);
	if (argc > 3 && fd > 1)
		container.stack_a = arguments_reader(argc - 2, argv + 2);
	else
		container.stack_a = arguments_reader(argc - 1, argv + 1);
	container.stack_proc = instructions_reader();
	procedure_itter(&container);
	if (fd < 1)
		fd = 1;
	if (!check_accending_order(container.stack_a))
		ft_putstr_fd("OK\n", 1); //испарвить на fd
	else
		ft_putstr_fd("KO\n", 1); //испарвить на fd
	ft_lstdel(&container.stack_a, content_del);
	if (container.stack_b)
		ft_lstdel(&container.stack_b, content_del);
	if (fd > 1)
		close (fd);
	return (0);
}