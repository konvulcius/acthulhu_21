#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (alst)
	{
		if ((*alst)->content)
		{
			del((*alst)->content, (*alst)->content_size);
			(*alst)->content = NULL;
		}
		free(*alst);
		*alst = NULL;
	}
}
