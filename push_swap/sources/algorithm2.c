/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:36:26 by acthulhu          #+#    #+#             */
/*   Updated: 2020/02/03 17:36:21 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_instruction(t_list **stack_a, t_list **stack_b, char *name, int fd)
{
	if (!ft_strcmp(name, "sa"))
		procedure_swap(stack_a);
	else if (!ft_strcmp(name, "pa"))
		procedure_push(stack_a, stack_b);
	else if (!ft_strcmp(name, "ra"))
		procedure_rotate(stack_a);
	else if (!ft_strcmp(name, "rra"))
		procedure_reverse_rotate(stack_a);
	else if (!ft_strcmp(name, "sb"))
		procedure_swap(stack_b);
	else if (!ft_strcmp(name, "pb"))
		procedure_push(stack_b, stack_a);
	else if (!ft_strcmp(name, "rb"))
		procedure_rotate(stack_b);
	else if (!ft_strcmp(name, "rrb"))
		procedure_reverse_rotate(stack_b);
	else if (!ft_strcmp(name, "ss"))
		double_procedure(stack_a, stack_b, procedure_swap);
	else if (!ft_strcmp(name, "rr"))
		double_procedure(stack_a, stack_b, procedure_rotate);
	else if (!ft_strcmp(name, "rrr"))
		double_procedure(stack_a, stack_b, procedure_reverse_rotate);
	ft_putstr_fd(name, fd);
	ft_putchar_fd('\n', fd);
}

// void	only_push_a(t_list **stack_a, t_list **stack_b, int fd)
// {
// 	while (*stack_b)
// 	ft_instruction(stack_a, stack_b, "pa", fd);
// }

void	get_b_last(t_list *stack, t_required *values)
{
	while (stack->next)
		stack = stack->next;
	values->last_b = stack;
}
