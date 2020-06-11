/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 11:39:32 by lliza             #+#    #+#             */
/*   Updated: 2020/04/22 15:51:16 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_H
# define FT_LEMIN_H

# include "libft.h"
# include "ft_printf.h"
# include "ft_data_structs.h"
# include "get_next_line.h"
# include <stdlib.h>

/*
** ft_array_fillers.c
*/
ssize_t			ft_find_position(t_l_data *data, char *name);
size_t			ft_parse_links(t_l_data *data, t_list **begin_list);
void			ft_fill_links(t_l_data *data, t_list **begin_list);
/*
** ft_avl_tree_init.c
*/
t_avl			*ft_avl_tree_init(size_t index);
ssize_t			ft_take_node_height(t_avl *node);
ssize_t			ft_tree_diff(t_avl *node);
void			ft_solve_node_height(t_avl *node);
/*
** ft_avl_tree_insert.c
*/
t_avl			*ft_rotateright(t_avl *node);
t_avl			*ft_rotateleft(t_avl *node);
t_avl			*ft_balance(t_avl *node);
t_avl			*ft_insert_node(t_avl *node, size_t index);
t_avl			*ft_lemin_avl_find_node(t_avl *root, size_t index);
/*
** ft_avl_tree_remove.c
*/
void			ft_avl_full_delete(t_avl **node);
t_avl			*ft_remove_node(t_avl *node, size_t index);
/*
** ft_errors.c
*/
void			ft_allocation_error(void);
void			ft_error_here(void);
/*
** ft_get_ways.c
*/
void			ft_delete_usefully_paths(t_l_data *data);
void			ft_print_paths(t_l_data *data);
void			ft_lemin_get_all_ways(t_l_data *data);
void			ft_delete_paths(t_path *paths);
/*
** ft_lemin_ant_move.c
*/
size_t			ft_lemin_decrease_ways_count(t_l_data *data, t_path *paths);
void			ft_lemin_ant_move(t_l_data *data, t_path *paths);
/*
** ft_lemin_bellman_ford.c
*/
void			bf_inner_check_edges
	(t_l_data *data, t_row *u_row, t_avl *node, size_t *check);
void			bf(t_l_data *data);
/*
** ft_lemin_check_path.c
*/
size_t			ft_check_path_usefully(t_l_data *data, t_list *start);
/*
** ft_lemin_check_ways_count.c
*/
ssize_t			ft_check_new_way(t_l_data *data);
/*
** ft_lemin_clear_data.c
*/
void			ft_lemin_clear_data(t_l_data **data);
/*
** ft_lemin_fill_data_utils.c
*/
void			ft_delete_strings(char **array);
void			ft_lemin_take_number_of_ants\
	(t_l_data *data, t_list **begin_list);
void			ft_read_input(t_l_data *data);
/*
** ft_lemin_fill_data.c
*/
size_t			ft_lemin_count_rooms(t_list *begin);
void			ft_fill_array(t_l_data *data, t_list **begin_list);
void			ft_lemin_fill_data(t_list *begin_list, t_l_data *data);
/*
** ft_lemin_fill_rooms.c
*/
void			ft_lemin_lst_add_last(t_list *lst, t_list *new_end);
void			ft_lemin_lst_add_second(t_list *head, t_l_room *new);
size_t			ft_lemin_check_room_parameters_duplicate\
	(t_list *lst, char *name, char *x, char *y);
void			ft_insert_room_in_list_sub\
	(t_l_data *data, char **line, size_t type);
void			ft_insert_room_in_list(t_l_data *data, char *s, size_t type);
void			ft_parse_comment(t_l_data *data, t_list **begin_list);
/*
** ft_lemin_find_way_utils.c
*/
void			ft_change_cross_tube(t_avl **paths_box, t_single *way_node, \
					ssize_t value);
void			ft_delete_nodes_from_way(t_avl **paths_box, t_single *start);
void			ft_delete_reverse_node(t_avl **paths_box, size_t index, \
					size_t next_index);
size_t			ft_check_exit(t_avl **paths_box, t_single *way_node);
/*
** ft_lemin_init.c
*/
t_l_data		*ft_lemin_init_data(void);
t_l_room		*ft_lemin_init_room(char *name, int x, int y);
void			ft_lemin_init_table(t_l_data *data);
void			ft_lemin_reset_table(t_l_data *data);
/*
** ft_lemin_print_moves.c
*/
void			ft_lemin_print_ants_move(t_l_data *data);
void			ft_lemin_print_all_in_one(t_l_data *data);
/*
** ft_lemin_print_rooms.c
*/
void			ft_lemin_traverse_tree\
	(t_l_data *data, t_avl *root, void (*f)(t_l_data *, t_avl *));
void			ft_lemin_print_node(t_l_data *data, t_avl *node);
void			ft_lemin_print_room(t_l_data *data, void *room);
void			ft_lemin_print_rooms(t_l_data *data);
/*
** ft_lemin_print.c
*/
void			ft_lemin_print_data(t_l_data *data, int show_input_rooms_data);
void			ft_lemin_print_map(t_l_data *data);
void			ft_print_every_ant(t_l_data *data);
/*
** ft_lemin_suurballe_utils.c
*/
t_avl			*ft_lemin_avl_change_nodes\
			(t_avl *root, size_t node_index, size_t new_index);
void			ft_lemin_avl_change_neighbours_links_out\
			(t_row **table, t_avl *root, size_t node_index, size_t new_index);
/*
** ft_lemin_suurballe.c
*/
t_avl			*ft_avl_tree_init_with_value(size_t index, int value);
t_avl			*ft_insert_node_with_value\
	(t_avl *node, size_t index, int value);
t_l_room		*ft_lemin_make_in_2(t_l_data *data, t_row *row);
void			ft_lemin_split_all(t_l_data *data, t_l_room *end);
void			ft_lemin_suurballe\
	(t_l_data *data, void (*algo)(t_l_data *data));
/*
** ft_save_way_in_table.c
*/
size_t			ft_save_new_way(t_l_data *data, t_single **start);
void			ft_delete_single_way(t_single **start, t_single *end);
/*
** ft_split_and_delete_reverse_node.c
*/
void			ft_2_and_3_step\
	(t_l_data *data, t_avl **paths_box, t_single *way_node);
/*
** ft_utils.c
*/
t_list			*ft_lstrev(t_list *start);
long long		ft_atoll(const char *str);
t_list			*ft_list_find\
	(t_list *begin_list, void *data_ref, size_t data_size, int (*cmp)());
int				ft_isspace(int c);
void			ft_delete_content(void *content, size_t size);
/*
** ft_validation.c
*/
int				ft_only_dig_validation(char *string);
int				ft_digit_compare(long long value);
size_t			ft_parse_room(char *line);
/*
** get_next_line.c
*/
int				get_next_line(const int fd, char **line);

#endif
