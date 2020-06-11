#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*next_list;

	if (alst)
	{
		while ((*alst))
		{
			next_list = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = next_list;
		}
	}
}
