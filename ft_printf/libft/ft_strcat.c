/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:35:01 by acthulhu          #+#    #+#             */
/*   Updated: 2019/12/16 13:17:10 by acthulhu         ###   ########.fr       */
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
