#include "libft.h"

t_bst_node		*ft_bst_find_node(t_bst_node *root, int key)
{
	t_bst_node	*node;

	node = NULL;
	if (root)
	{
		if (root->key == key)
			node = root;
		if (root->key > key)
			node = ft_bst_find_node(root->left, key);
		if (root->key < key)
			node = ft_bst_find_node(root->right, key);
	}
	return (node);
}
