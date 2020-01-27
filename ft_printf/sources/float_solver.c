/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:05:23 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/27 12:05:55 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_inf_nan(t_parse *storage, t_double *imagine)
{
	char	*string;

	string = NULL;
	if (imagine->notion.exp == 32767 && imagine->notion.mant << 1 == 0)
		string = "inf";
	else if (imagine->notion.exp == 32767 && imagine->notion.mant != 0)
	{
		string = "nan";
		storage->token = POSITIVE;
		storage->flags.sign = EMPTY;
	}
	if (!string)
		return (0);
	if (storage->flags.image == ZERO)
		storage->flags.image = NOTHING;
	signed_string_solver(storage, string);
	return (1);
}

void	parse_sign_precision(t_parse *storage, t_double *imagine)
{
	if (imagine->notion.sign == 1)
		storage->token = NEGATIVE;
	if (storage->precision > -1)
		return ;
	storage->precision = 6;
}

void	float_handler(t_parse *storage, t_double *imagine)
{
	t_float_point	container;

	ft_bzero(container.full_number, sizeof(int) * BUF_LEN);
	container.index = 0;
	container.exp_10 = 0;
	container.exp_2 = imagine->notion.exp - 16383;
	imagine->notion.mant = imagine->notion.mant << 1;
	if (imagine->notion.exp != 0 && container.exp_2 < 0)
		handle_large_tail(imagine, &container);
	else if (container.exp_2 >= 0)
	{
		handle_entire(imagine, &container);
		handle_small_tail(imagine, &container);
	}
	if (ft_tolower(storage->format_ptr[storage->specfr_len]) == 'f')
		handle_f(storage, &container);
	else if (ft_tolower(storage->format_ptr[storage->specfr_len]) == 'e')
		handle_e(storage, &container);
	else if (ft_tolower(storage->format_ptr[storage->specfr_len]) == 'g')
		handle_g(storage, &container);
}

void	float_solver(t_parse *storage, va_list *arg)
{
	t_double	imagine;

	if (storage->format_ptr[storage->specfr_len - 1] == 'L')
		imagine.value = va_arg(*arg, long double);
	else
		imagine.value = va_arg(*arg, double);
	parse_sign_precision(storage, &imagine);
	if (!handle_inf_nan(storage, &imagine))
		float_handler(storage, &imagine);
}
