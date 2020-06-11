/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <yaroslavfedorchuk@mail.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 22:57:23 by acthulhu          #+#    #+#             */
/*   Updated: 2020/06/03 00:52:01 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"
#include "ft_printf.h"
#include "libft.h"

t_bool	arg_types_valid(t_sp *sp, t_op *op)
{
	int32_t i;

	i = 0;
	while (i < op->p_qnty)
	{
		if (sp->op_arg_types[i] == REG_CODE)
		{
			if (!(T_REG & op->params[i]))
				return (FALSE);
		}
		else if (sp->op_arg_types[i] == DIR_CODE)
		{
			if (!(T_DIR & op->params[i]))
				return (FALSE);
		}
		else if (sp->op_arg_types[i] == IND_CODE)
		{
			if (!(T_IND & op->params[i]))
				return (FALSE);
		}
		else
			return (FALSE);
		++i;
	}
	return (TRUE);
}

t_bool	args_valid(t_vm *vm, t_sp *sp, t_op *op)
{
	int32_t i;
	int32_t	offset;

	i = 0;
	offset = 1;
	if (op->args_code)
		offset++;
	while (i < op->p_qnty)
	{
		if (sp->op_arg_types[i] == DIR_CODE)
			offset += op->t_dir_size;
		else if (sp->op_arg_types[i] == IND_CODE)
			offset += IND_SIZE;
		else if (sp->op_arg_types[i] == REG_CODE)
		{
			if (vm->arena[make_pc_fit_arena(sp->pc + offset)] < 1 ||
				vm->arena[make_pc_fit_arena(sp->pc + offset)] > REG_NUMBER)
				return (FALSE);
			offset++;
		}
		++i;
	}
	return (TRUE);
}

void	dump_line(t_vm *vm, size_t num, size_t size)
{
	size_t i;

	i = 0;
	ft_printf("0x%04x : ", num);
	while (i < size)
	{
		ft_printf("%02x ", vm->arena[num + i]);
		++i;
	}
	ft_putendl("");
}

void	dump(t_vm *vm, size_t size)
{
	size_t i;

	i = 0;
	while (i < MEM_SIZE)
	{
		dump_line(vm, i, size);
		i += size;
	}
}
