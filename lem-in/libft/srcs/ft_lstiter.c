#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (f)
	{
		if (lst && lst->next)
			ft_lstiter(lst->next, f);
		if (lst)
			f(lst);
	}
}
