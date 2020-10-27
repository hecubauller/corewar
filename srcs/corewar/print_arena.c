/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 20:33:38 by huller            #+#    #+#             */
/*   Updated: 2020/10/09 20:34:50 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static int		define_curs_color(t_vm *vm, int i)
{
	if (vm->color_arena[i] == 5)
		return (DEFAULT_CURSOR);
	else if (vm->color_arena[i] == 1)
		return (F_P_C);
	else if (vm->color_arena[i] == 2)
		return (S_P_C);
	else if (vm->color_arena[i] == 3)
		return (T_P_C);
	return (FO_P_C);
}

static void		print_byte(t_vs *vs, int attrs, uint8_t byte)
{
	wattron(vs->arena, COLOR_PAIR(attrs));
	mvwprintw(vs->arena, vs->y, vs->x, "%.2x", byte);
	wattroff(vs->arena, COLOR_PAIR(attrs));
	mvwprintw(vs->arena, vs->y, vs->x + 2, " ");
}

void			init_clr_aren(t_vm *vm)
{
	int	i;
	int cnt;

	i = 0;
	cnt = -1;
	while (i < vm->players_num)
	{
		while (++cnt < MEM_SIZE && cnt >= vm->players[i]->location && \
			cnt < (vm->players[i]->location + vm->players[i]->isntr_size))
			vm->color_arena[cnt] = vm->players[i]->id;
		i++;
		if (i < vm->players_num)
			cnt = vm->players[i]->location - 1;
	}
}

void			print_carry(t_vm *vm, t_vs *vs)
{
	t_cursor	*beginning;

	beginning = vm->cursor;
	while (vm->cursor)
	{
		vs->y = vm->cursor->pc / (192 / 3);
		vs->x = 3 * (vm->cursor->pc % (192 / 3));
		print_byte(vs, define_curs_color(vm, vm->cursor->pc),
				vm->arena[vm->cursor->pc]);
		if (vm->cursor->next)
			vm->cursor = vm->cursor->next;
		else
			break ;
	}
	vm->cursor = beginning;
}

void			print_aren(t_vm *vm, t_vs *vs)
{
	int			i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		vs->y = i / (192 / 3);
		vs->x = 3 * (i % (192 / 3));
		print_byte(vs, vm->color_arena[i], vm->arena[i]);
	}
	print_carry(vm, vs);
}
