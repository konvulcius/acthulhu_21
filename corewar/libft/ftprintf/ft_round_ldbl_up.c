/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_ldbl_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:49:16 by lliza             #+#    #+#             */
/*   Updated: 2019/11/21 18:44:13 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_round_ldbl_up(char *buff_int, char *buff_fraction)
{
	int	len;
	int sum;

	sum = 1;
	len = ft_strlen(buff_fraction);
	while (len > 0)
	{
		len--;
		sum += *(buff_fraction + len) - '0';
		*(buff_fraction + len) = (sum % 10) + '0';
		if (sum < 10)
			break ;
		sum /= 10;
	}
	if ((len == 0) && (*buff_fraction == '0' || !(*buff_fraction)))
		ft_add_figure_to_buff(buff_int, 1);
}
