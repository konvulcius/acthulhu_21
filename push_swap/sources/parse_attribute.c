#include "visual.h"

int		parse_color(t_visual *vimlx, t_list *node)
{
	t_attr	*finder;

	finder = vimlx->head;
	while (finder->elem != node)
		finder = finder->next;
	return ((int)finder->color);
}

void	parse_min_high(t_visual *vimlx)
{
	t_list	*max;
	t_list	*min;
	t_list	*stack;

	stack = *vimlx->stack_a;
	max = stack;
	min = stack;
	while (stack)
	{
		if (*(long long*)stack->content > *(long long*)max->content)
			max = stack;
		if (*(long long*)stack->content < *(long long*)min->content)
			min = stack;
		stack = stack->next;
	}
	vimlx->max = max;
	vimlx->min = min;
}

int		parse_length(t_visual *vimlx, t_list *node)
{
	t_attr	*finder;

	finder = vimlx->head;
	while (finder->elem != node)
		finder = finder->next;
	return ((int)finder->length);
}

int		parse_attr(t_visual *vimlx)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = *vimlx->stack_a;
	if (!vimlx)
		return (0);
	while (temp)
	{
		++count;
		temp = temp->next;
	}
	if (count <= WIN_WIDTH - ((WIN_WIDTH - 200) / 10 * 2) - 200 && count > 0)
	{
		vimlx->width = (WIN_WIDTH - ((WIN_WIDTH - 200) / 10 * 2) - 200) / count;
		vimlx->count = count;
	}
	else
		return (0);
	return (1);
}
