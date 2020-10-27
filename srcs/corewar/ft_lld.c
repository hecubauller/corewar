/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:36:10 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:36:12 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	ft_lld(t_vm *vm, t_cursor *cursor)
{
	int value;
	int id;

	value = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
	cursor->carry = value ? 0 : 1;
	id = get_arg_instr(vm, cursor, cursor->args_type[1], OFF);
	if (is_register(id))
		cursor->reg[id - 1] = value;
}
