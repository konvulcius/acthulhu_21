#include "libft.h"

void			ft_bst_insert_node(t_bst_node **root, int key, char *content)
{
	if (!(*root))
		*root = ft_bst_create_node(key, content);
	if ((*root)->key > key)
		ft_bst_insert_node(&((*root)->left), key, content);
	if ((*root)->key < key)
		ft_bst_insert_node(&((*root)->right), key, content);
}
