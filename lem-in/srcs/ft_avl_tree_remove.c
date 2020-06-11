/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_remove.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:46:20 by acthulhu          #+#    #+#             */
/*   Updated: 2020/04/21 14:47:11 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void			ft_avl_full_delete(t_avl **node)
{
	if (node && *node)
	{
		if ((*node)->left)
			ft_avl_full_delete(&(*node)->left);
		if ((*node)->right)
			ft_avl_full_delete(&(*node)->right);
		free(*node);
		*node = NULL;
	}
}

static t_avl	*ft_findmin(t_avl *node)
{
	if (node->left)
		return (ft_findmin(node->left));
	return (node);
}

static t_avl	*ft_movemin(t_avl *node)
{
	if (node->left == 0)
		return (node->right);
	node->left = ft_movemin(node->left);
	return (ft_balance(node));
}

t_avl			*ft_remove_node(t_avl *node, size_t index)
{
	t_avl *east;
	t_avl *west;
	t_avl *min;

	if (!node)
		return (NULL);
	if (index < node->index)
		node->left = ft_remove_node(node->left, index);
	else if (index > node->index)
		node->right = ft_remove_node(node->right, index);
	else
	{
		east = node->left;
		west = node->right;
		free(node);
		node = NULL;
		if (!west)
			return (east);
		min = ft_findmin(west);
		min->right = ft_movemin(west);
		min->left = east;
		return (ft_balance(min));
	}
	return (ft_balance(node));
}
