/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:07:56 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/20 23:56:14 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	handle_unsigned(t_parse *storage, va_list *arg)
{
	if ((storage->specfr_len >= 2 && \
		!ft_strncmp(&storage->format_ptr[storage->specfr_len - 2], "ll", 2)))
		return (va_arg(*arg, unsigned long long));
	if (storage->specfr_len >= 2 && \
		!ft_strncmp(&storage->format_ptr[storage->specfr_len - 2], "hh", 2))
		return ((unsigned char)va_arg(*arg, unsigned int));
	if (storage->format_ptr[storage->specfr_len - 1] == 'l')
		return (va_arg(*arg, unsigned long));
	if (storage->format_ptr[storage->specfr_len - 1] == 'h')
		return ((unsigned short)va_arg(*arg, unsigned int));
	if (storage->format_ptr[storage->specfr_len - 1] == 'z')
		return (va_arg(*arg, size_t));
	return (va_arg(*arg, unsigned int));
}

void				handle_u(t_parse *storage, va_list *arg)
{
	unsigned long long	value;
	char		*string_of_uint;

	value = handle_unsigned(storage, arg);
	string_of_uint = ulltoa_base(value, 10);
	handling_digit_precision(storage, &string_of_uint);
	unsigned_string_solver(storage, string_of_uint);	
	ft_strdel(&string_of_uint);
}

void				handle_p(t_parse *storage, va_list *arg)
{
	unsigned long long	value;
	char		*string_of_uint;

	storage->flags.hash = 1;
	
	value = va_arg(*arg, unsigned long long);
	string_of_uint = ulltoa_base(value, 16);
	handling_digit_precision(storage, &string_of_uint);
	storage->width -= 2;
	unsigned_string_solver(storage, string_of_uint);
	ft_strdel(&string_of_uint);
}

void				handle_octet(t_parse *storage, va_list *arg)
{
	unsigned long long	value;
	char		*string_of_uint;

	value = handle_unsigned(storage, arg);
	string_of_uint = ulltoa_base(value, 8);
	handling_digit_precision(storage, &string_of_uint);
	if (*string_of_uint == '0' && storage->precision != 0)
		storage->flags.hash = 0;
	if (storage->flags.hash == 1)
		storage->width -= 1;
	unsigned_string_solver(storage, string_of_uint);
	ft_strdel(&string_of_uint);
}

void				handle_hex(t_parse *storage, va_list *arg)
{
	unsigned long long	value;
	char		*string_of_uint;
	char		*x;

	value = handle_unsigned(storage, arg);
	string_of_uint = ulltoa_base(value, 16);
	handling_digit_precision(storage, &string_of_uint);
	if (storage->flags.hash == 1 && ft_hex_to_i(string_of_uint))
		storage->width -= 2;
	if (storage->format_ptr[storage->specfr_len] == 'X')
	{
		x = string_of_uint;
		while (*x)
		{
			*x = ft_toupper(*x);
			x++;
		}
	}
	unsigned_string_solver(storage, string_of_uint);
	ft_strdel(&string_of_uint);
}
