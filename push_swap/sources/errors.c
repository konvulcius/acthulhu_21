/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:39:59 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/31 11:59:33 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stop(void)
{
	exit(0);
}

void	allocation_error(void)
{
	write(2, "Error\n", 6);
	exit(2);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}