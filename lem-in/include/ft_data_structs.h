#ifndef FT_DATA_STRUCTS_H
# define FT_DATA_STRUCTS_H

# define MAX_LL 9223372036854775807ULL
# define MAXIMAL_INT 2147483647LL

typedef struct		s_avl
{
	size_t			index;
	ssize_t			value;
	unsigned char	height;
	struct s_avl	*left;
	struct s_avl	*right;
}					t_avl;

typedef struct		s_path
{
	ssize_t			*path_point;
	size_t			path_length;
	struct s_path	*next_path;
}					t_path;

typedef	struct		s_r_new
{
	ssize_t			ant_num;
	char			*name;
	int				type;
	int				val;
	int				x;
	int				y;
	t_avl			*links_out;
	size_t			t_row_index;
	struct s_r_new	*out;
}					t_l_room;

typedef struct		s_row
{
	t_l_room		*room;
	size_t			len;
	size_t			prev_index;
}					t_row;

typedef struct		s_single
{
	t_l_room		*room;
	size_t			len;
	struct s_single	*next;
}					t_single;

typedef struct		s_l_data
{
	t_list			*start;
	t_list			*end;
	t_list			*begin_list;
	ssize_t			ants_num;
	t_list			*rooms;
	t_row			**table;
	size_t			all_in_one;
	size_t			every_move;
	size_t			print_data;
	size_t			print_path;
	size_t			print_help;
	size_t			table_curr_size;
	size_t			rooms_count;
	size_t			num_of_paths;
	ssize_t			paths_sum;
	t_avl			**paths_box;
	size_t			paths_max_len;
	t_path			*all_ways;
}					t_l_data;

#endif
