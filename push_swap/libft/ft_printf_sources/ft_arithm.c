#include "ft_printf.h"

void	ft_arithm_multiplication(int *box, int pow, int base, \
			t_float_point *container)
{
	int			index;
	int			rest;

	rest = 0;
	while (pow > 0)
	{
		index = BUF_LEN - 1;
		while (index >= BUF_LEN - (container->exp_2 / DIGIT_COUNT + 1) && \
			index >= 0)
		{
			box[index] *= base;
			box[index] += rest;
			if ((rest = box[index] / MAX_DIGIT) > 0)
				box[index] %= MAX_DIGIT;
			index--;
		}
		--pow;
	}
}

void	ft_arithm_division(int *box, int begin, int count)
{
	int		index;
	int		rest;

	while (count > 0)
	{
		index = begin;
		while (index < BUF_LEN)
		{
			rest = box[index] % 2;
			box[index] /= 2;
			box[++index] += rest * MAX_DIGIT;
		}
		--count;
	}
}

void	ft_entire_sum(const int *box2, t_float_point *container, int start)
{
	int		index;
	int		rest;

	index = BUF_LEN - 1;
	while (start >= 0)
	{
		container->full_number[start] += box2[index];
		rest = container->full_number[start] / MAX_DIGIT;
		if (rest > 0)
		{
			container->full_number[start] %= MAX_DIGIT;
			container->full_number[start - 1] += rest;
		}
		--start;
		--index;
	}
}

void	ft_tail_sum(const int *box2, t_float_point *container, int start)
{
	int		index;
	int		rest;

	index = (container->exp_2 - 1) / DIGIT_COUNT;
	while (start >= 0 && index >= 0)
	{
		container->full_number[start] += box2[index];
		rest = container->full_number[start] / MAX_DIGIT;
		if (rest > 0)
		{
			container->full_number[start] %= MAX_DIGIT;
			container->full_number[start - 1] += rest;
		}
		--start;
		--index;
	}
}

int		find_start(int *box)
{
	int		index;

	index = 0;
	while (box[index] == 0)
		++index;
	return (index);
}
