#include "dis_asm.h"

void		ft_args_type(char *str, t_instr *data)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (i < data->type->count_args * 2)
	{
		if (str[i] == '1' && str[i + 1] == '0')
			data->args[++j] = 1;
		else if (str[i] == '0' && str[i + 1] == '1')
			data->args[++j] = 2;
		else if (str[i] == '1' && str[i + 1] == '1')
			data->args[++j] = 3;
		i += 2;
	}
}

char		*invert(char *str, int i)
{
	char	*new;
	int		j;

	j = 0;
	new = ft_strnew(i);
	i--;
	while (i > -1)
	{
		new[j] = str[i];
		j++;
		i--;
	}
	return (new);
}
