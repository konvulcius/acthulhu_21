/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:30:52 by lliza             #+#    #+#             */
/*   Updated: 2020/05/29 01:56:06 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	if (s && f)
	{
		ptr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!ptr)
			return (NULL);
		while (s[i])
		{
			ptr[i] = f(i, s[i]);
			++i;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
