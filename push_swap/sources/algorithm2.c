#include "push_swap.h"

void	ft_instruction(t_list **stack_a, t_list **stack_b, char *name, \
				int fd)
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

void	part_one(t_list **stack_a, t_list **stack_b, t_required *values, \
			int fd)
{
	t_seq	*sequence;

	sequence = values->first;
	while (values->first)
	{
		if (*stack_a == sequence->target)
		{
			ft_instruction(stack_a, stack_b, "ra", fd);
			sequence = sequence->next;
			if (!sequence)
				break ;
		}
		else
			ft_instruction(stack_a, stack_b, "pb", fd);
	}
	while (*stack_a != values->first->target)
		ft_instruction(stack_a, stack_b, "pb", fd);
	delete_seq_data(&values->first, NULL);
}

int		choice_rotate_reverse(t_list *begin, t_list *goal, int *count)
{
	t_list	*point;

	point = goal;
	while (begin != point)
	{
		if (!goal)
			return (0);
		if (count)
			++(*count);
		begin = begin->next;
		goal = goal->next;
	}
	return (1);
}

void	part_three(t_list **stack_a, t_list **stack_b, int fd)
{
	t_list	*min_value;
	t_list	*temp;
	char	*proc;

	min_value = *stack_a;
	temp = *stack_a;
	while (temp)
	{
		if (*(long long*)temp->content < *(long long*)min_value->content)
			min_value = temp;
		temp = temp->next;
	}
	if (choice_rotate_reverse(*stack_a, min_value, NULL))
		proc = "ra";
	else
		proc = "rra";
	while (*stack_a != min_value)
		ft_instruction(stack_a, stack_b, proc, fd);
}
