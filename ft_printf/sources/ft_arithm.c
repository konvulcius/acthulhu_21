/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:46:39 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/23 22:23:47 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_arithm_multiplication(char *box, int amount, int pow, int base)
{
	int			index;
	int			rest;

	rest = 0;
	while (amount--)
	{
		index = DOUBLE_LEN - 1;
		while (index >= DOUBLE_LEN - pow)
		{
			box[index] *= base;
			box[index] += rest;
			if ((rest = box[index] / 10) > 0)
				box[index] %= 10;
			index--;
		}
	}
	++index;
	if (base == 2)
		index = find_start(box);
	return (DOUBLE_LEN - index);
}

void	ft_arithm_division(char *box, int begin, int count)
{
	int		index;
	int		rest;

	while (count--)
	{
		index = begin;
		while (index < DOUBLE_LEN)
		{
			rest = box[index] % 2;
			box[index] /= 2;
			box[++index] += rest * 10;
		}
	}
}

void	ft_string_sum(char *box1, const char *box2, int count)
{
	int		index;
	int		rest;

	index = DOUBLE_LEN - 1;
	while (count >= 0)
	{
		box1[count] += box2[index];
		rest = box1[count] / 10;
		if (rest > 0)
		{
			box1[count] %= 10;
			box1[count - 1] += rest;
		}
		--count;
		--index;
	}
}

int		find_start(char *box)
{
	int		index;

	index = 0;
	while (box[index] == 0)
		++index;
	return (index);
}
