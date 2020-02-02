/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:15:35 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/26 11:15:37 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*pointer_to_s1;

	pointer_to_s1 = ft_strchr(s1, '\0');
	ft_strcpy(pointer_to_s1, s2);
	return (s1);
}
