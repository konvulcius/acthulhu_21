/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_figures_to_buff_unsigned.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:53:26 by lliza             #+#    #+#             */
/*   Updated: 2019/11/26 16:53:37 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern char *g_nums_low;
extern char *g_nums_up;

void	ft_add_figures_to_buff_unsigned\
	(unsigned long long num, unsigned int base, t_data *d_ptr, char **buff_ptr)
{
	char *s;

	s = (d_ptr->flags & HEX_SMALL) ? g_nums_low : g_nums_up;
	if (num >= base)
		ft_add_figures_to_buff((num / base), base, d_ptr, buff_ptr);
	*((*buff_ptr)++) = s[(num % base)];
}
