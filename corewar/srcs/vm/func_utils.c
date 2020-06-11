/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <yaroslavfedorchuk@mail.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 20:51:34 by acthulhu          #+#    #+#             */
/*   Updated: 2020/06/03 00:58:52 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void	int_to_bytes(uint8_t *address, int offset, int32_t value)
{
	address[make_pc_fit_arena(offset++)] = (value >> 24) & 0xff;
	address[make_pc_fit_arena(offset++)] = (value >> 16) & 0xff;
	address[make_pc_fit_arena(offset++)] = (value >> 8) & 0xff;
	address[make_pc_fit_arena(offset)] = value & 0xff;
}

void	check_switch_carry(t_sp *sp, int32_t memory)
{
	if (!memory)
		sp->carry = 1;
	else
		sp->carry = 0;
}

void	regs_cpy(t_sp *dst, t_sp *src)
{
	int32_t		i;

	i = 0;
	while (i < REG_NUMBER + 1)
	{
		dst->reg[i] = src->reg[i];
		i++;
	}
}

t_champ	*find_champ(t_vm *vm, uint8_t id)
{
	t_champ *champ;

	champ = vm->champ_list;
	while (champ)
	{
		if (champ->id == id)
			break ;
		champ = champ->next;
	}
	return (champ);
}

void	find_arg_pos(t_vm *vm, t_sp *sp, int32_t value[3], int offset[3])
{
	int32_t		i;
	int32_t		cur;

	i = 0;
	cur = g_op_tab[sp->op_code - 1].args_code ? 2 : 1;
	while (i < g_op_tab[sp->op_code - 1].p_qnty)
	{
		offset[i] = make_pc_fit_arena(sp->pc + cur);
		if (sp->op_arg_types[i] == IND_CODE)
		{
			value[i] = bytes_to_int(vm->arena, offset[i], IND_SIZE) % IDX_MOD;
			cur += IND_SIZE - 1;
		}
		else if (sp->op_arg_types[i] == DIR_CODE)
		{
			value[i] = bytes_to_int(vm->arena, offset[i],\
				g_op_tab[sp->op_code - 1].t_dir_size);
			cur += g_op_tab[sp->op_code - 1].t_dir_size - 1;
		}
		else
			value[i] = sp->reg[vm->arena[offset[i]]];
		cur++;
		i++;
	}
}
