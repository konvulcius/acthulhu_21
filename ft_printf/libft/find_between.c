/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_between.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:15:09 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/26 11:15:10 by acthulhu         ###   ########.fr       */
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
