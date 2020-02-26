#include "ft_printf.h"

void	handling_digit_precision(t_parse *storage, char *string, \
			void (*f)(t_parse *, char *))
{
	char	*temp;
	int		length;
	int		index;

	if (storage->precision >= 0 && storage->flags.image == ZERO)
		storage->flags.image = NOTHING;
	if (storage->precision == 0 && !ft_strcmp(string, "0"))
		string[0] = '\0';
	length = (int)ft_strlen(string);
	if (length < storage->precision)
	{
		index = 0;
		if (!(temp = ft_strnew(storage->precision)))
			error();
		while (storage->precision > length++)
			temp[index++] = '0';
		ft_strcpy(&temp[index], string);
		f(storage, temp);
		ft_strdel(&temp);
	}
	else
		f(storage, string);
}
