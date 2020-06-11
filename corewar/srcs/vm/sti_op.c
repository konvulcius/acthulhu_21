#include "ft_corewar.h"
#include "ft_printf.h"

static void	sti_log(t_vm *vm, t_sp *sp, int32_t value[3], int offset[3])
{
	if (vm->instructions & OPERATIONS)
	{
		ft_printf("P %4d | %s r%d %d %d", sp->identifier,\
									g_op_tab[sp->op_code - 1].name,\
									vm->arena[offset[0]],\
									value[1],\
									value[2]);
		ft_printf("\n%6s | -> store to %d + %d = %d \
(with pc and mod %d = %d)\n", " ",\
					value[1],\
					value[2],\
					(value[1] + value[2]) % IDX_MOD,\
					MEM_SIZE,\
					(sp->pc + ((value[1] + value[2]) % IDX_MOD) % MEM_SIZE));
	}
}

void		sti(t_vm *vm, t_sp *sp)
{
	int32_t		value[3];
	int32_t		offset[3];
	int32_t		point;

	find_arg_pos(vm, sp, value, offset);
	if (sp->op_arg_types[1] == IND_CODE)
		value[1] = bytes_to_int(vm->arena, sp->pc + value[1], REG_SIZE);
	sti_log(vm, sp, value, offset);
	point = (value[1] + value[2]) % IDX_MOD;
	int_to_bytes(vm->arena, sp->pc + point, value[0]);
	sp->last_change = sp->pc + point;
	sp->pc += calculate_shift_to_next_op(sp);
}
