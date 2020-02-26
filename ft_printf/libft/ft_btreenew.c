#include "libft.h"

t_btree	*ft_btreenew(void *item, size_t item_size)
{
	t_btree	*btree_new;

	btree_new = (t_btree*)malloc(sizeof(t_btree));
	if (!btree_new)
		return (NULL);
	if (!item)
	{
		btree_new->item = NULL;
		btree_new->item_size = 0;
	}
	else
	{
		btree_new->item = malloc(item_size);
		if (!btree_new->item)
		{
			free(btree_new);
			btree_new = NULL;
			return (NULL);
		}
		ft_memcpy(btree_new->item, item, item_size);
		btree_new->item_size = item_size;
	}
	btree_new->left = NULL;
	btree_new->right = NULL;
	return (btree_new);
}
