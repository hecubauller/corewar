/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:35:36 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:35:38 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	ft_ldi(t_vm *vm, t_cursor *cursor)
{
	int addres;
	int value_1;
	int value_2;
	int id;

	value_1 = get_arg_instr(vm, cursor, cursor->args_type[0], ON);
	value_2 = get_arg_instr(vm, cursor, cursor->args_type[1], OFF);
	if (cursor->args_type[0] & T_REG && is_register(value_1))
		value_1 = cursor->reg[value_1 - 1];
	if (cursor->args_type[1] & T_REG && is_register(value_2))
		value_2 = cursor->reg[value_2 - 1];
	id = get_arg_instr(vm, cursor, cursor->args_type[2], OFF);
	if (is_register(id))
	{
		addres = cursor->pc + MODX((value_1 + value_2));
		cursor->reg[id - 1] = bytecode_arg_to_int(vm, MODA(addres), REG_SIZE);
	}
}
