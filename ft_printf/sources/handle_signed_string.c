/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signed_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 19:26:16 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/23 19:27:10 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_minus(t_parse *storage, char *string)
{
	if (storage->token == NEGATIVE)
		move_to_print(storage, storage->token);
	else if (storage->flags.sign != EMPTY)
		move_to_print(storage, storage->flags.sign);
	while (*string)
	{
		move_to_print(storage, *string++);
		--storage->width;
	}
	while (storage->width-- > 0)
		move_to_print(storage, ' ');
}

void	int_no_minus(t_parse *storage, char *string)
{
	int		len;

	len = (int)ft_strlen(string);
	if (storage->flags.image == ZERO)
	{
		if (storage->token == NEGATIVE)
			move_to_print(storage, storage->token);
		else if (storage->flags.sign != EMPTY)
			move_to_print(storage, storage->flags.sign);
		while (storage->width-- > len)
			move_to_print(storage, '0');
		while (len-- > 0)
			move_to_print(storage, *string++);
	}
	else
	{
		while (storage->width-- > len)
			move_to_print(storage, ' ');
		if (storage->token == NEGATIVE)
			move_to_print(storage, storage->token);
		else if (storage->flags.sign != EMPTY)
			move_to_print(storage, storage->flags.sign);
		while (len-- > 0)
			move_to_print(storage, *string++);
	}
}

void	signed_string_solver(t_parse *storage, char *digit)
{
	if (storage->token == NEGATIVE || storage->flags.sign != EMPTY)
		--storage->width;
	if (storage->flags.image == MINUS)
		int_minus(storage, digit);
	else
		int_no_minus(storage, digit);
	storage->format_ptr += ++storage->specfr_len;
}