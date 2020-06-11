/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 23:03:20 by acthulhu          #+#    #+#             */
/*   Updated: 2020/05/29 10:25:26 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int		bytes_to_int(uint8_t *address, int offset, size_t size)
{
	int32_t	val;

	val = 0;
	if (size == 4)
	{
		val |= address[make_pc_fit_arena(offset++)] << 24;
		val |= address[make_pc_fit_arena(offset++)] << 16;
	}
	val |= address[make_pc_fit_arena(offset++)] << 8;
	val |= address[make_pc_fit_arena(offset)];
	if (size == 2 && (val & (1 << 15)))
		val |= 0xffff << 16;
	return (val);
}

t_bool	is_op(int op_code)
{
	return (op_code > 0 && op_code < 17);
}

void	reset_op_arg_types(t_sp *sp)
{
	sp->op_arg_types[0] = 0;
	sp->op_arg_types[1] = 0;
	sp->op_arg_types[2] = 0;
}

void	get_op_arg_types(t_vm *vm, t_sp *sp)
{
	int32_t	i;
	uint8_t	args_code;

	i = 0;
	reset_op_arg_types(sp);
	if (g_op_tab[sp->op_code - 1].args_code)
	{
		args_code = vm->arena[make_pc_fit_arena(sp->pc + 1)];
		while (i < g_op_tab[sp->op_code - 1].p_qnty)
		{
			if (i == 0)
				sp->op_arg_types[i] = (args_code & 0xc0) >> 6;
			else if (i == 1)
				sp->op_arg_types[i] = (args_code & 0x30) >> 4;
			else if (i == 2)
				sp->op_arg_types[i] = (args_code & 0xc) >> 2;
			++i;
		}
	}
	else
		sp->op_arg_types[0] = DIR_CODE;
}

int		calculate_shift_to_next_op(t_sp *sp)
{
	size_t	i;
	int32_t	r;

	i = 0;
	r = 0;
	if (is_op(sp->op_code))
	{
		while (i < (size_t)g_op_tab[sp->op_code - 1].p_qnty)
		{
			if (sp->op_arg_types[i] == REG_CODE)
				r += 1;
			else if (sp->op_arg_types[i] == IND_CODE)
				r += IND_SIZE;
			else if (sp->op_arg_types[i] == DIR_CODE)
				r += g_op_tab[sp->op_code - 1].t_dir_size;
			++i;
		}
		return (r + 1 + (g_op_tab[sp->op_code - 1].args_code ? 1 : 0));
	}
	return (1);
}
