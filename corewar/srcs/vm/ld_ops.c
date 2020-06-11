#include "ft_corewar.h"
#include "ft_printf.h"

static void	ld_ops_log(t_vm *vm, t_sp *sp, int32_t value[3], int offset[3])
{
	if (vm->instructions & OPERATIONS)
	{
		ft_printf("P %4d | %s %d r%hhd\n", sp->identifier,\
											g_op_tab[sp->op_code - 1].name,\
											value[0],\
											vm->arena[offset[1]]);
	}
}

void		ld(t_vm *vm, t_sp *sp)
{
	int32_t		value[3];
	int32_t		offset[3];

	find_arg_pos(vm, sp, value, offset);
	if (sp->op_arg_types[0] == IND_CODE)
		value[0] = bytes_to_int(vm->arena, sp->pc + value[0], REG_SIZE);
	sp->reg[vm->arena[offset[1]]] = value[0];
	check_switch_carry(sp, value[0]);
	ld_ops_log(vm, sp, value, offset);
	sp->pc += calculate_shift_to_next_op(sp);
}

void		lld(t_vm *vm, t_sp *sp)
{
	int32_t		value[3];
	int32_t		offset[3];

	find_arg_pos(vm, sp, value, offset);
	if (sp->op_arg_types[0] == IND_CODE)
	{
		value[0] = bytes_to_int(vm->arena, sp->pc + 2, IND_SIZE);
		if (vm->instructions & LLD4)
			value[0] = bytes_to_int(vm->arena, sp->pc + value[0], REG_SIZE);
		else
			value[0] = bytes_to_int(vm->arena, sp->pc + value[0], IND_SIZE);
	}
	sp->reg[vm->arena[offset[1]]] = value[0];
	check_switch_carry(sp, value[0]);
	ld_ops_log(vm, sp, value, offset);
	sp->pc += calculate_shift_to_next_op(sp);
}
