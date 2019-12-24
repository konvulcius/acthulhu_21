/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:36:27 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/17 22:55:55 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	count_print(t_parse *storage, va_list *arg)
{
	int		*printed;

	printed = va_arg(*arg, int*);
	*printed = storage->printed + storage->string_length;
}