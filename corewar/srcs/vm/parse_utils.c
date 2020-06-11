/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <yaroslavfedorchuk@mail.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 23:00:26 by acthulhu          #+#    #+#             */
/*   Updated: 2020/05/27 23:00:26 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static int	check_id(t_sp *start, uint8_t id)
{
	while (start)
	{
		if (start->champ->id == id)
			return (0);
		start = start->next;
	}
	return (1);
}

static void	put_id(t_vm *vm)
{
	int8_t	id;
	t_sp	*cur;

	id = 1;
	cur = vm->sp_list;
	while (1)
	{
		while (cur && cur->champ->id)
		{
			cur->reg[1] = ~cur->champ->id + 1;
			cur->identifier = cur->champ->id;
			cur = cur->next;
		}
		if (!cur)
			break ;
		if (check_id(vm->sp_list, id))
			cur->champ->id = id;
		id++;
	}
}

void		sort_champ(t_vm *vm)
{
	t_sp	*cur;
	t_sp	*temp;

	put_id(vm);
	cur = vm->sp_list;
	temp = NULL;
	while (cur && cur->next)
	{
		if (cur->next->champ->id > cur->champ->id)
		{
			if (!temp)
				vm->sp_list = cur->next;
			else
				temp->next = cur->next;
			temp = cur->next;
			cur->next = temp->next;
			temp->next = cur;
			temp = NULL;
			cur = vm->sp_list;
			continue ;
		}
		temp = cur;
		cur = cur->next;
	}
}
