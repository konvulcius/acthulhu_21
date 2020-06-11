/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_exponent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:34:43 by lliza             #+#    #+#             */
/*   Updated: 2019/11/21 17:34:45 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_get_exponent(long double n)
{
	union u_ldbl	num;
	unsigned short	exp;

	num.dbl = n;
	ft_memcpy(&exp, &num.bytes[4], 15);
	exp <<= 1;
	exp >>= 1;
	return (int)(exp - EXP_BIAS);
}
