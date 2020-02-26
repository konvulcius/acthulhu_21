#include "push_swap.h"

static t_list	*find_req_a(t_list *stack_a, t_list *cur_b, t_required *values)
{
	t_list	*higher_a;

	higher_a = values->last_a;
	if (*(long long*)cur_b->content < *(long long*)stack_a->content && \
		*(long long*)cur_b->content > *(long long*)values->last_a->content)
		return (stack_a);
	while (stack_a)
	{
		if (stack_a->next && \
			*(long long*)cur_b->content > *(long long*)stack_a->content && \
			*(long long*)cur_b->content < *(long long*)stack_a->next->content)
			return (stack_a->next);
		if (stack_a->next && \
			*(long long*)stack_a->content > *(long long*)stack_a->next->content)
			higher_a = stack_a;
		stack_a = stack_a->next;
	}
	return (higher_a->next);
}

static void		find_min_way(t_list *stack_a, t_list *stack_b, \
					t_required *values, t_list *cur_b)
{
	int		count;
	int		temp;
	t_list	*required_a;

	count = 0;
	temp = 0;
	required_a = find_req_a(stack_a, cur_b, values);
	if (required_a == NULL)
		required_a = stack_a;
	if (choice_rotate_reverse(stack_b, cur_b, &count) == \
		choice_rotate_reverse(stack_a, required_a, &temp))
	{
		if (temp > count)
			count = temp;
	}
	else
		count += temp;
	if (count < values->length)
	{
		values->node_a = required_a;
		values->node_b = cur_b;
		values->length = count;
	}
}

static void		subpart_two(t_list **stack_a, t_list **stack_b, \
					t_required *values, int fd)
{
	int		way_a;
	int		way_b;
	char	*proc_a;
	char	*proc_b;
	char	*proc_both;

	way_a = choice_rotate_reverse(*stack_a, values->node_a, NULL);
	proc_a = way_a ? "ra" : "rra";
	way_b = choice_rotate_reverse(*stack_b, values->node_b, NULL);
	proc_b = way_b ? "rb" : "rrb";
	proc_both = ft_strncmp(proc_a, proc_b, 2) ? "rr" : "rrr";
	if (way_a == way_b)
	{
		while (*stack_a != values->node_a && *stack_b != values->node_b)
			ft_instruction(stack_a, stack_b, proc_both, fd);
	}
	while (*stack_a != values->node_a)
		ft_instruction(stack_a, stack_b, proc_a, fd);
	while (*stack_b != values->node_b)
		ft_instruction(stack_a, stack_b, proc_b, fd);
}

void			part_two(t_list **stack_a, t_list **stack_b, \
					t_required *values, int fd)
{
	t_list	*cur_b;

	values->length = MAXIMAL_INT;
	cur_b = *stack_b;
	find_last(*stack_a, &values->last_a);
	while (cur_b)
	{
		find_min_way(*stack_a, *stack_b, values, cur_b);
		cur_b = cur_b->next;
	}
	subpart_two(stack_a, stack_b, values, fd);
	ft_instruction(stack_a, stack_b, "pa", fd);
}
