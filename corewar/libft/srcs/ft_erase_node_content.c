#include "libft.h"

void	ft_erase_node_content(void *node, size_t node_size)
{
	t_list *ptr;

	ptr = node;
	if (ptr)
		if (ptr->content_size == node_size)
		{
			free(ptr->content);
			ptr->content = NULL;
		}
}
