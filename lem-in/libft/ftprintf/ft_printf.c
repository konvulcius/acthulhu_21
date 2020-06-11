/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <marvin@fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:45:04 by lliza             #+#    #+#             */
/*   Updated: 2020/04/04 00:46:00 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

static void		ft_bzero_data(t_data *data_ptr)
{
	data_ptr->flags = 0;
	data_ptr->type = 0;
	data_ptr->width = 0;
	data_ptr->precision = 0;
}

static void		ft_handle_input(char *s, t_data *data_ptr, char **buff_ptr)
{
	while (*s)
	{
		if (*s == '%')
		{
			++s;
			if (*s)
			{
				ft_handle_specs(&s, data_ptr, buff_ptr);
				if (*s)
					++s;
				ft_bzero_data(data_ptr);
				continue ;
			}
			else
				break ;
		}
		else
			*((*buff_ptr)++) = *s++;
	}
}

int				ft_printf(const char *s, ...)
{
	char			*buff;
	t_data			data;
	char			*buff_ptr;
	int				r;

	if (!(buff = (char *)malloc(sizeof(char) * 10000)))
		return (0);
	ft_bzero(buff, 10000);
	buff_ptr = buff;
	ft_bzero_data(&data);
	if (s && *s)
	{
		data.fd = 1;
		va_start(data.args, s);
		ft_handle_input((char *)s, &data, &buff_ptr);
		va_end(data.args);
	}
	if (data.fd > 0)
		write(data.fd, buff, buff_ptr - buff);
	else
		write(1, buff, buff_ptr - buff);
	r = buff_ptr - buff;
	free(buff);
	return (r);
}
