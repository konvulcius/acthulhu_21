/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 20:07:07 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/23 19:27:09 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_flags_handle(t_parse *storage, char **string)
{
	handling_digit_precision(storage, string);
	signed_string_solver(storage, *string);
	ft_strdel(string);
}

void	signed_solver(t_parse *storage, va_list *arg)
{
	char		*string_of_int;
	long long	value;

	if (storage->specfr_len > 2 && \
		!ft_strncmp(&storage->format_ptr[storage->specfr_len - 2], "ll", 2))
		value = va_arg(*arg, long long);
	else if (storage->specfr_len > 2 && \
		!ft_strncmp(&storage->format_ptr[storage->specfr_len - 2], "hh", 2))
		value = (char)va_arg(*arg, int);
	else if (storage->format_ptr[storage->specfr_len - 1] == 'l')
		value = va_arg(*arg, long);
	else if (storage->format_ptr[storage->specfr_len - 1] == 'h')
		value = (short)va_arg(*arg, int);
	else if (storage->format_ptr[storage->specfr_len - 1] == 'z')
		value = va_arg(*arg, ssize_t);
	else
		value = va_arg(*arg, int);
	string_of_int = lltoa(storage, value);
	int_flags_handle(storage, &string_of_int);
}
