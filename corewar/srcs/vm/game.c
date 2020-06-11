/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <yaroslavfedorchuk@mail.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 21:48:40 by lliza             #+#    #+#             */
/*   Updated: 2020/06/03 00:33:27 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"
#include "ft_printf.h"

static void	killem(t_vm *vm, t_sp **temp, t_sp **sp)
{
	t_sp	*ptr;

	ptr = *sp;
	if (*temp)
		(*temp)->next = ptr->next;
	else
		vm->sp_list = ptr->next;
	if (vm->instructions & DEATHS)
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
		ptr->identifier, vm->cycle_total - ptr->cycle_claimed_alive,
		vm->cycle_to_die);
	free(ptr);
}

void		remove_dead_bodies(t_vm *vm)
{
	t_sp	*temp;
	t_sp	*ptr;
	t_bool	murder;

	temp = NULL;
	ptr = vm->sp_list;
	murder = FALSE;
	while (ptr)
	{
		if (vm->cycle_to_die <= 0 ||
		vm->cycle_total - ptr->cycle_claimed_alive >= vm->cycle_to_die)
		{
			killem(vm, &temp, &ptr);
			murder = TRUE;
			ptr = temp ? temp->next : vm->sp_list;
			continue ;
		}
		temp = ptr;
		ptr = ptr->next;
	}
	if (murder && vm->sp_list)
		play_kill_sound();
}

void		champs_moves(t_vm *vm)
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
		ptr = ptr->next;
	}
}

void		cycle(t_vm *vm)
{
	vm->curr_cycle += 1;
	vm->cycle_total += 1;
	if (vm->instructions & CYCLES)
		ft_printf("It is now cycle %d\n", vm->cycle_total);
	champs_moves(vm);
	if (vm->cycle_to_die <= 0 || vm->curr_cycle == vm->cycle_to_die)
	{
		vm->live_checks_num += 1;
		remove_dead_bodies(vm);
		if (vm->live_checks_num == MAX_CHECKS ||
			vm->claimed_alive_total >= NBR_LIVE)
		{
			vm->live_checks_num = 0;
			vm->cycle_to_die -= CYCLE_DELTA;
			if (vm->instructions & CYCLES)
				ft_printf("Cycle to die is now %d\n", vm->cycle_to_die);
		}
		vm->claimed_alive_total = 0;
		vm->curr_cycle = 0;
	}
}

void		game(t_vm *vm)
{
	while (vm->sp_list)
	{
		if (vm->cycle_to_dump && vm->cycle_to_dump == vm->cycle_total)
		{
			dump(vm, (vm->flags & DUMP_64) ? 64 : 32);
			if (vm->flags & DUMP_GO)
				vm->cycle_to_dump += vm->rise_dump;
			else
				vm_exit_success(vm);
			ft_printf("It was %6d cycle\n", vm->cycle_total);
		}
		cycle(vm);
	}
	the_winner_is(vm);
}
