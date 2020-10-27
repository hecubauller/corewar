/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:30:20 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:30:22 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	delete_cursor(t_vm *vm, t_cursor **current, t_cursor *prev)
{
	if (vm->cursor == (*current))
	{
		vm->cursor = vm->cursor->next;
		free((*current));
		(*current) = vm->cursor;
	}
	else if (prev)
	{
		prev->next = (*current)->next;
		free((*current));
		(*current) = prev->next;
	}
}

void	modified_ctd(t_vm *vm)
{
	vm->nbr_checks++;
	if (vm->nbr_checks == MAX_CHECKS || vm->nbr_live >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->nbr_checks = 0;
	}
	vm->nbr_live = 0;
	vm->cycles_to_check = 0;
}

int		is_dead_cursor(t_vm *vm, t_cursor *cursor)
{
	int last_live;

	last_live = vm->total_cycles - cursor->last_live;
	if (last_live >= vm->cycles_to_die || vm->cycles_to_die <= 0)
		return (1);
	return (0);
}

void	check_cursor(t_vm *vm)
{
	t_cursor	*current;
	t_cursor	*prev;

	prev = NULL;
	current = vm->cursor;
	while (current)
	{
		if (is_dead_cursor(vm, current))
		{
			delete_cursor(vm, &current, prev);
			vm->cursors_num--;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

void	check_ctd_and_cursor(t_vm *vm)
{
	check_cursor(vm);
	modified_ctd(vm);
}
