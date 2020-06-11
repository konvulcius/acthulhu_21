#include "ft_lemin.h"

t_avl	*ft_lemin_avl_change_nodes\
	(t_avl *root, size_t node_index, size_t new_index)
{
	if (root)
	{
		if (ft_lemin_avl_find_node(root, node_index))
		{
			return (ft_insert_node(ft_remove_node(root, node_index),
				new_index));
		}
	}
	return (root);
}

void	ft_lemin_avl_change_neighbours_links_out\
	(t_row **table, t_avl *root, size_t node_index, size_t new_index)
{
	size_t index;

	if (root)
	{
		if (table[root->index]->room->type == 1)
		{
			index = table[root->index]->room->out->t_row_index;
			table[index]->room->links_out = \
				ft_lemin_avl_change_nodes(table[index]->room->links_out,
											node_index, new_index);
		}
		else
		{
			table[root->index]->room->links_out = \
				ft_lemin_avl_change_nodes(table[root->index]->room->links_out,
											node_index, new_index);
		}
		ft_lemin_avl_change_neighbours_links_out(table, root->left,
												node_index, new_index);
		ft_lemin_avl_change_neighbours_links_out(table, root->right,
												node_index, new_index);
	}
}
