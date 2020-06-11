#include "ft_lemin.h"

t_avl	*ft_rotateright(t_avl *node)
{
	t_avl	*temp;

	if (!node)
		return (NULL);
	temp = node->left;
	node->left = temp->right;
	temp->right = node;
	ft_solve_node_height(temp);
	ft_solve_node_height(node);
	return (temp);
}

t_avl	*ft_rotateleft(t_avl *node)
{
	t_avl	*temp;

	if (!node)
		return (NULL);
	temp = node->right;
	node->right = temp->left;
	temp->left = node;
	ft_solve_node_height(temp);
	ft_solve_node_height(node);
	return (temp);
}

t_avl	*ft_balance(t_avl *node)
{
	if (!node)
		return (NULL);
	ft_solve_node_height(node);
	if (ft_tree_diff(node) == 2)
	{
		if (ft_tree_diff(node->right) < 0)
			node->right = ft_rotateright(node->right);
		return (ft_rotateleft(node));
	}
	if (ft_tree_diff(node) == -2)
	{
		if (ft_tree_diff(node->left) > 0)
			node->left = ft_rotateleft(node->left);
		return (ft_rotateright(node));
	}
	return (node);
}

t_avl	*ft_insert_node(t_avl *node, size_t index)
{
	if (!node)
		return (ft_avl_tree_init(index));
	if (index < node->index)
		node->left = ft_insert_node(node->left, index);
	else
		node->right = ft_insert_node(node->right, index);
	return (ft_balance(node));
}

t_avl	*ft_lemin_avl_find_node(t_avl *root, size_t index)
{
	if (root)
	{
		if (root->index == index)
			return (root);
		if (index < root->index)
			return (ft_lemin_avl_find_node(root->left, index));
		return (ft_lemin_avl_find_node(root->right, index));
	}
	return (NULL);
}
