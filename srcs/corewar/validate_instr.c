/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:33:33 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:33:35 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static int	check_args_types(t_cursor *cursor)
{
	int i;

	i = 0;
	while (i < cursor->op->args_num)
	{
		if (!(cursor->args_type[i] & cursor->op->args_type[i]))
			return (ERRABC);
		i++;
	}
	return (0);
}

static int	check_args(t_vm *vm, t_cursor *cursor)
{
	int value;
	int step;
	int i;

	i = 0;
	step = cursor->step;
	while (i < cursor->op->args_num)
	{
		if (cursor->args_type[i] & T_REG)
		{
			value = get_byte(vm, cursor->pc + step);
			if (!is_register(value))
				return (ERRARG);
		}
		step += get_step(cursor->op, cursor->args_type[i]);
		i++;
	}
	return (0);
}

int			validate_instr(t_vm *vm, t_cursor *cursor)
{
	int ret;

	ret = 0;
	ret = check_args(vm, cursor);
	ret += check_args_types(cursor);
	return (ret);
}
