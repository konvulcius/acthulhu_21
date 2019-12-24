/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:50:10 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/23 22:23:48 by acthulhu         ###   ########.fr       */
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
