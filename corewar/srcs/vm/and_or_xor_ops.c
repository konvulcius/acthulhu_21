/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_xor_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 22:51:34 by acthulhu          #+#    #+#             */
/*   Updated: 2020/05/29 10:23:38 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"
#include "ft_printf.h"

static void	byte_ops_log(t_vm *vm, t_sp *sp, int32_t value[3], int offset[3])
{
	if (vm->instructions & OPERATIONS)
	{
		ft_printf("P %4d | %s %d %d r%d\n", sp->identifier,\
											g_op_tab[sp->op_code - 1].name,\
											value[0],\
											value[1],\
											vm->arena[offset[2]]);
	}
}

void		and(t_vm *vm, t_sp *sp)
{
	int32_t		value[3];
	int32_t		offset[3];

	find_arg_pos(vm, sp, value, offset);
	if (sp->op_arg_types[0] == IND_CODE)
		value[0] = bytes_to_int(vm->arena, sp->pc + value[0], REG_SIZE);
	if (sp->op_arg_types[1] == IND_CODE)
		value[1] = bytes_to_int(vm->arena, sp->pc + value[1], REG_SIZE);
	sp->reg[vm->arena[offset[2]]] = value[0] & value[1];
	check_switch_carry(sp, sp->reg[vm->arena[offset[2]]]);
	byte_ops_log(vm, sp, value, offset);
	sp->pc += calculate_shift_to_next_op(sp);
}

void		or(t_vm *vm, t_sp *sp)
{
	int32_t		value[3];
	int			offset[3];

	find_arg_pos(vm, sp, value, offset);
	if (sp->op_arg_types[0] == IND_CODE)
		value[0] = bytes_to_int(vm->arena, sp->pc + value[0], REG_SIZE);
	if (sp->op_arg_types[1] == IND_CODE)
		value[1] = bytes_to_int(vm->arena, sp->pc + value[1], REG_SIZE);
	sp->reg[vm->arena[offset[2]]] = value[0] | value[1];
	check_switch_carry(sp, sp->reg[vm->arena[offset[2]]]);
	byte_ops_log(vm, sp, value, offset);
	sp->pc += calculate_shift_to_next_op(sp);
}

void		xor(t_vm *vm, t_sp *sp)
{
	int32_t		value[3];
	int			offset[3];

	find_arg_pos(vm, sp, value, offset);
	if (sp->op_arg_types[0] == IND_CODE)
		value[0] = bytes_to_int(vm->arena, sp->pc + value[0], REG_SIZE);
	if (sp->op_arg_types[1] == IND_CODE)
		value[1] = bytes_to_int(vm->arena, sp->pc + value[1], REG_SIZE);
	sp->reg[vm->arena[offset[2]]] = value[0] ^ value[1];
	check_switch_carry(sp, sp->reg[vm->arena[offset[2]]]);
	byte_ops_log(vm, sp, value, offset);
	sp->pc += calculate_shift_to_next_op(sp);
}
