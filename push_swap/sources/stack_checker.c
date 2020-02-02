/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:16:34 by acthulhu          #+#    #+#             */
/*   Updated: 2020/02/01 23:45:37 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_lower(t_list *stack, t_required *values)
{
	while (stack)
	{
		if (*(long long*)stack->content < values->average)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
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

t_list	*check_descending_order(t_list *stack)
{
	if (stack && stack->next)
	{
		if (*(long long*)stack->content > *(long long*)stack->next->content)
			return (check_descending_order(stack->next));
		else
			return (stack);
	}
	else
		return (NULL);
}

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
	while ((values->wrong_a = find_lower(*stack_a, values)))
		a_rolling(stack_a, stack_b, values, fd);
	while (1)
	{
		get_last_value(*stack_a, values, 'a');
		get_last_value(*stack_b, values, 'b');
		values->wrong_a = check_accending_order(*stack_a);
		values->wrong_b = check_descending_order(*stack_b);
		print_stack(*stack_a);
		print_stack(*stack_b);
		if (values->wrong_a || values->wrong_b)
			both_rolling(stack_a, stack_b, values, fd);
		else
			break ;
	}
	only_push_a(stack_a, stack_b, fd);
}