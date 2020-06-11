/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_precision_to_data.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:01:58 by lliza             #+#    #+#             */
/*   Updated: 2019/11/21 15:50:15 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_add_precision_to_data(char **s, t_data *data_ptr)
{
	data_ptr->flags |= PRECISION_IS_THERE;
	++*s;
	if (**s == '*')
	{
		data_ptr->precision = va_arg(data_ptr->args, int);
		++*s;
	}
	if (ft_isdigit(**s))
	{
		data_ptr->precision = 0;
		while (ft_isdigit(**s))
		{
			if (data_ptr->precision)
				data_ptr->precision *= 10;
			data_ptr->precision += **s - '0';
			++*s;
		}
	}
}
