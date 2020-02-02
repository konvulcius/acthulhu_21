/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signed_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:50:57 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/24 20:51:01 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_minus(t_parse *storage, char *string)
{
	handle_sign(storage);
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
	handle_image(storage, len);
	while (len-- > 0)
		move_to_print(storage, *string++);
}

void	signed_string_solver(t_parse *storage, char *digit)
{
	if (storage->flags.image == MINUS)
		int_minus(storage, digit);
	else
		int_no_minus(storage, digit);
}
