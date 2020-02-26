#include "visual.h"

t_attr	*init_attr(t_list *elem)
{
	t_attr	*elem_head;

	if (!elem)
		return (NULL);
	elem_head = (t_attr*)malloc(sizeof(t_attr));
	if (!elem_head)
		allocation_error();
	elem_head->elem = elem;
	elem_head->length = 0;
	elem_head->color = 0;
	elem_head->next = NULL;
	return (elem_head);
}

void	delete_attr(t_attr **head)
{
	t_attr	*temp;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}

t_attr	*create_attr_stack(t_list *stack_a)
{
	t_attr	*head;
	t_attr	*current;

	if (!stack_a)
		return (NULL);
	head = init_attr(stack_a);
	current = head;
	while (stack_a->next)
	{
		stack_a = stack_a->next;
		current->next = init_attr(stack_a);
		current = current->next;
	}
	return (head);
}

t_attr	*find_next(t_attr *head, t_visual *vimlx)
{
	t_attr	*cur;

	cur = head;
	while (cur->elem != vimlx->min)
		cur = cur->next;
	while (head)
	{
		if (*(long long*)vimlx->max->content > *(long long*)head->elem->content
		&& *(long long*)head->elem->content > *(long long*)cur->elem->content)
			cur = head;
		head = head->next;
	}
	vimlx->max = cur->elem;
	return (cur);
}

void	take_param(t_visual *vimlx)
{
	t_attr	*current;
	int		cur_num;

	current = vimlx->head;
	while (current->elem != vimlx->max)
		current = current->next;
	cur_num = vimlx->count;
	while (cur_num)
	{
		current->length = (float)LENGTH / vimlx->count * cur_num + 5;
		current->color = 2 * 0xff / vimlx->count * cur_num;
		if (current->color > 0xff)
		{
			current->color = RED | (2 * 0xff - (int)current->color) | \
				(2 * 0xff - (int)current->color) << 8;
		}
		else
		{
			current->color = BLUE | (int)current->color << 16 | \
				(int)current->color << 8;
		}
		--cur_num;
		current = find_next(vimlx->head, vimlx);
	}
	parse_min_high(vimlx);
}
