/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:13:12 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/29 13:02:15 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrev(t_list *start)
{
	t_list	*temp;

	if (start->next)
	{
		temp = ft_lstrev(start->next);
		start->next->next = start;
		start->next = NULL;
		return (temp);
	}
	else
		return (start);
}
