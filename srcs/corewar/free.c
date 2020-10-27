/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:30:41 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:30:44 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	delete_players(t_player **players, int players_num)
{
	int i;

	i = 0;
	while (i < players_num)
	{
		if (players[i])
			free(players[i]);
		players[i] = NULL;
		i++;
	}
}

void	delete_cursors(t_cursor *cursor)
{
	t_cursor *tmp;

	tmp = NULL;
	while (cursor)
	{
		tmp = cursor;
		cursor = cursor->next;
		free(tmp);
	}
}

void	ft_free(t_vm *vm)
{
	delete_players(vm->players, vm->players_num);
	if (vm->cursor)
		delete_cursors(vm->cursor);
	vm->cursor = NULL;
	vm->last_alive = NULL;
}
