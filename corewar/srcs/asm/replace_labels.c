/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:01:15 by eblackbu          #+#    #+#             */
/*   Updated: 2020/05/30 11:00:59 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"

int			get_indirent_value(t_champion **champ, t_instr *instr, int arg_num)
{
	t_label	*tmp;

	tmp = (*champ)->labels;
	while (tmp && !ft_strequ(tmp->name, instr->args[arg_num].label_name))
		tmp = tmp->next;
	if (!tmp)
	{
		ft_printf("%WError: unknown label %s\n", 2,
		instr->args[arg_num].label_name);
		exit(-1);
	}
	return (tmp->first_byte - instr->first_byte);
}

t_instr		*check_labels(t_champion **champ, t_instr *instr)
{
	int		i;

	i = 0;
	while (i < instr->type.count_args)
	{
		if (instr->args[i].label_name)
			instr->args[i].value = get_indirent_value(champ, instr, i);
		i++;
	}
	return (instr);
}

void		replace_labels(t_champion **champ)
{
	t_instr *tmp;

	g_current_string = 0;
	tmp = (*champ)->code;
	while (tmp)
	{
		tmp = check_labels(champ, tmp);
		tmp = tmp->next;
	}
}
