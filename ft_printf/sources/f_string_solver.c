/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_string_solver.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:24:51 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/24 20:47:01 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	f_minus(t_parse *storage, char *string)
{
	handle_sign(storage);
	while (*string)
	{
		if (*string == '.' && !*(string + 1) && !storage->flags.hash)
			break ;
		move_to_print(storage, *string++);
		--storage->width;
	}
	while (storage->precision-- > 0)
	{
		move_to_print(storage, '0');
		--storage->width;
	}
	while (storage->width-- > 0)
		move_to_print(storage, ' ');
}

static void	f_no_minus(t_parse *storage, char *string)
{
	int		len;

	len = (int)ft_strlen(string);
	if (!*(ft_strchr(string, '.') + 1) && !storage->flags.hash)
		len--;
	if (storage->precision > 0)
		len += storage->precision;
	handle_image(storage, len);
	while (*string)
	{
		if (*string == '.' && !*(string + 1) && !storage->flags.hash)
			break ;
		move_to_print(storage, *string++);
	}
	while (storage->precision-- > 0)
		move_to_print(storage, '0');
}

void		f_string_solver(t_parse *storage, char *float_str)
{
	if (storage->flags.image == MINUS)
		f_minus(storage, float_str);
	else
		f_no_minus(storage, float_str);
}
