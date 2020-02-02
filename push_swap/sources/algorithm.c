/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:09:43 by acthulhu          #+#    #+#             */
/*   Updated: 2020/02/02 15:39:53 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rotate(t_list **stack_a, t_list **stack_b, t_required *values, \
			int fd)
{
	get_last_value(*stack_a, values, 'a');
	get_last_value(*stack_b, values, 'b');
	if (*(long long*)(*stack_a)->content > *(long long*)values->last_a->content)
	{
		if (*stack_b && (*stack_b)->next && *(long long*)(*stack_b)->content < \
			*(long long*)values->last_b->content)
			ft_instruction(stack_a, stack_b, "rr", fd);
		else
			ft_instruction(stack_a, stack_b, "ra", fd);
	}
	else if (*stack_b && (*stack_b)->next && *(long long*)(*stack_b)->content < \
			*(long long*)values->last_b->content)
			ft_instruction(stack_a, stack_b, "rb", fd);
}

void	check_swap(t_list **stack_a, t_list **stack_b, int fd)
{
	if (*(long long*)(*stack_a)->content > \
			*(long long*)(*stack_a)->next->content)
	{
		if (*stack_b && (*stack_b)->next && *(long long*)(*stack_b)->content < \
			*(long long*)(*stack_b)->next->content)
			ft_instruction(stack_a, stack_b, "ss", fd);
		else
			ft_instruction(stack_a, stack_b, "sa", fd);
	}
	else if (*stack_b && (*stack_b)->next && *(long long*)(*stack_b)->content < \
			*(long long*)(*stack_b)->next->content)
			ft_instruction(stack_a, stack_b, "sb", fd);
}

int		find_way(t_list *stack, t_list **wrong)
{
	t_list	*count_rotate;
	t_list	*count_reverse;
	int		rotate_number;
	int		reverse_number;

	count_rotate = stack;
	count_reverse = *wrong;
	rotate_number = 0;
	reverse_number = 0;
	while (count_rotate != *wrong)
	{
		if (count_reverse == NULL)
			return (reverse_number);
		count_rotate = count_rotate->next;
		count_reverse = count_reverse->next;
		++reverse_number;
		--rotate_number;
	}
	return (rotate_number);
}

void	a_rolling(t_list **stack_a, t_list **stack_b, t_required *values, int fd)
{
	t_list	*temp;
	char	*proc;

	temp = *stack_a;
	proc = "ra";
	if (temp != values->wrong_a && find_way(*stack_a, &values->wrong_a) > 0)
		proc = "rra";
	while (temp != values->wrong_a)
	{
		ft_instruction(stack_a, stack_b, proc, fd);
		temp = *stack_a;
	}
	ft_instruction(stack_a, stack_b, "pb", fd);
}

void	both_rolling(t_list **stack_a, t_list **stack_b, t_required *values, int fd)
{
	int		a_count;
	int		b_count;
	char	*proc;

	a_count = find_way(*stack_a, &values->wrong_a);
	b_count = find_way(*stack_b, &values->wrong_b);
	if (a_count < 0)
	{
		proc = "ra";
		if (b_count < 0)
		{
			while (a_count++ < 0 && b_count++ < 0)
				ft_instruction(stack_a, stack_b, "rr", fd);
			if (b_count != 0)
				proc = "rb";
			while (a_count++ < 0 || b_count++ < 0)
				ft_instruction(stack_a, stack_b, proc, fd);
		}
		else
		{
			if (a_count > b_count * -1)
				proc = "rrb";
			while (a_count++ < 0 && b_count-- > 0)
				ft_instruction(stack_a, stack_b, proc, fd);
		}
	}
	else if (a_count > 0)
	{
		proc = "rra";
		if (b_count > 0)
		{
			while (a_count-- > 0 && b_count-- > 0)
				ft_instruction(stack_a, stack_b, "rrr", fd);
			if (b_count != 0)
				proc = "rrb";
			while (a_count-- > 0 || b_count-- > 0)
				ft_instruction(stack_a, stack_b, proc, fd);
		}
		else
		{
			if (a_count > b_count * -1)
				proc = "rb";
			while (a_count-- > 0 && b_count++ < 0)
				ft_instruction(stack_a, stack_b, proc, fd);
		}
	}
	else
	{
		if (b_count > 0)
		{
			while (b_count-- > 0)
				ft_instruction(stack_a, stack_b, "rrb", fd);
		}
		else
		{
			while (b_count++ < 0)
				ft_instruction(stack_a, stack_b, "rb", fd);
		}
	}
	check_rotate(stack_a, stack_b, values, fd);
	check_swap(stack_a, stack_b, fd);
}