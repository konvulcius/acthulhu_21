/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_int_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:59:15 by lliza             #+#    #+#             */
/*   Updated: 2019/11/12 12:59:22 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

void	ft_add_int_precision(t_data *data_ptr, char **buff_ptr)
{
	if (data_ptr->precision > 0)
		while (data_ptr->precision-- != 0)
			*((*buff_ptr)++) = '0';
}
