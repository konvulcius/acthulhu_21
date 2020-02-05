/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:09:43 by acthulhu          #+#    #+#             */
/*   Updated: 2020/02/03 18:13:43 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_action(t_list **stack_a, t_list **stack_b, int fd)
{
	if (*stack_b && (*stack_b)->next && *(long long*)(*stack_b)->content < \
		*(long long*)(*stack_b)->next->content)
		ft_instruction(stack_a, stack_b, "ss", fd);
	else
		ft_instruction(stack_a, stack_b, "sa", fd);
}

void	rotate_action(t_list **stack_a, t_list **stack_b, t_required *values, \
			int fd)
{
	values->last_a = *stack_a;
	if (*stack_b && *(long long*)(*stack_b)->content < \
		*(long long*)values->last_b->content)
	{
		values->last_b = *stack_b;
		ft_instruction(stack_a, stack_b, "rr", fd);
	}
	else
		ft_instruction(stack_a, stack_b, "ra", fd);	
}

void	reverse_action(t_list **stack_a, t_list **stack_b, t_required *values, \
			int fd)
{
	find_required(*stack_a, values);
	if (*stack_b && *(long long*)values->last_b->content > \
		*(long long*)(*stack_b)->content)
	{
		get_b_last(*stack_b, values);
		ft_instruction(stack_a, stack_b, "rrr", fd);
	}
	else
		ft_instruction(stack_a, stack_b, "rra", fd);
}

void	first_part(t_list **stack_a, t_list **stack_b, t_required *values, \
			int fd)
{
	if (*stack_a != values->min_a && *stack_a != values->max_a)
	{
		if (*stack_b == NULL)
			values->last_b = *stack_a;
		ft_instruction(stack_a, stack_b, "pb", fd);
	}
	else
		ft_instruction(stack_a, stack_b, "ra", fd);
}

void	second_part(t_list **stack_a, t_list **stack_b, t_required *values, \
			int fd)
{
	// print_stack (*stack_a);
	// print_stack (*stack_b);
	find_required(*stack_a, values);
	if (*(long long*)(*stack_a)->content > \
		*(long long*)(*stack_a)->next->content)
	{
		swap_action(stack_a, stack_b, fd);
		if (*(long long*)(*stack_a)->next->content > \
			*(long long*)(*stack_a)->next->next->content)
			rotate_action(stack_a, stack_b, values, fd);
		second_part(stack_a, stack_b, values, fd);
	}
	else if (*(long long*)(*stack_a)->content < \
			*(long long*)values->last_a->content)
	{
			reverse_action(stack_a, stack_b, values, fd);
			second_part(stack_a, stack_b, values, fd);
	}
}

int		find_way(t_list *stack, t_list *target)
{
	t_list	*count_rotate;
	t_list	*count_reverse;
	int		rotate_number;
	int		reverse_number;

	count_rotate = stack;
	count_reverse = target;
	rotate_number = 0;
	reverse_number = 0;
	while (count_rotate != target)
	{
		if (count_reverse->next == NULL)
			return (reverse_number);
		count_rotate = count_rotate->next;
		count_reverse = count_reverse->next;
		++reverse_number;
		--rotate_number;
	}
	return (rotate_number);
}

void	third_part(t_list **stack_a, t_list **stack_b, t_required *values, \
			int fd)
{
	int		way;
	char	*proc;

	way = find_way(*stack_a, values->max_a);
	proc = "ra";
	if (way > 0)
		proc = "rra";
	while (values->max_a->next != NULL)
		ft_instruction(stack_a, stack_b, proc, fd);
}

// int		choos_way(t_list *stack_a, t_required *values, t_list **target)
// {
// 	int		way_min;
// 	int		way_max;

// 	way_min = find_way(stack_a, values->min_a);
// 	way_max = find_way(stack_a, values->max_a);
// 	if (way_max > way_min && way_max > way_min * -1)
// 	{
// 		*target = values->min_a;
// 		return (way_min);
// 	}
// 	if (way_max < way_min && way_max < way_min * -1)
// 	{
// 		*target = values->min_a;
// 		return (way_min);
// 	}
// 	if (way_min > way_max && way_min > way_max * -1)
// 	{
// 		*target = values->max_a;
// 		return (way_max);
// 	}
// 	*target = values->max_a;
// 	return (way_max);
// }

// void	a_rolling(t_list **stack_a, t_list **stack_b, t_required *values, int fd)
// {
// 	t_list	*temp;
// 	t_list	*target;
// 	char	*proc;

// 	temp = *stack_a;
// 	proc = "ra";
// 	if (choos_way(*stack_a, values, &target) > 0)
// 		proc = "rra";
// 	while (temp && temp != target)
// 	{
// 		ft_instruction(stack_a, stack_b, proc, fd);
// 		temp = *stack_a;
// 	}
// 	ft_instruction(stack_a, stack_b, "pb", fd);
// 	if (target == values->max_a && (*stack_b)->next)
// 		ft_instruction(stack_a, stack_b, "rb", fd);
// 	find_required(*stack_a, values);
// 	// print_stack (*stack_a);
// 	// print_stack (*stack_b);
// }

// void	b_rolling(t_list **stack_a, t_list **stack_b, t_required *values, int fd)
// {
// 	t_list	*temp;

// 	temp = *stack_b;
// 	while (temp && temp->next && *(long long*)temp->content > \
// 			*(long long*)temp->next->content)
// 	{
// 		ft_instruction(stack_a, stack_b, "pa", fd);
// 		temp = *stack_b;
// 	}
// 	ft_instruction(stack_a, stack_b, "pa", fd);
// 	while (check_accending_order(*stack_a))
// 		check_rotate(stack_a, stack_b, values, fd);
// 	// print_stack (*stack_a);
// 	// print_stack (*stack_b);
// }
