/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 01:21:49 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/23 22:23:47 by acthulhu         ###   ########.fr       */
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

	ft_bzero(container.full_number, DOUBLE_LEN);
	container.exp_10 = 0;
	container.exp_2 = imagine->notion.exp - 16383;
	if (container.exp_2 < 0)
	{
		handle_tail(imagine, &container);
		if (container.exp_10 == 0)
			container.exp_10 = find_start(container.full_number) * -1;
	}
	if (container.exp_2 >= 0)
	{
		handle_entire(imagine, &container);
		handle_tail(imagine, &container);
	}
	for (int i = 0; i < 40; i++)
	{
		move_to_print(storage, container.full_number[i] + 48);
	}
	// if (storage->format_ptr[storage->specfr_len] == 'f')
	// 	handle_f(storage, &container);
	// else if (ft_toupper(storage->format_ptr[storage->specfr_len]) == 'e')
	// 	handle_e(storage, &container);
	// else if (ft_toupper(storage->format_ptr[storage->specfr_len]) == 'g')
	// 	handle_g(storage, &container);
}

void	handle_entire(t_double *imagine, t_float_point *container)
{
	char	current_value[DOUBLE_LEN];

	ft_bzero(current_value, DOUBLE_LEN);
	current_value[DOUBLE_LEN - 1] = 1;
	container->exp_10 = ft_arithm_multiplication(current_value, \
		container->exp_2, container->exp_2, 2);
	ft_string_sum(container->full_number, current_value, container->exp_10);
	container->last_exp = container->exp_2;
	while (container->exp_2 >= 0 && imagine->notion.mant)
	{
		--container->exp_2;
		if (!(imagine->notion.mant >> 63))
		{
			imagine->notion.mant = imagine->notion.mant << 1;
			continue ;
		}
		ft_arithm_division(current_value, DOUBLE_LEN - container->exp_10, \
			container->last_exp - container->exp_2);
		container->last_exp = container->exp_2;
		imagine->notion.mant = imagine->notion.mant << 1;
		ft_string_sum(container->full_number, current_value, container->exp_10);
	}
}

void	handle_tail(t_double *imagine, t_float_point *container)
{
	char	current_value[DOUBLE_LEN];

	container->exp_2 *= -1;
	ft_bzero(current_value, DOUBLE_LEN);
	current_value[DOUBLE_LEN - 1] = 1;
	// ft_arithm_multiplication(current_value, container->exp_2, container->exp_2, 5);
	// ft_string_sum(container->full_number, current_value, container->exp_2);
	// container->last_exp = container->exp_2;
	while (imagine->notion.mant)
	{
		//++container->exp_2;
		if (!(imagine->notion.mant >> 63))
		{
			imagine->notion.mant = imagine->notion.mant << 1;
			++container->exp_2;
			continue ;
		}
		ft_arithm_multiplication(current_value, \
			container->exp_2 - container->last_exp, container->exp_2, 5);
		container->last_exp = container->exp_2;
		imagine->notion.mant = imagine->notion.mant << 1;
		++container->exp_2;
		ft_string_sum(container->full_number, current_value, \
			container->exp_10 + container->exp_2);
	}
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