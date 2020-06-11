/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:29:53 by lliza             #+#    #+#             */
/*   Updated: 2020/05/29 21:56:14 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COREWAR_H
# define FT_COREWAR_H

# include <stdlib.h>
# include "op.h"
# include "vm_structs.h"

/*
** functions
*/
void				live(t_vm *vm, t_sp *sp);
void				ld(t_vm *vm, t_sp *sp);
void				st(t_vm *vm, t_sp *sp);
void				add(t_vm *vm, t_sp *sp);
void				sub(t_vm *vm, t_sp *sp);
void				and(t_vm *vm, t_sp *sp);
void				or(t_vm *vm, t_sp *sp);
void				xor(t_vm *vm, t_sp *sp);
void				zjmp(t_vm *vm, t_sp *sp);
void				ldi(t_vm *vm, t_sp *sp);
void				sti(t_vm *vm, t_sp *sp);
void				vm_fork(t_vm *vm, t_sp *sp);
void				lld(t_vm *vm, t_sp *sp);
void				lldi(t_vm *vm, t_sp *sp);
void				lfork(t_vm *vm, t_sp *sp);
void				aff(t_vm *vm, t_sp *sp);

/*
**	init
*/
t_sp				*init_sp(t_vm *vm, t_champ *champ);
t_vm				*init_vm(int32_t ac, char **av);
void				add_champ_to_list(t_vm *vm, t_champ *champ);

/*
** functions' utils
*/
void				int_to_bytes
	(uint8_t *address, int32_t offset, int32_t	value);
t_champ				*find_champ(t_vm *vm, uint8_t id);
void				find_arg_pos
	(t_vm *vm, t_sp *sp, int32_t value[3], int32_t offset[3]);
void				check_switch_carry(t_sp *sp, int32_t memory);
void				regs_cpy(t_sp *dst, t_sp *src);
t_bool				is_op(int32_t op_code);
void				reset_op_arg_types(t_sp *sp);
void				get_op_arg_types(t_vm *vm, t_sp *sp);
int32_t				calculate_shift_to_next_op(t_sp *sp);
int32_t				bytes_to_int(uint8_t *address, int32_t offset, size_t size);
int32_t				make_pc_fit_arena(int32_t pc);

/*
** champ utils
*/
size_t				get_champs_num(int32_t ac, char **av);
void				place_champ(t_vm *vm, t_sp *sp, size_t i);
void				introduce_champ(t_vm *vm, t_sp *sp, size_t i);

/*
** sp utils
*/
void				add_sp_to_list(t_vm *vm, t_sp *sp, t_bool make_first);
void				apply_to_sp_list
	(t_vm *vm, t_sp *sp, void (*f)(t_vm *vm, t_sp *sp, size_t i), int32_t rcsv);
void				exec_sp(t_vm *vm, t_sp *sp);

/*
** parse
*/
void				sort_champ(t_vm *vm);
t_champ				*parse_champ(t_vm *vm, char *filename, int32_t id);
void				parse(t_vm *vm, int32_t ac, char **av);

/*
** validate
*/
t_bool				file_is_champ(char *filename);
int32_t				ft_only_dig_validation(char *string);
t_bool				arg_types_valid(t_sp *sp, t_op *op);
t_bool				args_valid(t_vm *vm, t_sp *sp, t_op *op);

/*
** free, exit, tools
*/
void				vm_free(t_vm *vm);
void				sp_free(t_sp *sp);
void				vm_exit_success(t_vm *vm);
void				vm_exit_failure(t_vm *vm);
void				vm_exit_malloc_failure(t_vm *vm);
void				vm_exit_sys_failure(t_vm *vm, char *string);
void				usage_exit(t_vm *vm);
void				dump(t_vm *vm, size_t size);
void				the_winner_is(t_vm *vm);
void				play_kill_sound();
void				play_win_sound();

/*
** game cycle
*/
void				game(t_vm *vm);
void				remove_dead_bodies(t_vm *vm);
void				champs_moves(t_vm *vm);
void				cycle(t_vm *vm);

/*
** vs
*/
void				vs(t_vm *vm);

#endif
