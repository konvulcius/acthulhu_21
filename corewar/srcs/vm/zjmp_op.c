/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 23:03:43 by acthulhu          #+#    #+#             */
/*   Updated: 2020/05/29 10:28:35 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"
#include "ft_printf.h"
#include "libft.h"

static void	zjmp_log(t_vm *vm, t_sp *sp, int32_t shift)
{
	if (vm->instructions & OPERATIONS)
	{
		ft_printf("P %4d | %s %d ", sp->identifier,\
									g_op_tab[sp->op_code - 1].name,\
									shift);
		if (sp->carry)
			ft_putendl("OK");
		else
			ft_putendl("FAILED");
	}
}

void		zjmp(t_vm *vm, t_sp *sp)
{
	int32_t	shift_to_next;

	shift_to_next =
bytes_to_int(vm->arena, sp->pc + 1, g_op_tab[sp->op_code - 1].t_dir_size);
	shift_to_next %= IDX_MOD;
	zjmp_log(vm, sp, shift_to_next);
	if (sp->carry)
		sp->pc += shift_to_next;
	else
		sp->pc += calculate_shift_to_next_op(sp);
}
