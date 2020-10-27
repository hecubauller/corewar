/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:35:29 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:35:30 by lelida           ###   ########.fr       */
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
