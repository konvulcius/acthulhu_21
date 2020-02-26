#include "push_swap.h"

int		ft_lstiter_int(t_list *lst, int (*f)(t_list *elem))
{
	t_list	*next_list;

	if (lst)
	{
		while (lst)
		{
			next_list = lst->next;
			if (!f(lst))
				return (0);
			lst = next_list;
		}
	}
	return (1);
}
