/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:25:26 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/30 21:35:08 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instructions_validation(t_list *start)
{
	while (start)
	{
		if (!ft_strcmp((char*)start->content, "sa") || \
			!ft_strcmp((char*)start->content, "sb") || \
			!ft_strcmp((char*)start->content, "ss") || \
			!ft_strcmp((char*)start->content, "pa") || \
			!ft_strcmp((char*)start->content, "pb") || \
			!ft_strcmp((char*)start->content, "ra") || \
			!ft_strcmp((char*)start->content, "rb") || \
			!ft_strcmp((char*)start->content, "rr") || \
			!ft_strcmp((char*)start->content, "rra") || \
			!ft_strcmp((char*)start->content, "rrb") || \
			!ft_strcmp((char*)start->content, "rrr"))
			start = start->next;
		else
			error();
	}
}

void	only_dig_validation(char *string)
{
	int		count;

	if (*string == '-' || *string == '+')
		string++;
	count = 0;
	while (*string)
	{
		if (count == 11 || !ft_isdigit(*string++))
			error();
		++count;
	}
}

void	digit_compare(t_list *elem)
{
	if (*(long long*)elem->content > MAXIMAL_INT ||
		*(long long*)elem->content < MINIMAL_INT)
		error();
}

void	check_same(t_list *stack)
{
	t_list	*checker;

	digit_compare(stack);
	checker = stack->next;
	while (checker)
	{
		if (ft_memcmp(stack->content, checker->content, \
				stack->content_size) == 0)
			error();			
		checker = checker->next;
	}
}