/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:36:55 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:36:56 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	ft_sub(t_vm *vm, t_cursor *cursor)
{
	int sum;
	int id[3];

	sum = 0;
	id[0] = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
	id[1] = get_arg_instr(vm, cursor, cursor->args_type[1], OFF);
	if (is_register(id[0]) && is_register(id[1]))
	{
		sum = cursor->reg[id[0] - 1] - cursor->reg[id[1] - 1];
		id[2] = get_arg_instr(vm, cursor, cursor->args_type[2], OFF);
		if (is_register(id[2]))
			cursor->reg[id[2] - 1] = sum;
		cursor->carry = sum ? 0 : 1;
	}
}
