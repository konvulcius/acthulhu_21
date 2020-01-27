/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:54:23 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/27 12:23:23 by acthulhu         ###   ########.fr       */
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
	char				*string_of_uint;

	value = handle_unsigned(storage, arg);
	string_of_uint = ulltoa_base(value, 10);
	handling_digit_precision(storage, string_of_uint, unsigned_string_solver);
}

void				handle_p(t_parse *storage, va_list *arg)
{
	unsigned long long	value;
	char				*string_of_uint;

	storage->flags.hash = 1;
	value = va_arg(*arg, unsigned long long);
	string_of_uint = ulltoa_base(value, 16);
	storage->width -= 2;
	handling_digit_precision(storage, string_of_uint, unsigned_string_solver);
}

void				handle_octet(t_parse *storage, va_list *arg)
{
	unsigned long long	value;
	char				*string_of_uint;

	value = handle_unsigned(storage, arg);
	string_of_uint = ulltoa_base(value, 8);
	if (*string_of_uint == '0' && storage->precision != 0)
		storage->flags.hash = 0;
	if (storage->flags.hash == 1)
	{
		--storage->width;
		if (storage->precision != 0)
			--storage->precision;
	}
	handling_digit_precision(storage, string_of_uint, unsigned_string_solver);
}

void				handle_hex(t_parse *storage, va_list *arg)
{
	unsigned long long	value;
	char				*string_of_uint;
	char				*x;

	value = handle_unsigned(storage, arg);
	string_of_uint = ulltoa_base(value, 16);
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
	handling_digit_precision(storage, string_of_uint, unsigned_string_solver);
}
