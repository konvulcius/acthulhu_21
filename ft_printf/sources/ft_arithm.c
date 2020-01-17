/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yar <yar@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:46:39 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/30 22:32:16 by yar              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arithm_multiplication(int *box, int pow, int base)
{
	int			index;
	int			rest;

	rest = 0;
	index = BUF_LEN - 1;
	while (index >= BUF_LEN - (pow / DIGIT_COUNT + 1))
	{
		box[index] *= base;
		box[index] += rest;
		if ((rest = box[index] / MAX_DIGIT) > 0)
			box[index] %= MAX_DIGIT;
		index--;
	}
}

void	ft_arithm_division(char *box, int begin)
{
	int		index;
	int		rest;

	index = begin;
	while (index < BUF_LEN)
	{
		rest = box[index] % 2;
		box[index] /= 2;
		box[++index] += rest * MAX_DIGIT;
	}
}

void	ft_string_sum(int *box1, const int *box2, int count)
{
	int		index;
	int		rest;

	index = BUF_LEN - 1;
	while (count >= 0)
	{
		box1[count] += box2[index];
		rest = box1[count] / MAX_DIGIT;
		if (rest > 0)
		{
			if (count != 0)
			{
				box1[count] %= MAX_DIGIT;
				box1[count - 1] += rest;
			}
			else
			{
				box1[count + 1] = box1[count] % MAX_DIGIT;
				box1[count] = rest;
			}
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
