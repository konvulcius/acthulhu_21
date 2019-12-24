/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:02:04 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/13 22:52:49 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		any(char *line, ...)
{
	va_list ap;
	long long a, b, c, d;
	char *str;
	float qw;

	va_start(ap, line);
	a = va_arg(ap, long long);
	str = va_arg(ap, char*);
	b = va_arg(ap, long long);
	c = va_arg(ap, long long);
	qw = va_arg(ap, double);
	d = va_arg(ap, long long);
	
	write(1, "%", 1);
	printf("%+x|\n", -123);
	a = printf("%04294967303d|\n", 12313);
	printf("%lld\n", a);
	
	return (printf("%s\n%d\n%s\n%c\n%d\n%f\n%d", line, a, str, b, c, qw, d));
}

int		main(void)
{
	float qwe = 3131231;
	char	b = 'c';
	char	*c = "123456";
	int		i = 6;
	//any("Hello", 12, "123123", b, 143, qwe, 12);
	while (i-- > 0)
		printf("%c", *c++);
	return (0);
}
