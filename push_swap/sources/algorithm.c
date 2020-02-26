#include "push_swap.h"

void			delete_seq_data(t_seq **first, t_seq *stop)
{
	t_seq	*temp;

	while (*first && *first != stop)
	{
		temp = (*first)->next;
		free(*first);
		*first = temp;
	}
}

static t_seq	*create_node(int count, t_list *target)
{
	t_seq	*elem;

	elem = (t_seq*)malloc(sizeof(t_seq));
	if (!elem)
		allocation_error();
	elem->count = count;
	elem->target = target;
	elem->next = NULL;
	return (elem);
}

static void		check_position(t_required *values, t_seq **max)
{
	t_seq	*temp;

	while (1)
	{
		temp = values->first;
		while (temp != *max)
		{
			if (temp->count + 1 == (*max)->count && \
				*(long long*)temp->target->content < \
				*(long long*)(*max)->target->content)
			{
				delete_seq_data(&temp->next, *max);
				temp->next = *max;
				*max = temp;
			}
			else
				temp = temp->next;
		}
		if ((*max)->count == 1)
			break ;
	}
}

static void		queue_only(t_required *values)
{
	t_seq	*temp;
	t_seq	*max;

	temp = values->first;
	max = temp;
	while (temp)
	{
		if (temp->count > max->count)
			max = temp;
		temp = temp->next;
	}
	delete_seq_data(&max->next, NULL);
	check_position(values, &max);
	delete_seq_data(&values->first, max);
	values->first = max;
}

void			find_max_sequence(t_list *stack, t_required *values)
{
	t_seq	*i;
	t_seq	*j;

	values->first = create_node(1, stack);
	i = values->first;
	while (stack->next)
	{
		i->next = create_node(1, stack->next);
		stack = stack->next;
		i = i->next;
	}
	j = values->first->next;
	while (j)
	{
		i = values->first;
		while (i != j)
		{
			if (*(long long*)j->target->content > \
				*(long long*)i->target->content && j->count <= i->count)
				++j->count;
			i = i->next;
		}
		j = j->next;
	}
	queue_only(values);
}
