/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 01:21:49 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/19 12:01:02 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_sign_precision(t_parse *storage, t_double *imagine)
{
	if (imagine->notion.sign == 1)
		storage->token = NEGATIVE;
	if (storage->precision > -1)
		return ;
	if (storage->format_ptr[storage->specfr_len] == 'f' || \
		ft_tolower(storage->format_ptr[storage->specfr_len]) == 'e')
		storage->precision = 6;
}

void	float_handler(t_parse *storage, t_double *imagine)
{
	t_float_point	container;

	ft_bzero(container.full_number, BUF_LEN * sizeof(int));
	container.exp_10 = 0;
	container.exp_2 = imagine->notion.exp - 16383;
	if (container.exp_2 < 0)
		handle_large_tail(imagine, &container);
	else if (container.exp_2 >= 0)
	{
		handle_entire(imagine, &container);
		handle_small_tail(imagine, &container);
	}
	for (int i = 0; i < 10; i++)
	{
		ft_putnbr(container.full_number[i]);
	}
	// if (storage->format_ptr[storage->specfr_len] == 'f')
	// 	handle_f(storage, &container);
	// else if (ft_toupper(storage->format_ptr[storage->specfr_len]) == 'e')
	// 	handle_e(storage, &container);
	// else if (ft_toupper(storage->format_ptr[storage->specfr_len]) == 'g')
	// 	handle_g(storage, &container);
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
	storage->format_ptr += ++storage->specfr_len;
}
