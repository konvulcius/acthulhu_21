/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldbl_add_int_part_to_buff.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:47:25 by lliza             #+#    #+#             */
/*   Updated: 2019/11/25 13:02:06 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_ldbl_add_int_part_to_buff(char *buff, union u_ldbl *n)
{
	int		exp;
	int		bits_num;
	int		sh_num;
	char	temp[5000];

	sh_num = 3;
	bits_num = 64;
	exp = ft_get_exponent(n->dbl);
	if (exp >= 0)
		while (bits_num > 0 && exp >= 0)
		{
			if (n->bytes[3] & (1 << 15))
			{
				ft_bzero(temp, 5000);
				ft_fill_buff_for_one_two(temp, exp);
				ft_add_buff_to_buff(temp, buff);
			}
			ft_union_ldbl_bitmove_right(n, 1);
			n->bytes[4] -= 1;
			--exp;
			--sh_num;
			--bits_num;
		}
	else
		*buff = '0';
}
