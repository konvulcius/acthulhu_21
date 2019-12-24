/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:50:09 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/18 16:54:06 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_cleaner(t_parse *storage)
{
	storage->width = 0;
	storage->precision = -1;
	storage->flags.hash = 0;
	storage->flags.quote = 0;
	storage->token = POSITIVE;
	storage->flags.image = NOTHING;
	storage->flags.sign = EMPTY;
}
