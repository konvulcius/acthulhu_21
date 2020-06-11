#include "libft.h"

size_t		ft_lstlen(t_list *head)
{
	size_t len;

	len = 0;
	while (head)
	{
		head = head->next;
		++len;
	}
	return (len);
}
