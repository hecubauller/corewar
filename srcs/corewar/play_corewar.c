/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:39:44 by lelida            #+#    #+#             */
/*   Updated: 2020/10/24 13:39:45 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void		(*g_function[16])(t_vm *, t_cursor *) =
{
	ft_live, ft_ld, ft_st, ft_add, ft_sub, ft_and,
	ft_or, ft_xor, ft_zjmp, ft_ldi, ft_sti, ft_fork,
	ft_lld, ft_lldi, ft_lfork, ft_aff
};

int			is_check_cycle(t_vm *vm)
{
	return (vm->cycles_to_check == vm->cycles_to_die || \
			vm->cycles_to_die <= 0);
}

static void	execute_instruction(t_vm *vm, t_cursor *cursor)
{
	if (cursor->cycles_to_exec == 0)
		get_operation(vm, cursor);
	if (cursor->cycles_to_exec > 0)
		cursor->cycles_to_exec--;
	if (cursor->cycles_to_exec == 0)
	{
		if (cursor->op)
		{
			parse_args_byte_code(vm, cursor);
			if (!validate_instr(vm, cursor))
				g_function[cursor->op_code - 1](vm, cursor);
			else
				cursor->step = get_all_steps(cursor);
			ft_bzero(cursor->args_type, sizeof(int) * 3);
			cursor->op = NULL;
		}
		else
			cursor->step++;
		move_cursor(cursor);
	}
}

void		execute_cursors(t_vm *vm)
{
	t_cursor *cursor;

	vm->total_cycles++;
	vm->cycles_to_check++;
	cursor = vm->cursor;
	while (cursor)
	{
		execute_instruction(vm, cursor);
		cursor = cursor->next;
	}
}

void		play_corewar(t_vm *vm)
{
	if (vm->flag_vs)
		play_visual(vm);
	else
		while (vm->cursors_num > 0)
			play_cycle(vm);
}
