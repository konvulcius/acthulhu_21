/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtory <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:36:17 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/27 12:20:56 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_cleaner(t_parse *storage)
{
	storage->current = 0;
	storage->width = 0;
	storage->precision = -1;
	storage->flags.hash = 0;
	storage->token = POSITIVE;
	storage->flags.image = NOTHING;
	storage->flags.sign = EMPTY;
}
