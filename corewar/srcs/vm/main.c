/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 21:49:21 by lliza             #+#    #+#             */
/*   Updated: 2020/05/28 22:14:39 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"
#include "libft.h"

int			main(int ac, char **av)
{
	t_vm		*vm;

	vm = init_vm(ac, av);
	parse(vm, ac, av);
	if (vm->flags & USAGE)
		usage_exit(vm);
	if (!vm->sp_list)
	{
		ft_putendl_fd("Error: no champs", 2);
		vm_exit_failure(vm);
	}
	apply_to_sp_list(vm, vm->sp_list, place_champ, 1);
	ft_putendl("Introducing contestants...");
	apply_to_sp_list(vm, vm->sp_list, introduce_champ, 1);
	if (vm->flags & NCURSES)
		vs(vm);
	else
		game(vm);
	vm_free(vm);
	return (0);
}
