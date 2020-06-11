/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <yaroslavfedorchuk@mail.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2020/05/27 22:51:15 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

t_op	g_op_tab[17] = {
	{"live", 1, {T_DIR}, 1, 10, "alive", DIR_SIZE, FALSE, live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", DIR_SIZE, TRUE, ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", DIR_SIZE, TRUE, st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", DIR_SIZE, TRUE, add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", DIR_SIZE,
		TRUE, sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", DIR_SIZE, TRUE, and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", DIR_SIZE, TRUE, or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", DIR_SIZE, TRUE, xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", IND_SIZE, FALSE, zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", IND_SIZE, TRUE, ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", IND_SIZE, TRUE, sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", IND_SIZE, FALSE, vm_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", DIR_SIZE,
		TRUE, lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", IND_SIZE, TRUE, lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", IND_SIZE, FALSE, lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", DIR_SIZE, TRUE, aff},
	{0, 0, {0}, 0, 0, 0, 0, 0, NULL}
};
