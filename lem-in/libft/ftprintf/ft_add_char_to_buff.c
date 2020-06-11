/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char_to_buff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:57:05 by lliza             #+#    #+#             */
/*   Updated: 2019/11/12 12:57:07 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

void	ft_add_char_to_buff(unsigned char c, t_data *data_ptr, char **buff_ptr)
{
	if (data_ptr->width)
		data_ptr->width--;
	if (!(data_ptr->flags & ALIGN_LEFT))
		ft_add_width_to_buff(data_ptr, buff_ptr);
	*((*buff_ptr)++) = c;
	ft_add_width_to_buff(data_ptr, buff_ptr);
}
