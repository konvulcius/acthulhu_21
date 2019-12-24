/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:55:41 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/13 14:05:20 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	error(t_parse *storage)
{
	storage->printed = -1;
	storage->format_ptr = ft_strrchr(storage->format_ptr, '\0');
}

void	bad_alloc(void)
{
	write(1, "Error\n", 6);
	exit(11);
}