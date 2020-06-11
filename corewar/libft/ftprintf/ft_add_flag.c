/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:57:57 by lliza             #+#    #+#             */
/*   Updated: 2019/11/12 12:57:59 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_flag(char **s, t_data *data_ptr)
{
	if (**s == '-')
		data_ptr->flags |= ALIGN_LEFT;
	if (**s == '0')
		data_ptr->flags |= ZERO;
	if (**s == '+')
		data_ptr->flags |= PLUS;
	if (**s == ' ')
		data_ptr->flags |= BLANK;
	if (**s == '#')
		data_ptr->flags |= HASH;
}
