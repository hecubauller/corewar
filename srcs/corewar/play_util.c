/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:36:46 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/07 20:36:50 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static int	is_operation(int op_code)
{
	return (op_code >= 0x01 && op_code <= 0x10);
}

int			is_register(int reg_id)
{
	return (reg_id >= 0x01 && reg_id <= 0x10);
}

int8_t		get_byte(t_vm *vm, int index)
{
	return (vm->arena[MODA(index)]);
}

int			get_operation(t_vm *vm, t_cursor *cursor)
{
	int code;

	cursor->op = NULL;
	code = get_byte(vm, cursor->pc);
	if (is_operation(code))
	{
		cursor->op_code = code;
		cursor->op = &vm->op_tab[code - 1];
		cursor->cycles_to_exec = cursor->op->cycles;
		cursor->step += OPC_LEN;
		return (code);
	}
	return (0);
}
