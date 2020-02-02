/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:08:06 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/29 11:44:01 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				counter;
	unsigned char		*object;
	unsigned char const	*source;

	if (!(dest || src))
		return (0);
	counter = -1;
	object = dest;
	source = src;
	while (++counter < n)
		object[counter] = source[counter];
	return (object);
}
