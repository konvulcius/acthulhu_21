/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:53:59 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/10 14:02:49 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int		main(void)
{
	int ret = 0;
	int a;

	printf("\n\n\n\n\nSome digits\n");
	printf("Max int: %d\n", INT_MAX);
	printf("Min long long: %lld\n", LLONG_MIN);
	printf("byte == %d bits\n", CHAR_BIT);
	printf("Max double: %e\n", DBL_MAX);
	printf("float Min: %e\n", FLT_MIN);
	printf("last string 1.00 diff 1.00 = %e\n", FLT_EPSILON);
	printf("%14d\n", 123);
	printf("%5.2f\n", 1.123);
	printf("%.30f\n", 0.11);
	printf("%#020X\n", 214748);
	printf("%+.20d\n", -214748);
	printf("ads\?\n", a);
	ret = printf("%lc\n", 2);
	printf("%**.*d|", '+', 4, 1, 1);
	return (0);
}
