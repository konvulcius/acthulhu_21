#include "ft_printf.h"

int		base_power(unsigned long long digit, int base)
{
	int power;

	power = 1;
	while ((digit /= base))
		++power;
	return (power);
}

int		ten_power(long long digit)
{
	int power;

	power = 1;
	while ((digit /= 10))
		++power;
	return (power);
}

char	*ulltoa_base(unsigned long long digit, int base)
{
	char		*string;
	static char	string_box[MAX_LEN_INTEGER];
	int			size;

	size = base_power(digit, base);
	ft_bzero(string_box, MAX_LEN_INTEGER);
	while (size--)
	{
		if (digit % base <= 9)
			string_box[size] = digit % base + 48;
		else
			string_box[size] = digit % base + 87;
		digit /= base;
	}
	string = string_box;
	return (string);
}

char	*lltoa(t_parse *storage, long long digit)
{
	char		*string;
	static char	string_box[MAX_LEN_INTEGER];
	int			size;

	size = ten_power(digit);
	ft_bzero(string_box, MAX_LEN_INTEGER);
	if (digit < 0)
	{
		storage->token = NEGATIVE;
		if (digit == -LL_MAX - 1LL)
			return (ft_strcpy(string_box, "9223372036854775808"));
		digit *= -1;
	}
	while (size--)
	{
		string_box[size] = digit % 10 + 48;
		digit /= 10;
	}
	string = string_box;
	return (string);
}
