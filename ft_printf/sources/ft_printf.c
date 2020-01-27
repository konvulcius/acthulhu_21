/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:05:11 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/27 12:05:12 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	t_parse	storage;

	va_start(arg, format);
	storage.format_ptr = format;
	begin_func(&storage, &arg);
	va_end(arg);
	return (storage.printed);
}
