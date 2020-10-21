/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_abc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:05:15 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/07 20:05:17 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static int	get_type_arg(int type_code)
{
	if (type_code == REG_CODE)
		return (T_REG);
	else if (type_code == DIR_CODE)
		return (T_DIR);
	else if (type_code == IND_CODE)
		return (T_IND);
	return (0);
}

static void	set_type_args(t_cursor *cursor, uint8_t args_byte_code)
{
	uint8_t	abc;
	int		i;

	i = 0;
	abc = args_byte_code;
	while (i < cursor->op->args_num)
	{
		if (i == 0)
			cursor->args_type[i] = get_type_arg(((abc & 0xC0) >> 6));
		else if (i == 1)
			cursor->args_type[i] = get_type_arg(((abc & 0x30) >> 4));
		else if (i == 2)
			cursor->args_type[i] = get_type_arg(((abc & 0x0C) >> 2));
		i++;
	}
}

void		parse_args_byte_code(t_vm *vm, t_cursor *cursor)
{
	int code;

	code = cursor->op_code - 1;
	if (cursor->op->args_type_code == 1)
	{
		set_type_args(cursor, get_byte(vm, cursor->pc + cursor->step));
		cursor->step += 1;
	}
	else
		cursor->args_type[0] = cursor->op->args_type[0];
}
