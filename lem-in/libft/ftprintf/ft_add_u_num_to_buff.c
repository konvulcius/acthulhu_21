/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_u_num_to_buff.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:52:39 by lliza             #+#    #+#             */
/*   Updated: 2019/11/26 16:53:11 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"
#include "libft.h"

static void		ft_add_sign(t_data *data_ptr, char **buff_ptr)
{
	if (data_ptr->flags & PLUS)
		*((*buff_ptr)++) = '+';
	else if (data_ptr->flags & BLANK)
		*((*buff_ptr)++) = ' ';
}

static void		ft_add_sign_and_hex\
	(t_data *data_ptr, char **buff_ptr, unsigned long long num)
{
	if (!(data_ptr->flags & ALIGN_LEFT))
	{
		if (data_ptr->flags & ZERO)
		{
			ft_add_sign(data_ptr, buff_ptr);
			ft_add_hex_to_buff(data_ptr, buff_ptr, num);
			ft_add_width_to_buff(data_ptr, buff_ptr);
		}
		else
		{
			ft_add_width_to_buff(data_ptr, buff_ptr);
			ft_add_sign(data_ptr, buff_ptr);
			ft_add_hex_to_buff(data_ptr, buff_ptr, num);
		}
	}
	else
	{
		ft_add_sign(data_ptr, buff_ptr);
		ft_add_hex_to_buff(data_ptr, buff_ptr, num);
	}
}

static void		ft_add_to_buff\
	(unsigned long long num, unsigned int base, t_data *d_ptr, char **buff_ptr)
{
	size_t num_len;

	num_len = ft_unsigned_num_len(num, base);
	ft_add_sign_and_hex(d_ptr, buff_ptr, num);
	ft_calculate_precision(d_ptr, num_len);
	ft_add_int_precision(d_ptr, buff_ptr);
	if (!((d_ptr->flags & PRECISION_IS_THERE) &&
		d_ptr->precision == 0 && num == 0))
		ft_add_figures_to_buff_unsigned(num, base, d_ptr, buff_ptr);
	else if ((d_ptr->flags & HASH) &&
		(d_ptr->type == 'o' || d_ptr->type == 'p'))
		ft_add_figures_to_buff_unsigned(num, base, d_ptr, buff_ptr);
	ft_add_width_to_buff(d_ptr, buff_ptr);
}

void			ft_add_u_num_to_buff\
	(unsigned long long num, unsigned int base, t_data *d_ptr, char **buff_ptr)
{
	size_t	len;

	len = ft_unsigned_num_len(num, base);
	ft_calculate_width_unsigned(d_ptr, len, num);
	ft_add_to_buff(num, base, d_ptr, buff_ptr);
}
