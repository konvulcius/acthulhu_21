#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*next_list;

	if (lst)
	{
		while (lst)
		{
			next_list = lst->next;
			f(lst);
			lst = next_list;
		}
	}
}
