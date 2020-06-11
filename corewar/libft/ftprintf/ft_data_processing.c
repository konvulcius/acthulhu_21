#include <stddef.h>
#include "ft_printf.h"

static void		ft_handle_decimal(t_data *d_ptr, char **b_ptr)
{
	ft_data_preprocessing(d_ptr);
	if (d_ptr->flags & L_LOWER)
		ft_add_num_to_buff(va_arg(d_ptr->args, long int), 10, d_ptr, b_ptr);
	else if (d_ptr->flags & LL)
		ft_add_num_to_buff(va_arg(d_ptr->args, long long int),
						10, d_ptr, b_ptr);
	else if (d_ptr->flags & H)
		ft_add_num_to_buff((short)va_arg(d_ptr->args, int), 10, d_ptr, b_ptr);
	else if (d_ptr->flags & HH)
		ft_add_num_to_buff((char)va_arg(d_ptr->args, int), 10, d_ptr, b_ptr);
	else
		ft_add_num_to_buff(va_arg(d_ptr->args, int), 10, d_ptr, b_ptr);
}

static void		ft_handle_oxu(t_data *d_ptr, char **b_ptr)
{
	unsigned int base;

	ft_data_preprocessing(d_ptr);
	if (d_ptr->type == 'o' || d_ptr->type == 'O')
		base = 8;
	else
		base = (d_ptr->type == 'u') ? 10 : 16;
	if (d_ptr->type == 'x')
		d_ptr->flags |= HEX_SMALL;
	if (d_ptr->flags & L_LOWER)
		ft_add_u_num_to_buff(va_arg(d_ptr->args, unsigned long int),
						base, d_ptr, b_ptr);
	else if (d_ptr->flags & LL)
		ft_add_u_num_to_buff(va_arg(d_ptr->args, unsigned long long int),
						base, d_ptr, b_ptr);
	else if (d_ptr->flags & H)
		ft_add_u_num_to_buff((unsigned short)va_arg(d_ptr->args, unsigned int),
							base, d_ptr, b_ptr);
	else if (d_ptr->flags & HH)
		ft_add_u_num_to_buff((unsigned char)va_arg(d_ptr->args, unsigned int),
							base, d_ptr, b_ptr);
	else
		ft_add_u_num_to_buff(va_arg(d_ptr->args, unsigned int),
							base, d_ptr, b_ptr);
}

static void		ft_handle_p(t_data *d_ptr, char **b_ptr, unsigned long num)
{
	ft_data_preprocessing(d_ptr);
	if (!num)
		if (d_ptr->precision <= 0)
			if (d_ptr->flags & PRECISION_IS_THERE)
			{
				ft_add_hex_to_buff(d_ptr, b_ptr, num);
				return ;
			}
	d_ptr->flags |= HEX_SMALL;
	d_ptr->flags |= HASH;
	d_ptr->flags |= PRECISION_IS_THERE;
	ft_add_num_to_buff(num, 16, d_ptr, b_ptr);
}

static void		ft_handle_bonus(t_data *d_ptr, char **b_ptr)
{
	if (d_ptr->type == 'b')
		ft_add_num_to_buff(va_arg(d_ptr->args, int), 2, d_ptr, b_ptr);
	else if (d_ptr->type == 'z')
		ft_handle_size_t(d_ptr, b_ptr);
	else if (d_ptr->type == 'Q')
		ft_handle_strings_array(d_ptr, b_ptr);
}

void			ft_data_processing(t_data *d_ptr, char **b_ptr)
{
	if (d_ptr->type == '%')
		ft_add_char_to_buff('%', d_ptr, b_ptr);
	else if (d_ptr->type == 'c')
		ft_add_char_to_buff(va_arg(d_ptr->args, unsigned int), d_ptr, b_ptr);
	else if (d_ptr->type == 's')
		ft_add_string_to_buff(va_arg(d_ptr->args, char *), d_ptr, b_ptr);
	else if (d_ptr->type == 'd' || d_ptr->type == 'i')
		ft_handle_decimal(d_ptr, b_ptr);
	else if (d_ptr->type == 'x' || d_ptr->type == 'X' ||
			d_ptr->type == 'u' || d_ptr->type == 'o' || d_ptr->type == 'O')
		ft_handle_oxu(d_ptr, b_ptr);
	else if (d_ptr->type == 'p')
		ft_handle_p(d_ptr, b_ptr, (unsigned long)va_arg(d_ptr->args, void *));
	else if (d_ptr->type == 'f')
	{
		if (d_ptr->flags & L_UPPER)
			ft_handle_double(d_ptr, b_ptr, va_arg(d_ptr->args, long double));
		else
			ft_handle_double(d_ptr, b_ptr, va_arg(d_ptr->args, double));
	}
	else if (d_ptr->type == 'b' || d_ptr->type == 'z' || d_ptr->type == 'Q')
		ft_handle_bonus(d_ptr, b_ptr);
}
