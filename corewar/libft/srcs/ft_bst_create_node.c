#include "libft.h"

t_bst_node	*ft_bst_create_node(int key, char *content)
{
	t_bst_node	*new_node;

	new_node = (t_bst_node *)malloc(sizeof(t_bst_node));
	if (new_node)
	{
		new_node->key = key;
		if (content)
			new_node->s_content = ft_strdup(content);
		else
			new_node->s_content = NULL;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return (new_node);
}
