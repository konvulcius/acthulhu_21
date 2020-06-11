/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 20:41:07 by acthulhu          #+#    #+#             */
/*   Updated: 2020/05/29 10:23:30 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"
#include "ft_printf.h"

static void		aff_log(t_vm *vm, t_sp *sp, int value)
{
	if (vm->instructions & OPERATIONS)
	{
		ft_printf("P %4d | %s %d\n", sp->identifier,\
											g_op_tab[sp->op_code - 1].name,\
											value);
	}
}

void			aff(t_vm *vm, t_sp *sp)
{
	int32_t		value;

	value = sp->reg[vm->arena[sp->pc + 2]];
	if (vm->flags & AFF)
	{
		ft_printf("AFF: %c\n", (char)value);
		aff_log(vm, sp, value);
	}
	sp->pc += calculate_shift_to_next_op(sp);
}
