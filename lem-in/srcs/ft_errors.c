/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:47:14 by acthulhu          #+#    #+#             */
/*   Updated: 2020/04/21 14:47:14 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	ft_allocation_error(void)
{
	write(2, "Memory is over\n", 15);
	exit(1);
}

void	ft_error_here(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}
