/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:35:59 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:36:02 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static int	is_player(int total_player, int id_player)
{
	return (id_player <= -1 && id_player >= -(total_player));
}

void		ft_live(t_vm *vm, t_cursor *cursor)
{
	int value;

	value = 0;
	vm->nbr_live++;
	cursor->last_live = vm->total_cycles;
	value = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
	if (is_player(vm->players_num, value))
	{
		value *= -1;
		vm->last_alive = vm->players[value - 1];
	}
}
