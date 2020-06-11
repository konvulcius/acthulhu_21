#include "ft_corewar.h"
#include "ft_printf.h"
#include "libft.h"

static void	fork_ops_log(t_vm *vm, t_sp *sp, int new_pc)
{
	if (vm->instructions & OPERATIONS)
	{
		ft_printf("P %4d | %s %d\n", sp->identifier,\
										g_op_tab[sp->op_code - 1].name,\
										new_pc - sp->pc);
	}
}

void		vm_fork(t_vm *vm, t_sp *sp)
{
	t_sp	*new;

	if (!(new = (t_sp*)malloc(sizeof(t_sp))))
		vm_exit_malloc_failure(vm);
	new->stepfather_id = sp->stepfather_id ? sp->stepfather_id : sp->identifier;
	new->champ = sp->champ;
	ft_bzero(new->op_arg_types, sizeof(uint8_t) * 3);
	regs_cpy(new, sp);
	new->cycle_claimed_alive = sp->cycle_claimed_alive;
	new->cycles_to_exec_op = 0;
	new->carry = sp->carry;
	new->pc = sp->pc + \
	bytes_to_int(vm->arena, sp->pc + 1, g_op_tab[sp->op_code - 1].t_dir_size)\
		% IDX_MOD;
	new->pc = make_pc_fit_arena(new->pc);
	add_sp_to_list(vm, new, 1);
	fork_ops_log(vm, sp, new->pc);
	sp->pc += calculate_shift_to_next_op(sp);
}

void		lfork(t_vm *vm, t_sp *sp)
{
	t_sp	*new;

	if (!(new = (t_sp*)malloc(sizeof(t_sp))))
		vm_exit_malloc_failure(vm);
	new->stepfather_id = sp->stepfather_id ? sp->stepfather_id : sp->identifier;
	new->champ = sp->champ;
	ft_bzero(new->op_arg_types, sizeof(uint8_t) * 3);
	regs_cpy(new, sp);
	new->cycle_claimed_alive = sp->cycle_claimed_alive;
	new->cycles_to_exec_op = 0;
	new->carry = sp->carry;
	new->pc = sp->pc + \
	bytes_to_int(vm->arena, sp->pc + 1, g_op_tab[sp->op_code - 1].t_dir_size);
	new->pc = make_pc_fit_arena(new->pc);
	add_sp_to_list(vm, new, 1);
	fork_ops_log(vm, sp, new->pc);
	sp->pc += calculate_shift_to_next_op(sp);
}
