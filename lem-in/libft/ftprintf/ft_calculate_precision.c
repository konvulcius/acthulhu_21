/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:03:48 by lliza             #+#    #+#             */
/*   Updated: 2019/11/12 13:04:02 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_calculate_precision(t_data *data_ptr, int num_len)
{
	if ((data_ptr->flags & HASH) && data_ptr->type == 'o')
		if (data_ptr->precision <= num_len)
		{
			if (num_len == 0)
				data_ptr->precision = 0;
			else
				data_ptr->precision = 1;
			return ;
		}
	if (num_len == 0)
	{
		if (data_ptr->precision)
			data_ptr->precision -= 1;
	}
	else if (data_ptr->precision > num_len)
		data_ptr->precision -= num_len;
	else
		data_ptr->precision = 0;
}
