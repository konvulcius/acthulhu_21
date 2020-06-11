/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 22:56:12 by acthulhu          #+#    #+#             */
/*   Updated: 2020/05/29 10:25:00 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"
#include "ft_printf.h"

static void	ldi_ops_log(t_vm *vm, t_sp *sp, int32_t value[3], int offset[3])
{
	if (vm->instructions & OPERATIONS)
	{
		ft_printf("P %4d | %s %d %d r%d", sp->identifier,\
									g_op_tab[sp->op_code - 1].name,\
									value[0],\
									value[1],\
									vm->arena[offset[2]]);
		ft_printf("\n%6s | -> load from (%d + %d)", " ",\
								value[0],\
								value[1]);
		if (sp->op_code == 10)
		{
			ft_printf("%% %d = %d (with pc and mod %d = %d)\n", IDX_MOD,\
					(value[0] + value[1]) % IDX_MOD,\
					MEM_SIZE,\
					(sp->pc + ((value[0] + value[1]) % IDX_MOD) % MEM_SIZE));
		}
		else
		{
			ft_printf(" = %d (with pc and mod %d = %d)\n", value[0] + value[1],\
							MEM_SIZE,\
							(sp->pc + (value[0] + value[1]) % MEM_SIZE));
		}
	}
}

void		ldi(t_vm *vm, t_sp *sp)
{
	int32_t		value[3];
	int32_t		offset[3];

	find_arg_pos(vm, sp, value, offset);
	if (sp->op_arg_types[0] == IND_CODE)
		value[0] = bytes_to_int(vm->arena, sp->pc + value[0], REG_SIZE);
	value[2] = (value[0] + value[1]) % IDX_MOD;
	sp->reg[vm->arena[offset[2]]] = \
		bytes_to_int(vm->arena, sp->pc + value[2], REG_SIZE);
	ldi_ops_log(vm, sp, value, offset);
	sp->pc += calculate_shift_to_next_op(sp);
}

void		lldi(t_vm *vm, t_sp *sp)
{
	int32_t		value[3];
	int32_t		offset[3];

	find_arg_pos(vm, sp, value, offset);
	if (sp->op_arg_types[0] == IND_CODE)
		value[0] = bytes_to_int(vm->arena, sp->pc + value[0], REG_SIZE);
	value[2] = (value[0] + value[1]);
	sp->reg[vm->arena[offset[2]]] = \
		bytes_to_int(vm->arena, sp->pc + value[2], REG_SIZE);
	ldi_ops_log(vm, sp, value, offset);
	sp->pc += calculate_shift_to_next_op(sp);
}
