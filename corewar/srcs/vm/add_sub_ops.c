#include "ft_corewar.h"
#include "ft_printf.h"

static void	add_sub_log(t_vm *vm, t_sp *sp, int offset[3])
{
	if (vm->instructions & OPERATIONS)
	{
		ft_printf("P %4d | %5s r%d r%d r%d\n", sp->identifier,\
											g_op_tab[sp->op_code - 1].name,\
											vm->arena[offset[0]],\
											vm->arena[offset[1]],\
											vm->arena[offset[2]]);
	}
}

void		add(t_vm *vm, t_sp *sp)
{
	int32_t		value[3];
	int32_t		offset[3];

	find_arg_pos(vm, sp, value, offset);
	sp->reg[vm->arena[offset[2]]] = value[0] + value[1];
	check_switch_carry(sp, sp->reg[vm->arena[offset[2]]]);
	add_sub_log(vm, sp, offset);
	sp->pc += calculate_shift_to_next_op(sp);
}

void		sub(t_vm *vm, t_sp *sp)
{
	int32_t		value[3];
	int32_t		offset[3];

	find_arg_pos(vm, sp, value, offset);
	sp->reg[vm->arena[offset[2]]] = value[0] - value[1];
	check_switch_carry(sp, sp->reg[vm->arena[offset[2]]]);
	add_sub_log(vm, sp, offset);
	sp->pc += calculate_shift_to_next_op(sp);
}
