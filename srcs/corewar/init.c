/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:48:29 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/07 19:48:31 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	init_arena(t_vm *vm)
{
	int location;
	int i;

	i = 0;
	while (i < vm->players_num)
	{
		location = MEM_SIZE / vm->players_num * i;
		vm->players[i]->location = location;
		ft_memcpy(&vm->arena[location], &vm->players[i]->instr, \
				vm->players[i]->isntr_size);
		i++;
	}
}

void	init_vm(t_vm *vm)
{
	int	i;

	i = -1;
	vm->cursor = NULL;
	vm->tmp_cursor = NULL;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->dump = -1;
	vm->flags = 0;
	vm->id = 0;
	vm->last_alive = NULL;
	vm->nbr_checks = 0;
	vm->nbr_live = 0;
	vm->players_num = 0;
	vm->cursors_num = 0;
	vm->total_cycles = 0;
	vm->cycles_to_check = 0;
	ft_bzero(vm->arena, sizeof(uint8_t) * MEM_SIZE);
	ft_bzero(vm->players, sizeof(t_player *) * 4);
	vm->is_init_viz = 0;
	vm->flag_vs = 0;
	vm->pause = 0;
	vm->speed = MIN_SPEED;
	while (++i < MEM_SIZE)
		vm->color_arena[i] = 5;
}
