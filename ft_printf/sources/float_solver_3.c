/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_solver_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yar <yar@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:29:03 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/30 22:32:17 by yar              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_entire(t_double *imagine, t_float_point *container)
{
	char	current_value[MAX_DOUBLE_LEN];

	ft_bzero(current_value, MAX_DOUBLE_LEN);
	current_value[MAX_DOUBLE_LEN - 1] = 1;
	container->exp_10 = ft_arithm_multiplication(current_value, \
		container->exp_2, container->exp_2, 2);
	ft_string_sum(container->full_number, current_value, container->exp_10);
	container->last_exp = container->exp_2;
	printf("%d\n", BUF_LEN)
;	while (container->exp_2 > 0 && imagine->notion.mant)
	{
		--container->exp_2;
		if (!(imagine->notion.mant >> 63))
		{
			imagine->notion.mant = imagine->notion.mant << 1;
			continue ;
		}
		ft_arithm_division(current_value, MAX_DOUBLE_LEN - container->exp_10, \
			container->last_exp - container->exp_2);
		container->last_exp = container->exp_2;
		imagine->notion.mant = imagine->notion.mant << 1;
		ft_string_sum(container->full_number, current_value, container->exp_10);
	}
	--container->exp_2;
}

void	handle_small_tail(t_double *imagine, t_float_point *container)
{
	char	current_value[MAX_DOUBLE_LEN];

	container->exp_2 *= -1;
	ft_bzero(current_value, MAX_DOUBLE_LEN);
	current_value[MAX_DOUBLE_LEN - 1] = 1;
	container->last_exp = 0;
	while (imagine->notion.mant)
	{
		if (!(imagine->notion.mant >> 63))
		{
			imagine->notion.mant = imagine->notion.mant << 1;
			++container->exp_2;
			continue ;
		}
		ft_arithm_multiplication(current_value, \
			container->exp_2 - container->last_exp, container->exp_2, 5);
		ft_string_sum(container->full_number, current_value, \
			container->exp_10 + container->exp_2);
		container->last_exp = container->exp_2;
		imagine->notion.mant = imagine->notion.mant << 1;
		++container->exp_2;
	}
}

void	handle_large_tail(t_double *imagine, t_float_point *container)
{
	char	current_value[MAX_DOUBLE_LEN];

	container->exp_2 *= -1;
	ft_bzero(current_value, MAX_DOUBLE_LEN);
	current_value[MAX_DOUBLE_LEN - 1] = 1;
	ft_arithm_multiplication(current_value, container->exp_2, container->exp_2, 5);
	ft_string_sum(container->full_number, current_value, container->exp_2);
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
		ft_arithm_multiplication(current_value, \
			container->exp_2 - container->last_exp, container->exp_2, 5);
		ft_string_sum(container->full_number, current_value, \
			container->exp_10 + container->exp_2);
		container->last_exp = container->exp_2;
	}
}
