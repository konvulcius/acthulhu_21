/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <yaroslavfedorchuk@mail.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 20:47:11 by acthulhu          #+#    #+#             */
/*   Updated: 2020/06/03 00:54:16 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"
#include "ft_printf.h"

static void	live_log(t_vm *vm, t_sp *sp, int32_t value)
{
	if (vm->instructions & OPERATIONS)
	{
		ft_printf("P %4d | %s %d\n", sp->identifier,\
										g_op_tab[sp->op_code - 1].name,\
										value);
	}
}

void		live(t_vm *vm, t_sp *sp)
{
	int32_t temp;
	t_champ	*champ;

	temp = bytes_to_int(vm->arena, sp->pc + 1, REG_SIZE);
	if (vm->instructions & OPERATIONS)
		live_log(vm, sp, temp);
	temp = ~(temp - 1);
	champ = find_champ(vm, temp);
	if (champ)
	{
		ft_printf("A process shows that player %d (%s) is alive\n",
			champ->id,
			champ->header->prog_name);
		vm->last_hero = temp;
	}
	sp->cycle_claimed_alive = vm->cycle_total;
	vm->claimed_alive_total += 1;
	sp->pc += calculate_shift_to_next_op(sp);
}
