/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_buff_to_buff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <lliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:44:05 by lliza             #+#    #+#             */
/*   Updated: 2019/11/21 17:44:10 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_buff_to_buff(char *buff_one, char *buff_all)
{
	while (*buff_one)
	{
		ft_add_figure_to_buff(buff_all, *buff_one - '0');
		++buff_one;
		++buff_all;
	}
}
