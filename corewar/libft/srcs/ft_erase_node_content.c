/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase_node_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:24:05 by lliza             #+#    #+#             */
/*   Updated: 2020/05/29 01:55:37 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_erase_node_content(void *node, size_t node_size)
{
	t_list *ptr;

	ptr = node;
	if (ptr)
		if (ptr->content_size == node_size)
		{
			free(ptr->content);
			ptr->content = NULL;
		}
}
