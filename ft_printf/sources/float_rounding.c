#include "ft_printf.h"

static void	rounding(char *string, int i)
{
	int		rest;

	rest = 1;
	while (--i >= 0 && rest == 1 && string[i] != '.')
	{
		if (rest == 1)
			string[i] += 1;
		rest = (string[i] - 48) / 10;
		string[i] = (string[i] - 48) % 10 + 48;
	}
	if (string[i] == '.' && rest == 1)
		rounding(string, i);
}

static void	zero_clean(char *string, int i)
{
	while (--i >= 0 && string[i] == '0')
		string[i] = '\0';
}

void		handle_rounding(t_parse *storage, char *string)
{
	int		i;

	i = (int)ft_strlen(string) - 1;
	if (string[i] - 48 > 4)
		rounding(string, i);
	if (ft_isdigit(string[i]))
		string[i] = '\0';
	if (ft_tolower(storage->format_ptr[storage->specfr_len]) == 'g')
		zero_clean(string, i);
}
