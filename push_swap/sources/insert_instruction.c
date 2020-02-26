#include "push_swap.h"

void	insert_instructions(t_list **stack_a, t_list **stack_b, \
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
	else if (!ft_strcmp((char*)(*stack_proc)->content, "rrr"))
		double_procedure(stack_a, stack_b, procedure_reverse_rotate);
}

void	content_del(void *content, size_t size)
{
	if (size)
		free(content);
}

void	end_of_checker(t_list **stack_a, t_list **stack_b, int fd)
{
	if (!check_accending_order(*stack_a) && !*stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_lstdel(stack_a, content_del);
	if (*stack_b)
		ft_lstdel(stack_b, content_del);
	if (fd > 1)
		close(fd);
}

void	procedure_itter(t_list **stack_a, t_list **stack_b, \
			t_list **stack_proc, int fd)
{
	t_list	*worked_procedure;

	while (*stack_proc)
	{
		insert_instructions(stack_a, stack_b, stack_proc);
		worked_procedure = *stack_proc;
		*stack_proc = (*stack_proc)->next;
		ft_lstdelone(&worked_procedure, content_del);
	}
	end_of_checker(stack_a, stack_b, fd);
}
