/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_ldbl_bits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:56:26 by lliza             #+#    #+#             */
/*   Updated: 2019/11/26 16:16:48 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_show_ldbl_bits_print_line(void)
{
	ft_printf("---------------------------------------------");
	ft_printf("--------------------------------------------\n");
}

void			ft_show_ldbl_bits(union u_ldbl *un)
{
	int		i;
	int		j;

	i = 0;
	ft_show_ldbl_bits_print_line();
	ft_printf("                            significand ");
	ft_printf("                         |     exponent    | sign\n");
	ft_show_ldbl_bits_print_line();
	while (i < 5)
	{
		if (i == 4)
			ft_printf(" | ");
		j = 0;
		while (j < 16)
		{
			if (i == 4 && j == 15)
				ft_printf(" | ");
			ft_printf("%d", (un->bytes[i] & (1 << j++) ? 1 : 0));
		}
		++i;
	}
	ft_printf("\n");
	ft_show_ldbl_bits_print_line();
}
