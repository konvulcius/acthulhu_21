/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <acthulhu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:32:19 by acthulhu          #+#    #+#             */
/*   Updated: 2020/01/30 21:38:55 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	procedure_swap(t_list **top)
{
	t_list	*temp;

	if (*top && (*top)->next)
	{
		temp = (*top)->next;
		(*top)->next = temp->next;
		temp->next = *top;
		*top = temp;
	}
}

void	procedure_push(t_list **dest, t_list **source)
{
	t_list	*temp;

	if (*source)
	{
		temp = (*source)->next;
		ft_lstadd(dest, *source);
		*source = temp;
	}
}

void	procedure_rotate(t_list **top)
{
	t_list	*temp;
	t_list	*last;

	if (!*top || !(*top)->next)
		return ;
	temp = *top;
	last = temp->next;
	while (last->next)
		last = last->next;
	*top = temp->next;
	last->next = temp;
	temp->next = NULL;	
}

void	procedure_reverse_rotate(t_list **top)
{
	t_list	*temp;
	t_list	*last;

	if (!*top || !(*top)->next)
		return ;
	temp = *top;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	ft_lstadd(top, last);
}

void	double_procedure(t_list **stack_a, t_list **stack_b, \
			void (*f)(t_list **))
{
	f(stack_a);
	f(stack_b);
}