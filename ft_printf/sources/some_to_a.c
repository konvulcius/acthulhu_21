/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:28:43 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/23 15:27:45 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		base_power(unsigned long long digit, int base)
{
	int power;

	power = 1;
	while ((digit /= base))
		++power;
	return (power);
}

int		ten_power(long long digit)
{
	int power;

	power = 1;
	while ((digit /= 10))
		++power;
	return (power);
}

char	*ulltoa_base(unsigned long long  digit, int base)
{
	char		*string;
	int			size;

	size = base_power(digit, base);
	if (!(string = ft_strnew(size)))
		bad_alloc();
	while (size--)
	{
		if (digit % base <= 9)
			string[size] = digit % base + 48;
		else
			string[size] = digit % base + 87;
		digit /= base;
	}
	return (string);
}

char	*lltoa(t_parse *storage, long long  digit)
{
	char		*string;
	int			size;

	size = ten_power(digit);
	if (!(string = ft_strnew(size)))
		bad_alloc();
	if (digit < 0)
	{
		storage->token = NEGATIVE;
		if (digit == LLONG_MIN)
			return (ft_strcpy(string, "9223372036854775808"));
		digit *= -1;
	}
	while (size--)
	{
		string[size] = digit % 10 + 48;
		digit /= 10;
	}
	return (string);
}