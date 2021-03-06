#include "libft.h"

t_list		*ft_lstcpy(t_list *lst)
{
	t_list *lst_cpy;
	t_list *temp;
	t_list *origin;

	lst_cpy = NULL;
	if (lst)
	{
		lst_cpy = ft_lstnew(lst->content, lst->content_size);
		temp = lst_cpy;
		origin = lst;
		while (origin->next)
		{
			origin = origin->next;
			temp->next = ft_lstnew(origin->content, origin->content_size);
			if (!temp->next)
			{
				ft_lstdel(&lst_cpy, ft_erase_node_content);
				break ;
			}
			temp = temp->next;
		}
		temp = NULL;
		origin = NULL;
	}
	return (lst_cpy);
}
