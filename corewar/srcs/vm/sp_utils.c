/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <yaroslavfedorchuk@mail.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 21:49:11 by lliza             #+#    #+#             */
/*   Updated: 2020/06/03 00:33:25 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int32_t	make_pc_fit_arena(int32_t pc)
{
	pc %= MEM_SIZE;
	if (pc < 0)
		pc += MEM_SIZE;
	return (pc);
}

void	exec_sp(t_vm *vm, t_sp *sp)
{
	if (sp->cycles_to_exec_op > 0)
		sp->cycles_to_exec_op -= 1;
	if (sp->cycles_to_exec_op == 0)
	{
		if (is_op(sp->op_code))
		{
			get_op_arg_types(vm, sp);
			if (arg_types_valid(sp, &g_op_tab[sp->op_code - 1]) &&
				args_valid(vm, sp, &g_op_tab[sp->op_code - 1]))
				g_op_tab[sp->op_code - 1].f(vm, sp);
			else
				sp->pc += calculate_shift_to_next_op(sp);
		}
		else
			sp->pc += 1;
		sp->pc = make_pc_fit_arena(sp->pc);
	}
}

void	add_sp_to_list(t_vm *vm, t_sp *sp, t_bool make_first)
{
	t_sp			*temp;

	if (!vm->sp_list)
		vm->sp_list = sp;
	else if (make_first)
	{
		sp->identifier = vm->new_sp_num++;
		sp->next = vm->sp_list;
		vm->sp_list = sp;
	}
	else
	{
		temp = vm->sp_list;
		while (temp->next)
			temp = temp->next;
		temp->next = sp;
	}
}

void	apply_to_sp_list(t_vm *vm, t_sp *sp,\
	void (*f)(t_vm *vm, t_sp *sp, size_t i), int32_t recursive)
{
	t_sp	*temp;
	size_t	i;

	i = 0;
	temp = sp;
	if (recursive)
	{
		if (temp->next)
			apply_to_sp_list(vm, temp->next, f, 1);
		f(vm, temp, temp->champ->id - 1);
	}
	else
	{
		while (temp)
		{
			f(vm, temp, i);
			temp = temp->next;
			++i;
		}
	}
}
