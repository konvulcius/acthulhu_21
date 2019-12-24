/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:32:52 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/21 00:13:50 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hex_to_i(const char *str)
{
	unsigned long long	value;
	int					minus;

	minus = 1;
	value = 0;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isalnum(*str))
	{
		if (ft_isdigit(*str))
			value = value * 16 + (*str - 48);
		if (ft_isalpha(*str))
			value = value * 16 + (ft_tolower(*str) - 87);
		str++;
	}
	if (value > MAX_LL && minus > 0)
		return (-1);
	if (value > MAX_LL && minus < 0)
		return (0);
	return (value * minus);
}

void	handle_hash(t_parse *storage, char *string)
{
	if (storage->flags.hash != 1 || \
	(ft_tolower(storage->format_ptr[storage->specfr_len]) == 'x' \
	&& !ft_hex_to_i(string)))
		return ;
	move_to_print(storage, '0');
	if (storage->format_ptr[storage->specfr_len] == 'X')
		move_to_print(storage, 'X');
	else if (storage->format_ptr[storage->specfr_len] != 'o')
		move_to_print(storage, 'x');
}

void	uint_minus(t_parse *storage, char *string)
{
	if (storage->format_ptr[storage->specfr_len] != 'u')
		handle_hash(storage, string);
	while (*string)
	{
		move_to_print(storage, *string++);
		--storage->width;
	}
	while (storage->width-- > 0)
		move_to_print(storage, ' ');
}

void	uint_no_minus(t_parse *storage, char *string)
{
	int		len;

	len = (int)ft_strlen(string);
	if (storage->flags.image == ZERO)
	{
		if (storage->format_ptr[storage->specfr_len] != 'u')
			handle_hash(storage, string);
		while (storage->width-- > len)
			move_to_print(storage, '0');
		while (len-- > 0)
			move_to_print(storage, *string++);
	}
	else
	{
		while (storage->width-- > len)
			move_to_print(storage, ' ');
		if (storage->format_ptr[storage->specfr_len] != 'u')
			handle_hash(storage, string);
		while (len-- > 0)
			move_to_print(storage, *string++);
	}
}

void	unsigned_string_solver(t_parse *storage, char *unsigned_digit)
{
	if (storage->flags.image == MINUS)
		uint_minus(storage, unsigned_digit);
	else
		uint_no_minus(storage, unsigned_digit);
	storage->format_ptr += ++storage->specfr_len;
}