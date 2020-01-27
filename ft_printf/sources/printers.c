/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:54:06 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/27 12:22:25 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printer(t_parse *storage)
{
	if (storage->string_length != BUFF_SIZE)
		return ;
	storage->printed += storage->string_length;
	storage->string_length = 0;
	write(1, storage->box, BUFF_SIZE);
}

void	ft_print_end(t_parse *storage)
{
	if (storage->string_length != 0)
		write(1, storage->box, storage->string_length);
	if (storage->printed >= 0)
		storage->printed += storage->string_length;
}

void	move_to_print(t_parse *storage, char elem)
{
	storage->box[storage->string_length] = elem;
	storage->string_length++;
	ft_printer(storage);
}
