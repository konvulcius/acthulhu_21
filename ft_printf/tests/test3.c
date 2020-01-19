#include "ft_printf.h"
#include <stdio.h>
#include <float.h>

// int		main(void)
// {
// 	int a;
// 	long double b = __LDBL_MIN__;
// 	long double n = 2.3432423;

// 	printf("%f\n", 123.5);
// 	printf("%f\n", 123.5);
// 	printf("-f: [%.Lf]\n", n);
// 	return (0);
// }

int main(void)
{
	t_float_point container;

	container.index = 2;
	container.exp_10 = 0;
	container.full_number[0] = 3;
	container.full_number[1] = 322225;
	find_exp10(&container);
	printf("%d\n", container.exp_10);
	return (0);
}