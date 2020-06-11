/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:58:51 by eblackbu          #+#    #+#             */
/*   Updated: 2020/05/29 19:09:57 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"

void	print_error_with_arg(char *str, int num_arg)
{
	ft_printf("%WError in line %d: %s %d\n", 2, g_current_string, str, num_arg);
}

void	error_args(int code, int num_arg)
{
	if (code == ERR_INV_TYPE)
		print_error_with_arg("invalid type of argument", num_arg);
	if (code == ERR_COUNT_ARGS)
		ft_printf_error("invalid count of arguments");
	if (code == ERR_INV_ARG)
		print_error_with_arg("invalid argument", num_arg);
	if (code == ERR_INV_REG)
		print_error_with_arg("invalid number of registry, argument", num_arg);
	exit(-1);
}
