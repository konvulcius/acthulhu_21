/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:35:11 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/24 16:35:18 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	count_print(t_parse *storage, va_list *arg)
{
	int		*printed;

	printed = va_arg(*arg, int*);
	*printed = storage->printed + storage->string_length;
}
