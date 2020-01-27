/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:56:25 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/27 12:22:43 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		validation(t_parse *storage)
{
	unsigned int	cur;

	cur = 0;
	while (storage->format_ptr[cur] != storage->format_ptr[storage->specfr_len])
	{
		if (!ft_strchr(VALID_FLAGS, storage->format_ptr[cur]))
			return (0);
		cur++;
	}
	return (1);
}

void	parse_flags(t_parse *storage, va_list *arg)
{
	while (storage->current < storage->specfr_len)
	{
		if (storage->format_ptr[storage->current] == '#')
			storage->flags.hash = 1;
		else if (storage->format_ptr[storage->current] == '-')
			storage->flags.image = MINUS;
		else if (storage->format_ptr[storage->current] == '+')
			storage->flags.sign = PLUS;
		else if (storage->format_ptr[storage->current] == '0')
		{
			if (storage->flags.image != MINUS)
				storage->flags.image = ZERO;
		}
		else if (storage->format_ptr[storage->current] == ' ')
		{
			if (storage->flags.sign != PLUS)
				storage->flags.sign = SPACE;
		}
		else
			parse_width_precision(storage, arg);
		storage->current++;
	}
}

void	parse_width_precision(t_parse *storage, va_list *arg)
{
	while (storage->format_ptr[storage->current] != '.' && \
			storage->current < storage->specfr_len)
	{
		if (storage->format_ptr[storage->current] == '*')
		{
			storage->width = va_arg(*arg, int);
			++storage->current;
		}
		else if (ft_isdigit(storage->format_ptr[storage->current]))
		{
			storage->width = ft_atoi(&storage->format_ptr[storage->current]);
			while (ft_isdigit(storage->format_ptr[storage->current]))
				++storage->current;
		}
		else
			break ;
	}
	if (storage->format_ptr[storage->current] == '.')
		parse_precision(storage, arg);
	else if (storage->width < 0)
	{
		storage->flags.image = MINUS;
		storage->width *= -1;
	}
}

void	parse_precision(t_parse *storage, va_list *arg)
{
	++storage->current;
	if (storage->format_ptr[storage->current] == '*')
	{
		storage->precision = va_arg(*arg, int);
		++storage->current;
	}
	else
	{
		storage->precision = ft_atoi(&storage->format_ptr[storage->current]);
		while (ft_isdigit(storage->format_ptr[storage->current]))
			++storage->current;
	}
	parse_width_precision(storage, arg);
}
