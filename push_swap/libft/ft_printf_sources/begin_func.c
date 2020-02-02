/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:04:22 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/27 12:04:23 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		default_parse(t_parse *storage, va_list *arg)
{
	if (!validation(storage))
		return (0);
	flag_cleaner(storage);
	parse_flags(storage, arg);
	return (1);
}

int		parse_specifier(t_parse *storage, va_list *arg)
{
	storage->specfr_len = 0;
	while (storage->format_ptr[storage->specfr_len])
	{
		if (ft_strchr(VALID_SP, storage->format_ptr[storage->specfr_len]))
			return (default_parse(storage, arg));
		storage->specfr_len++;
	}
	return (0);
}

void	start_solution(t_parse *storage, va_list *arg)
{
	if (storage->format_ptr[storage->specfr_len] == '%')
		char_solver(storage, NULL, '%');
	else if (storage->format_ptr[storage->specfr_len] == 'n')
		count_print(storage, arg);
	else if (storage->format_ptr[storage->specfr_len] == 'c')
		char_solver(storage, arg, 0);
	else if (storage->format_ptr[storage->specfr_len] == 's')
		string_solver(storage, arg, NULL);
	else if (ft_tolower(storage->format_ptr[storage->specfr_len]) == 'd' \
		|| storage->format_ptr[storage->specfr_len] == 'i')
		signed_solver(storage, arg);
	else if (storage->format_ptr[storage->specfr_len] == 'u' || \
		storage->format_ptr[storage->specfr_len] == 'p' || \
		storage->format_ptr[storage->specfr_len] == 'o' || \
		ft_tolower(storage->format_ptr[storage->specfr_len]) == 'x')
		unsigned_solver(storage, arg);
	else if (ft_tolower(storage->format_ptr[storage->specfr_len]) == 'f' || \
		ft_tolower(storage->format_ptr[storage->specfr_len]) == 'e' || \
		ft_tolower(storage->format_ptr[storage->specfr_len]) == 'g')
		float_solver(storage, arg);
	storage->format_ptr += ++storage->specfr_len;
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
