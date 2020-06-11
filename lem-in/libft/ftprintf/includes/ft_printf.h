/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:34:52 by lliza             #+#    #+#             */
/*   Updated: 2019/11/26 16:54:32 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# define ALIGN_LEFT 1
# define ZERO 2
# define PLUS 4
# define BLANK 8
# define HASH 16
# define H 32
# define HH 64
# define L_LOWER 128
# define LL 256
# define L_UPPER 512
# define HEX_SMALL 1024
# define PRECISION_IS_THERE 2048
# define EXP_BIAS 16383

typedef struct	s_data
{
	short		flags;
	char		type;
	char		subtype;
	int			width;
	int			precision;
	va_list		args;
	int			fd;
}				t_data;
union			u_ldbl
{
	long double		dbl;
	unsigned short	bytes[5];
};
int				ft_printf(const char *s, ...);
/*
** 				<============================ tools =========================>
*/
int				ft_is_flag(char *s);
int				ft_is_length(char *s);
void			ft_calculate_precision(t_data *data_ptr, int num_len);
void			ft_calculate_width\
				(t_data *data_ptr, int num_len, long long num);
void			ft_calculate_width_unsigned\
				(t_data *data_ptr, int num_len, unsigned long long num);
/*
** 				<======================== end of tools ======================>
*/
void			ft_handle_specs(char **s, t_data *data_ptr, char **buff_ptr);
void			ft_handle_size_t(t_data *d_ptr, char **b_ptr);
void			ft_data_preprocessing(t_data *data_ptr);
void			ft_data_processing(t_data *data_ptr, char **buff_ptr);
void			ft_add_flag(char **s, t_data *data_ptr);
void			ft_add_width_to_data(char **s, t_data *data_ptr);
void			ft_add_length(char **s, t_data *data_ptr);
void			ft_add_precision_to_data(char **s, t_data *data_ptr);
void			ft_add_num_to_buff\
				(long long num, int base, t_data *data_ptr, char **buff_ptr);
void			ft_add_u_num_to_buff\
				(unsigned long long num, unsigned int base,
				t_data *data_ptr, char **buff_ptr);
void			ft_add_width_to_buff(t_data *data_ptr, char **buff_ptr);
void			ft_add_hex_to_buff\
				(t_data *data_ptr, char **buff_ptr, long long num);
void			ft_add_int_precision(t_data *data_ptr, char **buff_ptr);
void			ft_add_figures_to_buff\
				(long long num, int base, t_data *data_ptr, char **buff_ptr);
void			ft_add_figures_to_buff_unsigned\
				(unsigned long long num, unsigned int base,
				t_data *data_ptr, char **buff_ptr);
void			ft_add_char_to_buff\
				(unsigned char c, t_data *data_ptr, char **buff_ptr);
void			ft_add_string_to_buff\
				(char *s, t_data *data_ptr, char **buff_ptr);
void			ft_handle_strings_array(t_data *d_ptr, char **b_ptr);
/*
** 				<========================= long double =======================>
*/
void			ft_show_ldbl_bits(union u_ldbl *un);
int				ft_get_exponent(long double n);
void			ft_get_int_part(long double n);
void			ft_add_figure_to_buff(char *buff, int n);
void			ft_multiply_buff_by_two(char *buff);
void			ft_fill_buff_for_one_two(char *buff, int exp);
void			ft_add_buff_to_buff(char *buff_one, char *buff_all);
void			ft_union_ldbl_bitmove_right(union u_ldbl *un, int shift);
void			ft_convert_ldbl_to_fraction(union u_ldbl *un);
void			ft_round_ldbl_up(char *buff_int, char *buff_fraction);
void			ft_ldbl_add_int_part_to_buff(char *buff, union u_ldbl *n);
void			ft_ldbl_add_precision_to_buff\
		(union u_ldbl *un, char *buff_int, char *buff_fraction, int precision);
char			*ft_ldbl_one_buff_to_rule_them_all\
				(t_data *data_ptr, char *buff_int, char *buff_fraction);
void			ft_handle_double(t_data *data, char **buff_ptr, long double n);
/*
** 				<====================== end of long double ===================>
*/
/*
** 				<============================ color ==========================>
*/
void			ft_color_input(char **format_s, char **buff);
/*
** 				<======================== end of color =======================>
*/
#endif
