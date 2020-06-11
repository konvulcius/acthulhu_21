#include "ft_corewar.h"

static void	champ_free(t_vm *vm)
{
	t_champ	*delete;

	while (vm->champ_list)
	{
		delete = vm->champ_list;
		vm->champ_list = vm->champ_list->next;
		free(delete->header);
		free(delete->code);
		free(delete);
	}
}

static void	sp_list_free(t_vm *vm)
{
	t_sp	*delete;

	while (vm->sp_list)
	{
		delete = vm->sp_list;
		vm->sp_list = vm->sp_list->next;
		free(delete);
	}
}

void		vm_free(t_vm *vm)
{
	if (vm)
	{
		if (vm->champ_list)
			champ_free(vm);
		if (vm->sp_list)
			sp_list_free(vm);
		free(vm->arena);
		free(vm);
	}
}
