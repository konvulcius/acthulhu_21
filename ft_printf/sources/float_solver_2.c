/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_solver_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:30:23 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/23 21:07:02 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_inf_nan(t_parse *storage, t_double *imagine)
{
	char *string;

	string = NULL;
	if (imagine->notion.exp == 32765 && imagine->notion.mant == 0)
		string = "inf";
	else if (imagine->notion.exp == 32765 && imagine->notion.mant != 0)
		string = "nan";
	if (!string)
		return (0);
	while (*string)
		move_to_print(storage, *string++);
	return (1);	
}

// void	handle_f(t_parse *storage, t_float_point *container)
// {

// }

// void	handle_f(t_parse *storage, t_float_point *container)
// {
	
// }

// void	handle_f(t_parse *storage, t_float_point *container)
// {
	
// }

// void	handle_float_precision(t_parse *storage, int start, t_float_point *container)
// {
// 	char	unit[DOUBLE_LEN];

// 	if (storage->precision <= container->exp_2)
// 	{
// 		ft_bzero(unit, DOUBLE_LEN);
// 		unit[DOUBLE_LEN - 1] = 1;
// 		if (container->full_number[storage->precision + start + 1] > 4)
// 			ft_string_sum(container->full_number, unit, storage->precision + start);
// 		if (container->full_number[storage->precision + start] == 9 && \
// 			container->full_number[storage->precision + start - 1] > 4)
// 			ft_string_sum(container->full_number, unit, storage->precision + start);
// 		storage->precision = -1;
// 	}
// }
