#include "vs.h"
#include "libft.h"

static void	vs_champs_moves(t_vm *vm, t_vs *vs)
{
	t_sp *ptr;

	ptr = vm->sp_list;
	while (ptr)
	{
		if (ptr->cycles_to_exec_op == 0)
		{
			ptr->op_code = vm->arena[ptr->pc];
			if (is_op(ptr->op_code))
				ptr->cycles_to_exec_op =
				g_op_tab[ptr->op_code - 1].cycles_to_exec;
		}
		exec_sp(vm, ptr);
		vs_apply_arena_update(vm, vs, ptr);
		ptr = ptr->next;
	}
}

void		vs_cycle(t_vm *vm, t_vs *vs)
{
	vm->curr_cycle += 1;
	vm->cycle_total += 1;
	vs_champs_moves(vm, vs);
	if (vm->cycle_to_die <= 0 || vm->curr_cycle == vm->cycle_to_die)
	{
		vm->live_checks_num += 1;
		remove_dead_bodies(vm);
		if (vm->live_checks_num == MAX_CHECKS ||
			vm->claimed_alive_total >= NBR_LIVE)
		{
			vm->live_checks_num = 0;
			vm->cycle_to_die -= CYCLE_DELTA;
		}
		vm->claimed_alive_total = 0;
		vm->curr_cycle = 0;
	}
}

void		run_cycles(t_vm *vm, t_vs *vs, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		vs_cycle(vm, vs);
		++i;
	}
}
