/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:16:34 by acthulhu          #+#    #+#             */
/*   Updated: 2020/02/05 14:53:55 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_required(t_list *stack, t_required *values)
{
	values->min_a = stack;
	values->max_a = stack;
	while (stack)
	{
		if (*(long long*)stack->content < *(long long*)values->min_a->content)
			values->min_a = stack;
		if (*(long long*)stack->content > *(long long*)values->max_a->content)
			values->max_a = stack;
		if (!stack->next)
			values->last_a = stack;
		stack = stack->next;
	}
}

t_list	*check_accending_order(t_list *stack)
{
	if (stack && stack->next)
	{
		if (*(long long*)stack->content < *(long long*)stack->next->content)
			return (check_accending_order(stack->next));
		else
			return (stack);
	}
	else
		return (NULL);
}

// t_list	*check_descending_order(t_list *stack)
// {
// 	if (stack && stack->next)
// 	{
// 		if (*(long long*)stack->content > *(long long*)stack->next->content)
// 			return (check_descending_order(stack->next));
// 		else
// 			return (stack);
// 	}
// 	else
// 		return (NULL);
// }

void	print_stack(t_list *stack)
{
	while (stack)
	{
		ft_printf("%d ", *(long long*)stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	stack_checker(t_list **stack_a, t_list **stack_b, t_required *values, \
			int fd)
{
	while (*stack_a != values->max_a || (*stack_a)->next != values->min_a || \
		(*stack_a)->next->next != NULL)
		first_part(stack_a, stack_b, values, fd);
	while (*stack_b != NULL)
	{
		second_part(stack_a, stack_b, values, fd);
		ft_instruction(stack_a, stack_b, "pa", fd);
	}
	third_part(stack_a, stack_b, values, fd);
}