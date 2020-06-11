#include "ft_lemin.h"

void		bf_inner_check_edges\
	(t_l_data *data, t_row *u_row, t_avl *node, size_t *check)
{
	t_row	*v_row;

	if (node)
	{
		v_row = data->table[node->index];
		if (node->index != 0 && u_row->len != MAXIMAL_INT &&
			v_row->len > u_row->len + node->value)
		{
			v_row->len = u_row->len + node->value;
			v_row->prev_index = u_row->room->t_row_index;
			if (!(*check))
				*check = 1;
		}
		if (node->left)
			bf_inner_check_edges(data, u_row, node->left, check);
		if (node->right)
			bf_inner_check_edges(data, u_row, node->right, check);
	}
}

void		bf(t_l_data *data)
{
	size_t		i;
	size_t		j;
	size_t		check;
	t_row		*u_row;

	i = 0;
	while (i < data->rooms_count - 1)
	{
		check = 0;
		j = 0;
		while (j < data->rooms_count)
		{
			u_row = data->table[j];
			if (j != data->rooms_count - 1)
				bf_inner_check_edges(data, u_row,
									u_row->room->links_out, &check);
			++j;
		}
		if (!check)
			break ;
		++i;
	}
}
