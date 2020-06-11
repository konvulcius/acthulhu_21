#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

static void		ft_add_sign(t_data *data_ptr, char **buff_ptr, int is_neg)
{
	if (is_neg)
		*((*buff_ptr)++) = '-';
	else
	{
		if (data_ptr->flags & PLUS)
			*((*buff_ptr)++) = '+';
		else if (data_ptr->flags & BLANK)
			*((*buff_ptr)++) = ' ';
	}
}

static void		ft_ldbl_add_width_to_buff(t_data *data_ptr, char **buff_ptr)
{
	char fill;

	if (data_ptr->width > 0)
	{
		if (data_ptr->flags & ALIGN_LEFT)
			fill = ' ';
		else
			fill = (data_ptr->flags & ZERO) ? '0' : ' ';
		while (data_ptr->width != 0)
		{
			*((*buff_ptr)++) = fill;
			data_ptr->width--;
		}
	}
}

static void		ft_ldbl_add_to_buff\
	(t_data *data_ptr, char **buff_ptr, char *buff_dbl, int is_neg)
{
	int		len;

	len = ft_strlen(buff_dbl);
	if (!(data_ptr->flags & ALIGN_LEFT))
	{
		if (data_ptr->flags & ZERO)
			ft_add_sign(data_ptr, buff_ptr, is_neg);
		ft_ldbl_add_width_to_buff(data_ptr, buff_ptr);
		if (!(data_ptr->flags & ZERO))
			ft_add_sign(data_ptr, buff_ptr, is_neg);
		ft_strcpy(*buff_ptr, buff_dbl);
		*buff_ptr += len;
	}
	else
	{
		ft_add_sign(data_ptr, buff_ptr, is_neg);
		ft_strcpy(*buff_ptr, buff_dbl);
		*buff_ptr += len;
		ft_ldbl_add_width_to_buff(data_ptr, buff_ptr);
	}
	free(buff_dbl);
}

static void		ft_ldbl_calculate_width\
	(t_data *data_ptr, char *buff, int is_neg)
{
	int len;

	if (data_ptr->width > 0)
	{
		len = ft_strlen(buff);
		data_ptr->width -= len + ((data_ptr->flags & BLANK) ||
			(data_ptr->flags & PLUS) || is_neg);
	}
}

void			ft_handle_double(t_data *d_ptr, char **buff, long double dbl)
{
	char			*buff_int;
	char			*buff_fraction;
	union u_ldbl	un;
	char			*b_ptr;
	int				is_neg;

	if (!(buff_int = (char *)malloc(sizeof(char) * 5000)))
		return ;
	if (!(buff_fraction = (char *)malloc(sizeof(char) * 5000)))
		return ;
	if (d_ptr->precision <= 0 && !(d_ptr->flags & PRECISION_IS_THERE))
		d_ptr->precision = 6;
	ft_bzero(buff_int, 5000);
	ft_bzero(buff_fraction, 5000);
	b_ptr = buff_int;
	is_neg = dbl < 0;
	un.dbl = is_neg ? -dbl : dbl;
	ft_ldbl_add_int_part_to_buff(b_ptr, &un);
	ft_convert_ldbl_to_fraction(&un);
	ft_ldbl_add_precision_to_buff(&un, b_ptr, buff_fraction, d_ptr->precision);
	b_ptr = ft_ldbl_one_buff_to_rule_them_all(d_ptr, buff_int, buff_fraction);
	ft_ldbl_calculate_width(d_ptr, b_ptr, is_neg);
	ft_ldbl_add_to_buff(d_ptr, buff, b_ptr, is_neg);
	free(buff_int);
	free(buff_fraction);
}
