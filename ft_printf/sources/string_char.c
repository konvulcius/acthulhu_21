/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:15:04 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/25 10:15:06 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_minus(t_parse *storage, char *string, char *elem)
{
	int		len;
	int		index;

	len = (int)ft_strlen(string);
	index = 0;
	if (elem && !*elem)
		len++;
	while (index < len && (index < storage->precision || \
		storage->precision == -1))
		move_to_print(storage, string[index++]);
	while (index++ < storage->width)
		move_to_print(storage, ' ');
}

void	no_minus(t_parse *storage, char *string, char *elem)
{
	char	image;
	int		len;

	len = (int)ft_strlen(string);
	if (len > storage->precision && storage->precision > -1)
		len = storage->precision;
	if (elem && !*elem)
		len++;
	if (storage->flags.image == ZERO)
		image = '0';
	else
		image = ' ';
	while (storage->width-- > len)
		move_to_print(storage, image);
	while (len-- > 0)
		move_to_print(storage, *string++);
}

void	string_solver(t_parse *storage, va_list *arg, char *elem)
{
	char	*string;

	if (arg != NULL)
		string = va_arg(*arg, char*);
	else
		string = elem;
	if (!string)
		string = "(null)";
	if (storage->flags.image == MINUS)
		if_minus(storage, string, elem);
	else
		no_minus(storage, string, elem);
}

void	char_solver(t_parse *storage, va_list *arg, char percent)
{
	char	for_print[2];
	char	elem;

	if (arg != NULL)
		elem = (char)va_arg(*arg, int);
	else
		elem = percent;
	storage->precision = -1;
	for_print[0] = elem;
	for_print[1] = '\0';
	string_solver(storage, NULL, for_print);
}
