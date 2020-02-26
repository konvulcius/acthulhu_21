#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "get_next_line.h"
# include <stdarg.h>

# define VALID_SP "cspdDiouxXfFeEgG%naAC"
# define VALID_FLAGS "0123456789.* '#+-Llhzj"
# define MAX_LEN_INTEGER 25
# define LL_MAX 9223372036854775807
# define MAX_DOUBLE_LEN 16500
# define MAX_DIGIT 1000000000
# define DIGIT_COUNT 9
# define BUF_LEN 1833

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
}					t_flags;

typedef struct		s_parse
{
	int				printed;
	int				string_length;
	char			box[BUFF_SIZE];
	int				specfr_len;
	int				current;
	const char		*format_ptr;
	t_flags			flags;
	t_token			token;
	int				width;
	int				precision;
}					t_parse;

typedef struct		s_float
{
	long long		mant : 64;
	unsigned int	exp : 15;
	unsigned int	sign : 1;
}					t_float;

typedef union		u_double
{
	t_float			notion;
	long double		value;
}					t_double;

typedef struct		s_float_point
{
	int				full_number[BUF_LEN];
	int				index;
	int				exp_10;
	int				exp_2;
	int				last_exp;
}					t_float_point;

typedef struct		s_values
{
	int				i;
	int				j;
}					t_values;

/*
**	------------				ft_printf.c					--------------------
*/
int					ft_printf(const char *format, ...);
/*
**	------------				begin_func.c				--------------------
*/
void				begin_func(t_parse *storage, va_list *arg);
void				start_solution(t_parse *storage, va_list *arg);
int					parse_specifier(t_parse *storage, va_list *arg);
int					default_parse(t_parse *storage, va_list *arg);
/*
**	------------				count_print.c				--------------------
*/
void				count_print(t_parse *storage, va_list *arg);
/*
**	------------				e_string_solver.c			--------------------
*/
void				e_string_solver(t_parse *storage, char *float_str);
/*
**	------------				error.c						--------------------
*/
void				error(void);
/*
**	------------				float_solver.c				--------------------
*/
void				parse_sign_precision(t_parse *storage, t_double *imagine);
void				float_handler(t_parse *storage, t_double *imagine);
void				float_solver(t_parse *storage, va_list *arg);
int					handle_inf_nan(t_parse *storage, t_double *imagine);
void				handle_entire(t_double *imagine, t_float_point *container);
void				handle_small_tail(t_double *imagine, \
						t_float_point *container);
void				handle_large_tail(t_double *imagine, \
						t_float_point *container);
/*
**	------------				float_rounding.c			--------------------
*/
void				handle_rounding(t_parse *storage, char *string);
/*
**	------------				ft_arithm.c					--------------------
*/
void				ft_arithm_multiplication(int *box, int pow, int base, \
						t_float_point *container);
void				ft_arithm_division(int *box, int begin, int count);
void				ft_entire_sum(const int *box2, t_float_point *container, \
						int start);
void				ft_tail_sum(const int *box2, t_float_point *container, \
						int start);
/*
**	------------				flag_cleaner.c				--------------------
*/
void				flag_cleaner(t_parse *storage);
/*
**	------------				f_string_solver.c			--------------------
*/
void				f_string_solver(t_parse *storage, char *float_str);
/*
**	------------				handle_signed_string.c		--------------------
*/
void				int_minus(t_parse *storage, char *string);
void				int_no_minus(t_parse *storage, char *string);
void				signed_string_solver(t_parse *storage, char *digit);
/*
**	------------				handle_unsigned_string.c	--------------------
*/
int					ft_hex_to_i(const char *str);
void				handle_hash(t_parse *storage, char *string);
void				uint_minus(t_parse *storage, char *string);
void				uint_no_minus(t_parse *storage, char *string);
void				unsigned_string_solver(t_parse *storage, \
						char *unsigned_digit);
/*
**	------------				handle_precision.c			--------------------
*/
void				handling_digit_precision(t_parse *storage, char *string, \
						void (*f)(t_parse *, char *));
/*
**	------------				handle_flags.c				--------------------
*/
int					handle_sign(t_parse *storage);
void				handle_image(t_parse *storage, int len);
/*
**	------------				handle_unsigned.c			--------------------
*/
unsigned long long	handle_unsigned(t_parse *storage, va_list *arg);
void				handle_u(t_parse *storage, va_list *arg);
void				handle_p(t_parse *storage, va_list *arg);
void				handle_octet(t_parse *storage, va_list *arg);
void				handle_hex(t_parse *storage, va_list *arg);
/*
**	------------				handle_f.c					--------------------
*/
void				handle_f(t_parse *storage, t_float_point *container);
/*
**	------------				handle_e.c					--------------------
*/
void				handle_e(t_parse *storage, t_float_point *container);
/*
**	------------				handle_g.c					--------------------
*/
void				handle_g(t_parse *storage, t_float_point *container);
/*
**	------------				parse_flags.c				--------------------
*/
int					validation(t_parse *storage);
void				parse_flags(t_parse *storage, va_list *arg);
void				parse_width_precision(t_parse *storage, va_list *arg);
void				parse_precision(t_parse *storage, va_list *arg);
/*
**	------------				printers.c					--------------------
*/
void				ft_printer(t_parse *storage);
void				ft_print_end(t_parse *storage);
void				move_to_print(t_parse *storage, char elem);
/*
**	------------				string_char.c				-------------------
*/
void				if_minus(t_parse *storage, char *string, char *elem);
void				no_minus(t_parse *storage, char *string, char *elem);
void				string_solver(t_parse *storage, va_list *arg, char *elem);
void				char_solver(t_parse *storage, va_list *arg, char percent);
/*
**	------------				signed_solver.c				--------------------
*/
void				signed_solver(t_parse *storage, va_list *arg);
/*
**	------------				some_to_a.c					--------------------
*/
int					base_power(unsigned long long digit, int base);
int					ten_power(long long digit);
char				*ulltoa_base(unsigned long long digit, int base);
char				*lltoa(t_parse *storage, long long digit);
int					find_start(int *box);
/*
**	------------				unsigned_solver.c			--------------------
*/
void				unsigned_solver(t_parse *storage, va_list *arg);

#endif
