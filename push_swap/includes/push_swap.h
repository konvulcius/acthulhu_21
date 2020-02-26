#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "visual.h"
# include <fcntl.h>

# define MAXIMAL_INT 2147483647LL

typedef struct		s_args
{
	int				fd;
	int				visual;
}					t_args;

typedef struct		s_seq
{
	int				count;
	t_list			*target;
	struct s_seq	*next;

}					t_seq;

typedef struct		s_required
{
	t_list			*last_a;
	t_list			*node_a;
	t_list			*node_b;
	t_seq			*first;
	int				length;
}					t_required;

/*
**		________________________	error.c			____________________________
*/
void				stop(void);
void				allocation_error(void);
void				the_error(void);
/*
**		___________________		insert_instruction.c	________________________
*/
void				insert_instructions(t_list **stack_a, t_list **stack_b, \
						t_list **stack_proc);
void				content_del(void *content, size_t size);
void				end_of_checker(t_list **stack_a, t_list **stack_b, int fd);
void				procedure_itter(t_list **stack_a, t_list **stack_b, \
						t_list **stack_proc, int fd);
/*
**		____________________	ft_lstiter_int.c		________________________
*/
int					ft_lstiter_int(t_list *lst, int (*f)(t_list *elem));
/*
**		________________________	reader.c		____________________________
*/
t_list				*arguments_reader(int last, char **argv);
t_list				*instructions_reader(int fd);
/*
**		________________________	procedure.c		____________________________
*/
void				procedure_swap(t_list **top);
void				procedure_push(t_list **dest, t_list **source);
void				procedure_rotate(t_list **top);
void				procedure_reverse_rotate(t_list **top);
void				double_procedure(t_list **stack_a, t_list **stack_b, \
						void (*f)(t_list **));
/*
**		________________________	validation.c	____________________________
*/
int					only_dig_validation(char *string);
int					digit_compare(t_list *elem);
void				instructions_validation(t_list *start);
int					check_same(t_list *stack);
/*
**		________________________	stack_checker.c	____________________________
*/
int					find_count(t_list *stack);
void				find_last(t_list *stack, t_list **last);
t_list				*check_accending_order(t_list *stack);
void				stack_checker(t_list **stack_a, t_list **stack_b, \
						t_required *values, int fd);
/*
**		________________________	algorithm.c		____________________________
*/
void				delete_seq_data(t_seq **first, t_seq *stop);
void				find_max_sequence(t_list *stack, t_required *values);
void				ft_instruction(t_list **stack_a, t_list **stack_b, \
						char *name, int fd);
void				part_one(t_list **stack_a, t_list **stack_b, \
						t_required *values, int fd);
int					choice_rotate_reverse(t_list *begin, t_list *goal, \
						int *count);
void				part_two(t_list **stack_a, t_list **stack_b, \
						t_required *values, int fd);
void				part_three(t_list **stack_a, t_list **stack_b, int fd);
void				simple_solver(t_list **stack_a, t_list **stack_b, \
						t_required *values, int fd);

#endif
