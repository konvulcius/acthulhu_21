/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliza <robotizac@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 17:50:29 by acthulhu          #+#    #+#             */
/*   Updated: 2020/05/28 23:12:07 by lliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"
#include "ft_printf.h"
#include <stdlib.h>

void	play_kill_sound(void)
{
	system("pkill afplay");
	system("afplay assets/BaseBallBatRelease.wav &> /dev/null &");
}

void	play_win_sound(void)
{
	system("pkill afplay");
	system("afplay assets/TaDa.mp3 &> /dev/null &");
}

void	the_winner_is(t_vm *vm)
{
	t_champ *last_hero;

	last_hero = find_champ(vm, vm->last_hero);
	ft_printf(CLAIM_WINNER, last_hero->id, last_hero->header->prog_name);
	play_win_sound();
}
