/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:50:41 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/07 20:50:44 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	ft_ld(t_vm *vm, t_cursor *cursor)
{
	int value;
	int id;

	value = 0;
	value = get_arg_instr(vm, cursor, cursor->args_type[0], ON);
	cursor->carry = (value == 0) ? 1 : 0;
	id = get_arg_instr(vm, cursor, cursor->args_type[1], OFF);
	if (is_register(id))
		cursor->reg[id - 1] = value;
}
