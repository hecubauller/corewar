/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:59:24 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/07 20:59:37 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	ft_st(t_vm *vm, t_cursor *cursor)
{
	int addres;
	int value;
	int id;

	vm->tmp_cursor = cursor;
	value = 0;
	id = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
	if (is_register(id))
		value = cursor->reg[id - 1];
	if (cursor->args_type[1] & T_REG)
	{
		id = get_arg_instr(vm, cursor, cursor->args_type[1], OFF);
		cursor->reg[id - 1] = value;
	}
	else if (cursor->args_type[1] & T_IND)
	{
		addres = bytecode_arg_to_int(vm, cursor->pc + cursor->step, IND_SIZE);
		set_int_by_addres(vm, cursor->pc + MODX(addres), value, REG_SIZE);
		cursor->step += get_step(cursor->op, cursor->args_type[1]);
	}
}
