/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:56:01 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/24 20:56:07 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_solver(t_parse *storage, va_list *arg)
{
	char		*string_of_int;
	long long	value;

	if (storage->specfr_len >= 2 && \
		!ft_strncmp(&storage->format_ptr[storage->specfr_len - 2], "ll", 2))
		value = va_arg(*arg, long long);
	else if (storage->specfr_len >= 2 && \
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
	handling_digit_precision(storage, string_of_int, signed_string_solver);
}
