#include "libft.h"

static void	delete_content(void *content, size_t size)
{
	while (size)
	{
		ft_memdel(&content[size]);
		size--;
	}
	free(content);
	content = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_new;
	t_list	*slider;

	if (!lst)
		return (NULL);
	begin_new = f(lst);
	if (!begin_new)
		return (NULL);
	slider = begin_new;
	while (lst->next)
	{
		lst = lst->next;
		slider->next = f(lst);
		if (!slider->next)
		{
			ft_lstdel(&begin_new, delete_content);
			return (NULL);
		}
		slider = slider->next;
	}
	return (begin_new);
}
