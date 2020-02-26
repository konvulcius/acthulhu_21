#include "libft.h"

t_list	*ft_lstrev(t_list *start)
{
	t_list	*temp;

	if (start && start->next)
	{
		temp = ft_lstrev(start->next);
		start->next->next = start;
		start->next = NULL;
		return (temp);
	}
	else
		return (start);
}
