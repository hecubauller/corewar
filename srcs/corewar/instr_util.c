/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:37:23 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:37:25 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static void	bytecode_read(t_vm *vm, int pc, uint8_t *buf, int size)
{
	int i;

	i = -1;
	while (++i < size)
		buf[i] = get_byte(vm, pc + i);
}

int			bytecode_arg_to_int(t_vm *vm, int pc, int size)
{
	uint8_t	buffer[size];
	int		result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	bytecode_read(vm, pc, buffer, size);
	sign = buffer[0] & 0x80;
	while (i < size)
		result = result * 256 + (sign ? buffer[i++] ^ 0xff : buffer[i++]);
	return (sign ? ~result : result);
}

void		set_int_by_addres(t_vm *vm, int addres, int value, int size)
{
	uint8_t	*ptr;
	int		i;

	i = size;
	ptr = (uint8_t *)&value;
	while (--i >= 0)
	{
		vm->arena[MODA((addres + i))] = *ptr++;
		vm->color_arena[MODA((addres + i))] = vm->tmp_cursor->clr;
	}
}

int			get_arg_instr(t_vm *vm, t_cursor *cursor, int t_arg, int idx_mod)
{
	int		value;
	int16_t	addres;

	value = 0;
	if (t_arg & T_REG)
		value = bytecode_arg_to_int(vm, cursor->pc + cursor->step, 1);
	else if (t_arg & T_DIR)
		value = bytecode_arg_to_int(vm, cursor->pc + cursor->step, \
				cursor->op->t_dir_size);
	else if (t_arg & T_IND)
	{
		addres = bytecode_arg_to_int(vm, cursor->pc + cursor->step, IND_SIZE);
		addres = idx_mod ? MODX(addres) : addres;
		value = bytecode_arg_to_int(vm, cursor->pc + addres, REG_SIZE);
	}
	cursor->step += get_step(cursor->op, t_arg);
	return (value);
}
