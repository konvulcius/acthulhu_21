/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:36:53 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/20 22:31:34 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handling_digit_precision(t_parse *storage, char **string)
{
	char	*temp;
	int		length;
	int		index;

	if (storage->precision == -1)
		return ;
	if (storage->flags.image == ZERO)
		storage->flags.image = NOTHING;
	if (storage->precision == 0 && !ft_strcmp(*string, "0"))
		*string[0] = '\0';
	length = (int)ft_strlen(*string);
	if (length < storage->precision)
	{
		index = 0;
		temp = ft_strnew(storage->precision);
		while (storage->precision > length++)
			temp[index++] = '0';
		ft_strcpy(&temp[index], *string);
		ft_strdel(string);
		*string = temp;
	}
}
