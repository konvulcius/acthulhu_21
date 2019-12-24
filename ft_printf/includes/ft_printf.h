/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:44:49 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/23 21:05:02 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include "libft.h"
# include <stdarg.h>
# include <float.h>
# include <limits.h>
# include <stdio.h> //Удалить!!!

# define VALID_SP "cspdiouxXfeEgG%n"
# define VALID_FLAGS "0123456789.* '#+-Llhz"
# define DOUBLE_LEN 16500

typedef enum		e_image
{
	NOTHING,
	ZERO,
	MINUS,
}					t_image;

typedef enum		e_sign
{
	EMPTY,
	SPACE = 32,
	PLUS = 43,
}					t_sign;

typedef enum		e_token
{
	NEGATIVE = 45,
	POSITIVE = 43,
}					t_token;

typedef struct		s_flags
{
	int				hash;
	t_image			image;
	t_sign			sign;
	int				quote; // Нужен ли???
}					t_flags;

typedef struct		s_parse
{
	int				printed;
	int				string_length;	
	char			box[BUFF_SIZE];
	int				specfr_len;
	const char		*format_ptr;
	t_flags			flags;
	t_token			token;
	int				width;
	int				precision;	
}					t_parse;

typedef struct		s_float
{
	long long		mant : 63;
	int				exp : 16;
	int				sign : 1;
}					t_float;

typedef union		u_double
{
	t_float			notion;
	long double		value;
}					t_double;

typedef struct		s_float_point
{
	char			full_number[DOUBLE_LEN];
	int				exp_10;
	int				exp_2;
	int				last_exp;
}					t_float_point;

/*
**	ft_printf.c
*/
int					ft_printf(const char *format, ...);
/*
**	printers.c
*/
void				ft_printer(t_parse *storage);
void				ft_print_end(t_parse *storage);
void				move_to_print(t_parse *storage, char elem);
/*
**	begin_func.c
*/
void				begin_func(t_parse *storage, va_list *arg);
void				start_solution(t_parse *storage, va_list *arg);
int					parse_specifier(t_parse *storage, va_list *arg);
int					default_parse(t_parse *storage, va_list *arg);
/*
**	parse_flags.c
*/
int					validation(t_parse *storage);
void				parse_flags(t_parse *storage);
void				parse_width_precision(t_parse *storage, va_list *arg);
void				parse_precision(t_parse *storage, va_list *arg,
						const char *dot);
/*
**	string_char.c
*/
void				if_minus(t_parse *storage, char *string, char *elem);
void				no_minus(t_parse *storage, char *string, char *elem);
void				string_solver(t_parse *storage, va_list *arg, char *elem);
void				char_solver(t_parse *storage, va_list *arg);
/*
**	handle_signed_string.c
*/
void				handling_digit_precision(t_parse *storage, char **string);
void				int_minus(t_parse *storage, char *string);
void				int_no_minus(t_parse *storage, char *string);
void				signed_string_solver(t_parse *storage, char *digit);
/*
**	handle_unsigned_string.c
*/
int					ft_hex_to_i(const char *str);
void				handle_hash(t_parse *storage, char *string);
void				uint_minus(t_parse *storage, char *string);
void				uint_no_minus(t_parse *storage, char *string);
void				unsigned_string_solver(t_parse *storage, char *unsigned_digit);
/*
**	handle_precision.c
*/
void				handling_digit_precision(t_parse *storage, char **string);
/*			
**	count_print.c
*/
void				count_print(t_parse *storage, va_list *arg);
/*
**	signed_solver.c
*/
void				signed_solver(t_parse *storage, va_list *arg);
void				int_flags_handle(t_parse *storage, char **string);
/*
**	unsigned_solver.c
*/
void				unsigned_solver(t_parse *storage, va_list *arg);
/*
**	handle_unsigned.c
*/
unsigned long long	handle_unsigned(t_parse *storage, va_list *arg);
void				handle_u(t_parse *storage, va_list *arg);
void				handle_p(t_parse *storage, va_list *arg);
void				handle_octet(t_parse *storage, va_list *arg);
void				handle_hex(t_parse *storage, va_list *arg);
/*
**	float_solver.c
*/
void				parse_sign_precision(t_parse *storage, t_double *imagine);
void				float_handler(t_parse *storage, t_double *imagine);
void				handle_entire(t_double *imagine, t_float_point *container);
void				handle_tail(t_double *imagine, t_float_point *container);
void				float_solver(t_parse *storage, va_list *arg);
int					handle_inf_nan(t_parse *storage, t_double *imagine);

/* 
**	flag_cleaner.c
*/
void				flag_cleaner(t_parse *storage);
/* 
**	find_between.c
*/
char				*find_between(const char *s1, const char *s2, int c);
/*
**	some_to_a.c
*/
int					base_power(unsigned long long digit, int base);
int					ten_power(long long digit);
char				*ulltoa_base(unsigned long long  digit, int base);
char				*lltoa(t_parse *storage, long long  digit);
/*
**	error.c
*/
void				error(t_parse *storage);
void				bad_alloc(void);
/*
**	ft_arithm.c
*/
int					ft_arithm_multiplication(char *box, int amount, int pow, int base);
void				ft_arithm_division(char *box, int begin, int count);
void				ft_string_sum(char *box1, const char *box2, int count);
int					find_start(char *box);

#endif
