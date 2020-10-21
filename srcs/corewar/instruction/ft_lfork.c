/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:52:51 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/07 20:53:00 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	ft_lfork(t_vm *vm, t_cursor *cursor)
{
	t_cursor	*new_cursor;
	int			addres;

	addres = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
	new_cursor = push_top_cursor(vm);
	copy_cursor(new_cursor, cursor);
	new_cursor->id = ++id_cursors;
	new_cursor->pc = MODA((cursor->pc + addres));
}
