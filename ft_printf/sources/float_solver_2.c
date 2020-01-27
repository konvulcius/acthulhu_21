/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_solver_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:06:45 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/27 12:07:01 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	find_int_exp10(t_float_point *container)
{
	int		index;

	index = 0;
	if (container->full_number[index] == 0)
		++index;
	while (index <= container->index)
	{
		if (index > 1 || (index == 1 && container->full_number[0] > 0))
			container->exp_10 += DIGIT_COUNT;
		else
			container->exp_10 += ten_power(container->full_number[index]) - 1;
		++index;
	}
}

static void	find_float_exp10(t_float_point *container)
{
	int		index;

	index = 0;
	while (container->full_number[index] == 0 && ++index < BUF_LEN)
		container->exp_10 -= DIGIT_COUNT;
	if (index != BUF_LEN)
	{
		container->exp_10 -= DIGIT_COUNT - \
			ten_power(container->full_number[index]) + 1;
	}
}

void		handle_entire(t_double *imagine, t_float_point *container)
{
	int		current_value[BUF_LEN];

	ft_bzero(current_value, BUF_LEN * sizeof(int));
	current_value[BUF_LEN - 1] = 1;
	ft_arithm_multiplication(current_value, container->exp_2, 2, container);
	container->index = BUF_LEN - find_start(current_value);
	ft_entire_sum(current_value, container, container->index);
	container->last_exp = container->exp_2;
	while (container->exp_2 > 0 && imagine->notion.mant)
	{
		--container->exp_2;
		if (!(imagine->notion.mant >> 63))
		{
			imagine->notion.mant = imagine->notion.mant << 1;
			continue ;
		}
		ft_arithm_division(current_value, BUF_LEN - container->index, \
			container->last_exp - container->exp_2);
		container->last_exp = container->exp_2;
		imagine->notion.mant = imagine->notion.mant << 1;
		ft_entire_sum(current_value, container, container->index);
	}
	--container->exp_2;
	find_int_exp10(container);
}

void		handle_small_tail(t_double *imagine, t_float_point *container)
{
	int		current_value[BUF_LEN];

	container->exp_2 *= -1;
	ft_bzero(current_value, BUF_LEN);
	current_value[0] = MAX_DIGIT;
	container->last_exp = 0;
	while (imagine->notion.mant)
	{
		if (!(imagine->notion.mant >> 63))
		{
			imagine->notion.mant = imagine->notion.mant << 1;
			++container->exp_2;
			continue ;
		}
		ft_arithm_division(current_value, 0, \
			container->exp_2 - container->last_exp);
		ft_tail_sum(current_value, container, \
			container->index + ((container->exp_2 - 1) / DIGIT_COUNT) + 1);
		container->last_exp = container->exp_2;
		imagine->notion.mant = imagine->notion.mant << 1;
		++container->exp_2;
	}
}

void		handle_large_tail(t_double *imagine, t_float_point *container)
{
	int		current_value[BUF_LEN];

	container->index = -1;
	container->exp_2 *= -1;
	ft_bzero(current_value, BUF_LEN * sizeof(int));
	current_value[0] = MAX_DIGIT;
	ft_arithm_division(current_value, 0, container->exp_2);
	ft_tail_sum(current_value, container, (container->exp_2 - 1) / DIGIT_COUNT);
	container->last_exp = container->exp_2;
	while (imagine->notion.mant)
	{
		++container->exp_2;
		if (!(imagine->notion.mant >> 63))
		{
			imagine->notion.mant = imagine->notion.mant << 1;
			continue ;
		}
		imagine->notion.mant = imagine->notion.mant << 1;
		ft_arithm_division(current_value, 0, \
			container->exp_2 - container->last_exp);
		ft_tail_sum(current_value, container, \
			(container->exp_2 - 1) / DIGIT_COUNT);
		container->last_exp = container->exp_2;
	}
	find_float_exp10(container);
}
