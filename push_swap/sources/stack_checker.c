#include "push_swap.h"

int		find_count(t_list *stack)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = stack;
	while (temp)
	{
		++count;
		temp = temp->next;
	}
	return (count);
}

void	find_last(t_list *stack, t_list **last)
{
	while (stack)
	{
		if (!stack->next)
			*last = stack;
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

void	stack_checker(t_list **stack_a, t_list **stack_b, t_required *values, \
			int fd)
{
	if (find_count(*stack_a) < 7)
	{
		while (find_count(*stack_a) > 3)
			ft_instruction(stack_a, stack_b, "pb", fd);
		simple_solver(stack_a, stack_b, values, fd);
	}
	else
	{
		find_max_sequence(*stack_a, values);
		part_one(stack_a, stack_b, values, fd);
	}
	while (*stack_b)
		part_two(stack_a, stack_b, values, fd);
	part_three(stack_a, stack_b, fd);
}
