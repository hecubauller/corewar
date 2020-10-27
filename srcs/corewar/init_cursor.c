/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:31:41 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:31:43 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void		copy_cursor(t_cursor *dst, t_cursor *src)
{
	dst->carry = src->carry;
	dst->cycles_to_exec = 0;
	dst->last_live = src->last_live;
	dst->op_code = 0;
	ft_memcpy(dst->reg, src->reg, sizeof(int) * REG_NUMBER);
	ft_bzero(dst->args_type, sizeof(int) * 3);
	dst->op = NULL;
	dst->step = 0;
	dst->clr = src->clr;
}

void		fill_cursor(t_cursor *new, int addres, int id_player)
{
	new->carry = 0;
	new->cycles_to_exec = 0;
	new->id = ++g_id_cursors;
	new->last_live = 0;
	new->op_code = 0;
	new->pc = addres;
	new->op = NULL;
	ft_bzero(new->reg, sizeof(int) * REG_NUMBER);
	ft_bzero(new->args_type, sizeof(int) * 3);
	new->reg[0] = -(id_player);
	new->step = 0;
}

t_cursor	*push_top_cursor(t_vm *vm)
{
	t_cursor *new_cursor;

	if (!(new_cursor = malloc(sizeof(t_cursor))))
		ft_exit(vm, errno);
	new_cursor->next = vm->cursor;
	vm->cursor = new_cursor;
	vm->cursors_num++;
	return (new_cursor);
}

void		init_cursor(t_vm *vm)
{
	t_cursor	*tmp;
	int			i;

	i = 0;
	g_id_cursors = 0;
	while (i < vm->players_num)
	{
		tmp = push_top_cursor(vm);
		fill_cursor(tmp, vm->players[i]->location, vm->players[i]->id);
		tmp->clr = vm->players[i]->id;
		i++;
	}
}
