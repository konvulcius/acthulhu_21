/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 20:51:11 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/19 14:17:19 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static unsigned char 		uch_pos_1 = 100;
static unsigned short		ush_pos_1 = 3047;
static unsigned int			ui_pos_1 = 878023;
static unsigned long		ul_pos_1 = 22337203685477;

int	main(void)
{
	int		a = 123;
	unsigned long long b = 8809040871136690176;
	long double f = 123.123123123;
	
	printf("%.40f\n", 2.9999);
	ft_printf("%f\n", 2.9999);
	return (0);
}
