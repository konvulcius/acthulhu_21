/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:50:31 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/24 14:11:15 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		default_parse(t_parse *storage, va_list *arg)
{
	if (!validation(storage))
		return (0);
	flag_cleaner(storage);
	parse_flags(storage);
	parse_width_precision(storage, arg);
	return (1);
}

int		parse_specifier(t_parse *storage, va_list *arg)
{
	const char	*specifiers;

	storage->specfr_len = 0;
	specifiers = VALID_SP;
	while (storage->format_ptr[storage->specfr_len])
	{
		if (ft_strchr(specifiers, storage->format_ptr[storage->specfr_len]))
			return (default_parse(storage, arg));
		storage->specfr_len++;
	}
	return (0);
}

void	start_solution(t_parse *storage, va_list *arg)
{
	if (storage->format_ptr[storage->specfr_len] == '%')
		string_solver(storage, NULL, "%");
	else if (storage->format_ptr[storage->specfr_len] == 'n')
		count_print(storage, arg);
	else if (storage->format_ptr[storage->specfr_len] == 'c')
		char_solver(storage, arg);
	else if (storage->format_ptr[storage->specfr_len] == 's')
		string_solver(storage, arg, NULL);
	else if (storage->format_ptr[storage->specfr_len] == 'd' || \
		storage->format_ptr[storage->specfr_len] == 'i')
		signed_solver(storage, arg);
	else if (storage->format_ptr[storage->specfr_len] == 'u' || \
		storage->format_ptr[storage->specfr_len] == 'p' || \
		storage->format_ptr[storage->specfr_len] == 'o' || \
		storage->format_ptr[storage->specfr_len] == 'x' || \
		storage->format_ptr[storage->specfr_len] == 'X')
		unsigned_solver(storage, arg);
	else if (storage->format_ptr[storage->specfr_len] == 'f' || \
		storage->format_ptr[storage->specfr_len] == 'e' || \
		storage->format_ptr[storage->specfr_len] == 'E' || \
		storage->format_ptr[storage->specfr_len] == 'g' || \
		storage->format_ptr[storage->specfr_len] == 'G')
		float_solver(storage, arg);
}

void	begin_func(t_parse *storage, va_list *arg)
{
	storage->printed = 0;
	storage->string_length = 0;
	while (*storage->format_ptr)
	{
		if (*storage->format_ptr != '%')
		{
			move_to_print(storage, *storage->format_ptr);
			storage->format_ptr++;
			continue ;
		}
		storage->format_ptr++;
		if (parse_specifier(storage, arg))
			start_solution(storage, arg);
	}
	ft_print_end(storage);
}
