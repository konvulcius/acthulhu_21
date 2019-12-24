/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_between.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:38:38 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/13 23:53:26 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*find_between(const char *s1, const char *s2, int c)
{
	unsigned char	ch;

	if (!s1 || !s2)
		return (NULL);
	ch = c;
	if (s1 <= s2)
	{
		while (s1 <= s2)
		{
			if (*s1 == ch)
				return ((char*)s1);
			s1++;
		}
		return (NULL);
	}
	else
	{
		while (s1 > s2)
		{
			if (*s1 == ch)
				return ((char*)s1);
			s1--;
		}
		return (NULL);
	}
}
