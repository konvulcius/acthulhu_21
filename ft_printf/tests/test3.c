#include "ft_printf.h"
#include <stdio.h>
#include <float.h>

int		main(void)
{
	int a;
	long double b = __LDBL_MIN__;

	printf("%f\n", 123.5);
	printf("%f", 123.5);
	return (0);
}