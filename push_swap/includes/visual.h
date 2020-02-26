#ifndef VISUAL_H
# define VISUAL_H

# include "push_swap.h"
# include <mlx.h>
# include <unistd.h>

# define RED 0x00ff0000
# define BLUE 0x000000ff
# define GREEN 0x0000ff00
# define WHITE 0x00ffffff
# define BORD 0x00610052
# define BACKGROUND 0x003dff77
# define WIN_WIDTH 1200
# define WIN_LENGTH 1000
# define LENGTH 400

typedef struct		s_atr
{
	t_list			*elem;
	float			length;
	float			color;
	struct s_atr	*next;
}					t_attr;

typedef struct		s_visual
{
	void			*ptr;
	void			*win;
	void			*image;
	int				width;
	int				count;
	int				fd;
	t_list			*max;
	t_list			*min;
	t_list			**stack_a;
	t_list			**stack_b;
	t_list			**stack_proc;
	t_list			*procedure_list;
	t_list			*procedure_itter;
	t_attr			*head;
}					t_visual;

/*
**		____________________	parse_attribute.c	____________________________
*/
int					parse_color(t_visual *vimlx, t_list *node);
void				parse_min_high(t_visual *vimlx);
int					parse_length(t_visual *vimlx, t_list *node);
int					parse_attr(t_visual *vimlx);
/*
**		________________________	visual.c		____________________________
*/
void				ft_visual(t_list **stack_a, t_list **stack_b, \
						t_list **stack_proc, int fd);
void				clear_window(t_visual *vimlx);
void				print_stack_length(t_visual *vimlx);
void				print_stack_name(t_visual *vimlx);
void				print_procedure(t_visual *vimlx, t_list *start, \
						int x, int y);
void				print_count_proc(t_visual *vimlx, t_list *proc_list);
void				draw_stack(t_visual *vimlx, t_list *stack);
int					choose_sleep_time(t_visual *vimlx);
void				stacks_painter(t_visual *vimlx);
/*
**		______________________	visual_interface.c	____________________________
*/
t_attr				*init_attr(t_list *elem);
void				delete_attr(t_attr **head);
t_attr				*create_attr_stack(t_list *stack_a);
t_attr				*find_next(t_attr *head, t_visual *vimlx);
void				take_param(t_visual *vimlx);

#endif
