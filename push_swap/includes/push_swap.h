/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:08:05 by acthulhu          #+#    #+#             */
/*   Updated: 2020/02/03 18:03:16 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <fcntl.h>
#include <stdio.h> // Убрать

# define MAXIMAL_INT 2147483647LL
# define MINIMAL_INT -2147483648LL

typedef struct	s_stacks
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_list		*stack_proc;
}				t_stacks;

typedef struct	s_required
{
	t_list		*last_a;
	t_list		*last_b;
	t_list		*min_a;
	t_list		*max_a;
}				t_required;

/*
**		________________________	error.c			____________________________
*/
void			stop(void);
void			allocation_error(void);
void			error(void);
/*
**		________________________	reader.c		____________________________
*/
t_list			*arguments_reader(int last, char **argv);
t_list			*instructions_reader(void);
/*
**		________________________	procedure.c		____________________________
*/
void			procedure_swap(t_list **top);
void			procedure_push(t_list **dest, t_list **source);
void			procedure_rotate(t_list **top);
void			procedure_reverse_rotate(t_list **top);
void			double_procedure(t_list **stack_a, t_list **stack_b, \
					void (*f)(t_list **));
/*
**		________________________	validation.c	____________________________
*/
void			only_dig_validation(char *string);
void			digit_compare(t_list *elem);
void			instructions_validation(t_list *start);
void			check_same(t_list *stack);
/*
**		________________________	stack_checker.c	____________________________
*/
void			find_required(t_list *stack, t_required *values);
t_list			*check_accending_order(t_list *stack);
//t_list			*check_descending_order(t_list *stack);
void			print_stack(t_list *stack);
void			stack_checker(t_list **stack_a, t_list **stack_b, \
					t_required *values, int fd);
/*
**		________________________	algorithm.c		____________________________
*/
// void			only_push_a(t_list **stack_a, t_list **stack_b, int fd);
void			get_b_last(t_list *stack, t_required *values);
void			rotate_action(t_list **stack_a, t_list **stack_b, \
					t_required *values, int fd);
void			reverse_reverse(t_list **stack_a, t_list **stack_b, \
					t_required *values, int fd);
void			swap_action(t_list **stack_a, t_list **stack_b, int fd);
int				find_way(t_list *stack, t_list *wrong);
void			first_part(t_list **stack_a, t_list **stack_b, t_required *values, \
					int fd);
void			second_part(t_list **stack_a, t_list **stack_b, t_required *values, \
					int fd);
void			third_part(t_list **stack_a, t_list **stack_b, t_required *values, \
					int fd);
// int				choos_way(t_list *stack_a, t_required *values, t_list **target);
// void			a_rolling(t_list **stack_a, t_list **stack_b, \
// 					t_required *values, int fd);
// void			b_rolling(t_list **stack_a, t_list **stack_b, \
// 					t_required *values, int fd);
void			ft_instruction(t_list **stack_a, t_list **stack_b, char *name, \
					int fd);

#endif