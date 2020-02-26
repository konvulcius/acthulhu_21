#include "push_swap.h"

void	instructions_validation(t_list *start)
{
	if (start && !*(char*)start->content)
		return ;
	if (!ft_strcmp((char*)start->content, "sa") || \
		!ft_strcmp((char*)start->content, "sb") || \
		!ft_strcmp((char*)start->content, "ss") || \
		!ft_strcmp((char*)start->content, "pa") || \
		!ft_strcmp((char*)start->content, "pb") || \
		!ft_strcmp((char*)start->content, "ra") || \
		!ft_strcmp((char*)start->content, "rb") || \
		!ft_strcmp((char*)start->content, "rr") || \
		!ft_strcmp((char*)start->content, "rra") || \
		!ft_strcmp((char*)start->content, "rrb") || \
		!ft_strcmp((char*)start->content, "rrr"))
		return ;
	else
	{
		ft_lstdel(&start, content_del);
		the_error();
	}
}

int		only_dig_validation(char *string)
{
	int		count;

	if (*string == '-' || *string == '+')
		string++;
	count = 0;
	while (*string)
	{
		if (count == 11 || !ft_isdigit(*string++))
			return (0);
		++count;
	}
	if (count == 0)
		return (0);
	return (1);
}

int		digit_compare(t_list *elem)
{
	if (*(long long*)elem->content > MAXIMAL_INT ||
		*(long long*)elem->content < -MAXIMAL_INT - 1)
		return (0);
	return (1);
}

int		check_same(t_list *stack)
{
	t_list	*checker;

	if (!digit_compare(stack))
		return (0);
	checker = stack->next;
	while (checker)
	{
		if (ft_memcmp(stack->content, checker->content, \
				stack->content_size) == 0)
			return (0);
		checker = checker->next;
	}
	return (1);
}
