/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 22:52:31 by acthulhu          #+#    #+#             */
/*   Updated: 2020/05/29 10:27:56 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"
#include "ft_printf.h"
#include "libft.h"

static void	st_log(t_vm *vm, t_sp *sp, int32_t value[3], int32_t offset[3])
{
	if (vm->instructions & OPERATIONS)
	{
		ft_printf("P %4d | %s r%d ", sp->identifier,\
										g_op_tab[sp->op_code - 1].name,\
										vm->arena[offset[0]]);
		if (sp->op_arg_types[1] == IND_CODE)
			ft_printf("%d", value[1]);
		else
			ft_printf("r%d", vm->arena[offset[1]]);
		ft_putendl("");
	}
}

void		st(t_vm *vm, t_sp *sp)
{
	int32_t		value[3];
	int32_t		offset[3];

	find_arg_pos(vm, sp, value, offset);
	st_log(vm, sp, value, offset);
	if (sp->op_arg_types[1] == IND_CODE)
	{
		int_to_bytes(vm->arena, sp->pc + value[1], value[0]);
		sp->last_change = sp->pc + value[1];
	}
	else
		sp->reg[vm->arena[offset[1]]] = value[0];
	sp->pc += calculate_shift_to_next_op(sp);
}
