#include "ft_lemin.h"

t_avl	*ft_avl_tree_init(size_t index)
{
	t_avl	*new_node;

	new_node = (t_avl*)ft_memalloc(sizeof(t_avl));
	if (!new_node)
		ft_allocation_error();
	new_node->index = index;
	new_node->value = 1;
	new_node->height = 1;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

ssize_t	ft_take_node_height(t_avl *node)
{
	if (node)
		return ((ssize_t)node->height);
	return (0);
}

ssize_t	ft_tree_diff(t_avl *node)
{
	if (node)
	{
		return (ft_take_node_height(node->right) - \
			ft_take_node_height(node->left));
	}
	return (0);
}

void	ft_solve_node_height(t_avl *node)
{
	ssize_t		left;
	ssize_t		right;

	if (!node)
		return ;
	left = ft_take_node_height(node->left);
	right = ft_take_node_height(node->right);
	if (left > right)
		node->height = 1 + left;
	else
		node->height = 1 + right;
}
