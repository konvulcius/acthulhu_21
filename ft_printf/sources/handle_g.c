/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_g.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:47:21 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/24 20:47:24 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_g(t_parse *storage, t_float_point *container)
{
	if (storage->precision > container->exp_10 && container->exp_10 >= -4)
	{
		storage->precision -= 1 + container->exp_10;
		handle_f(storage, container);
	}
	else
	{
		storage->precision -= 1;
		handle_e(storage, container);
	}
}
