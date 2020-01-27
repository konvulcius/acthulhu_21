/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_e.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:06:20 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/27 12:06:21 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_e_string(t_parse *storage, \
				t_float_point *container, char *string, t_values *index)
{
	int		count;

	string[index->i++] = '0';
	while (container->full_number[index->j] == 0 && index->j < BUF_LEN - 2)
		index->j++;
	count = MAX_DIGIT / 10;
	while (count > 1 && container->full_number[index->j] % count == \
			container->full_number[index->j])
		count /= 10;
	string[index->i++] = container->full_number[index->j] / count + 48;
	container->full_number[index->j] %= count;
	string[index->i++] = '.';
	while (index->j < BUF_LEN)
	{
		while (count > 1 && storage->precision-- >= 0)
		{
			count /= 10;
			string[index->i++] = container->full_number[index->j] / count + 48;
			container->full_number[index->j] %= count;
		}
		if (storage->precision < 0)
			return ;
		count = MAX_DIGIT;
		index->j++;
	}
}

static void	put_exp_in_string(char *string, int exp)
{
	long long	value;
	int			count;

	value = exp;
	if (value < 0)
		value *= -1;
	count = MAX_DIGIT;
	while (count > 1 && value % count == value)
		count /= 10;
	while (count > 0)
	{
		*string++ = value / count + 48;
		value %= count;
		count /= 10;
	}
}

static void	handle_exponent(t_parse *storage, t_float_point *container, \
				char *string)
{
	int		i;

	i = ft_strlen(string);
	if (string[0] != '0')
	{
		container->exp_10++;
		string[2] = string[1];
		string[1] = '.';
		string[--i] = '\0';
	}
	if (storage->format_ptr[storage->specfr_len] < 'e')
		string[i++] = 'E';
	else
		string[i++] = 'e';
	if (container->exp_10 >= 0)
		string[i++] = '+';
	else
		string[i++] = '-';
	if (container->exp_10 / 10 == 0)
		string[i++] = '0';
	put_exp_in_string(&string[i], container->exp_10);
}

void		handle_e(t_parse *storage, t_float_point *container)
{
	char		string_e[MAX_DOUBLE_LEN];
	t_values	index;

	ft_bzero(string_e, MAX_DOUBLE_LEN);
	index.i = 0;
	index.j = 0;
	if (container->full_number[index.j] == 0 && container->exp_10 >= 0)
		++index.j;
	handle_e_string(storage, container, string_e, &index);
	handle_rounding(storage, string_e);
	handle_exponent(storage, container, string_e);
	if (string_e[0] == '0')
		e_string_solver(storage, string_e + 1);
	else
		e_string_solver(storage, string_e);
}
