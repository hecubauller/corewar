/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:46:06 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/07 20:46:13 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	ft_add(t_vm *vm, t_cursor *cursor)
{
	int id_1;
	int id_2;
	int id_3;
	int result;

	result = 0;
	id_1 = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
	id_2 = get_arg_instr(vm, cursor, cursor->args_type[1], OFF);
	if (is_register(id_1) && is_register(id_2))
	{
		result = cursor->reg[id_1 - 1] + cursor->reg[id_2 - 1];
		id_3 = get_arg_instr(vm, cursor, cursor->args_type[2], OFF);
		if (is_register(id_3))
			cursor->reg[id_3 - 1] = result;
		cursor->carry = result ? 0 : 1;
	}
}
