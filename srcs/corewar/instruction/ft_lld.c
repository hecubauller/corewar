/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:55:43 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/07 20:55:50 by gartanis         ###   ########.fr       */
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
