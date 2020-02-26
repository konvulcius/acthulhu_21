#include "push_swap.h"

static int	check_sa(t_list **stack_a, t_list **stack_b, int fd)
{
	if ((*stack_a)->next && *(long long*)(*stack_a)->content > \
		*(long long*)(*stack_a)->next->content)
	{
		ft_instruction(stack_a, stack_b, "sa", fd);
		return (1);
	}
	return (0);
}

static void	check_rra(t_list **stack_a, t_list **stack_b, t_required *values, \
			int fd)
{
	if ((*stack_a)->next && *(long long*)values->last_a->content < \
		*(long long*)(*stack_a)->next->content)
		ft_instruction(stack_a, stack_b, "rra", fd);
}

static int	check_ra(t_list **stack_a, t_list **stack_b, int fd)
{
	if ((*stack_a)->next && (*stack_a)->next->next && \
		*(long long*)(*stack_a)->content > \
		*(long long*)(*stack_a)->next->content &&
		*(long long*)(*stack_a)->content > \
		*(long long*)(*stack_a)->next->next->content)
	{
		ft_instruction(stack_a, stack_b, "ra", fd);
		return (1);
	}
	return (0);
}

void		simple_solver(t_list **stack_a, t_list **stack_b, \
				t_required *values, int fd)
{
	while (check_accending_order(*stack_a))
	{
		find_last(*stack_a, &values->last_a);
		if (check_ra(stack_a, stack_b, fd))
			continue ;
		if (check_sa(stack_a, stack_b, fd))
			continue ;
		check_rra(stack_a, stack_b, values, fd);
	}
}
