#include "ft_corewar.h"
#include "libft.h"

static void	init_regs(t_sp *sp)
{
	size_t	i;

	i = 0;
	while (i < REG_NUMBER + 1)
		sp->reg[i++] = 0;
}

void		add_champ_to_list(t_vm *vm, t_champ *champ)
{
	t_champ *temp;

	if (!vm->champ_list)
		vm->champ_list = champ;
	else
	{
		temp = vm->champ_list;
		while (temp->next)
			temp = temp->next;
		temp->next = champ;
	}
}

t_sp		*init_sp(t_vm *vm, t_champ *champ)
{
	t_sp	*sp;

	if (!(sp = (t_sp*)malloc(sizeof(t_sp))))
		vm_exit_malloc_failure(vm);
	init_regs(sp);
	sp->stepfather_id = 0;
	sp->identifier = 0;
	sp->cycles_to_exec_op = 0;
	sp->pc = 0;
	sp->op_code = 0;
	sp->last_change = NO_CHANGE;
	sp->champ = champ;
	sp->cycle_claimed_alive = 0;
	sp->carry = 0;
	sp->next = NULL;
	return (sp);
}

t_vm		*init_vm(int ac, char **av)
{
	t_vm	*vm;

	if (!(vm = (t_vm *)malloc(sizeof(t_vm))) ||
		!(vm->arena = (uint8_t *)malloc(MEM_SIZE)))
		vm_exit_malloc_failure(vm);
	vm->sp_list = NULL;
	vm->champ_list = NULL;
	if ((vm->champs_num = get_champs_num(ac, av)) > MAX_PLAYERS)
	{
		ft_putendl_fd("Too many champions", 2);
		vm_exit_failure(vm);
	}
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->prev_cycle_to_die = CYCLE_TO_DIE;
	vm->curr_cycle = 0;
	vm->cycle_total = 0;
	vm->cycle_to_dump = 0;
	vm->live_checks_num = 0;
	vm->claimed_alive_total = 0;
	vm->flags = 0;
	vm->instructions = 0;
	vm->last_hero = vm->champs_num;
	ft_bzero(vm->arena, MEM_SIZE);
	return (vm);
}
