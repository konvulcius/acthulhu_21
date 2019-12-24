/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:45:57 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/18 21:44:15 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		validation(t_parse *storage)
{
	char			*valid_flags;
	unsigned int	cur;

	cur = 0;
	valid_flags = VALID_FLAGS;
	while (storage->format_ptr[cur] != storage->format_ptr[storage->specfr_len])
	{
		if (!ft_strchr(valid_flags, storage->format_ptr[cur]))
			return (0);
		cur++;
	}
	return (1);
}

void	parse_flags(t_parse *storage)
{
	char	*temp;

	if (find_between(storage->format_ptr, \
		&storage->format_ptr[storage->specfr_len], '\''))
		storage->flags.quote = 1;
	if (find_between(storage->format_ptr, \
		&storage->format_ptr[storage->specfr_len], '#'))
		storage->flags.hash = 1;
	if (find_between(storage->format_ptr, \
		&storage->format_ptr[storage->specfr_len], '-'))
		storage->flags.image = MINUS;
	else
	{
		temp = find_between(storage->format_ptr, \
		&storage->format_ptr[storage->specfr_len], '0');
		if (temp && *(temp - 1) != '.' && *(temp - 1) < '1')
			storage->flags.image = ZERO;
	}
	if (find_between(storage->format_ptr, \
		&storage->format_ptr[storage->specfr_len], '+'))
		storage->flags.sign = PLUS;
	else if (find_between(storage->format_ptr, \
		&storage->format_ptr[storage->specfr_len], ' '))
		storage->flags.sign = SPACE;
}

void	parse_width_precision(t_parse *storage, va_list *arg)
{
	char	*no_width;
	int		current;
 
	current = 0;
	no_width = " '#+-0";
	while (ft_strchr(no_width, storage->format_ptr[current]))
		current++;
	if (storage->format_ptr[current] == '*')
	{
		storage->width = va_arg(*arg, int);
		if (storage->width < 0)
		{
			storage->flags.image = MINUS;
			storage->width *= -1;
		}
	}
	else
		storage->width = ft_atoi(&storage->format_ptr[current]);
	parse_precision(storage, arg, find_between(storage->format_ptr, \
		&storage->format_ptr[storage->specfr_len], '.'));
}

void	parse_precision(t_parse *storage, va_list *arg, const char *dot)
{
	if (!dot)
		return ;
	if (find_between(dot, &storage->format_ptr[storage->specfr_len], '*'))
		storage->precision = va_arg(*arg, int);
	else
		storage->precision = ft_atoi(++dot);
	if (storage->precision < 0)
		storage->precision *= -1;
}
