/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:22:04 by croxane           #+#    #+#             */
/*   Updated: 2020/05/30 11:01:24 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dis_asm.h"

char			*ft_quotes(char *str)
{
	int			i;
	char		*new;

	new = ft_strnew(ft_strlen(str) + 2);
	i = 0;
	new[0] = 34;
	while (str[i])
	{
		new[i + 1] = str[i];
		i++;
	}
	new[i + 1] = 34;
	free(str);
	return (new);
}

char			*file_name(char *str)
{
	char		*name;

	name = ft_strnew(ft_strlen(str) - 2);
	ft_strncpy(name, str, ft_strlen(str) - 3);
	name[ft_strlen(name)] = 's';
	return (name);
}

int				main(int argc, char **argv)
{
	t_struct	data;

	if (argc != 2)
	{
		write(1, "Usage: <dis_asm> <player.cor>\n", 30);
		return (0);
	}
	if (ft_strlen(argv[1]) < 4)
		return (0);
	data.file_name = file_name(argv[1]);
	ft_opening(argv[1], &data);
	return (0);
}
