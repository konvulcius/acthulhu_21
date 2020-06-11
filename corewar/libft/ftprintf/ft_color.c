#include "ft_printf.h"
#include "libft.h"

char *g_colors[] = {
	"red", "\e[31m",
	"green", "\e[32m",
	"yellow", "\e[33m",
	"blue", "\e[34m",
	"magenta", "\e[35m",
	"cyan", "\e[36m",
	"eoc", "\e[0m",
	NULL
};

static int		ft_is_color(char **s)
{
	char	color[10];
	char	*temp;
	int		i;

	ft_bzero(color, 10);
	temp = *s + 1;
	i = 0;
	while (i < 9)
	{
		if (*temp && *temp != '}')
			color[i++] = *(temp++);
		else
			break ;
	}
	i = 0;
	while (g_colors[i] != NULL)
	{
		if (!ft_strcmp(color, g_colors[i++]))
		{
			*s = temp;
			return (i);
		}
	}
	--*s;
	return (0);
}

void			ft_color_input(char **s, char **buff)
{
	char	*temp;
	int		index;

	index = ft_is_color(s);
	if (index > 0)
	{
		temp = g_colors[index];
		while (*temp)
			*((*buff)++) = *(temp++);
	}
}
