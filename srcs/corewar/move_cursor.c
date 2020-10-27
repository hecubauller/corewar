/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:32:03 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:32:06 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int		get_step(t_op *operation, int type_arg)
{
	if (type_arg & T_REG)
		return (BYT_LEN);
	else if (type_arg & T_IND)
		return (IND_SIZE);
	else if (type_arg & T_DIR)
		return (operation->t_dir_size);
	return (0);
}

int		get_all_steps(t_cursor *cursor)
{
	int i;
	int step;

	i = 0;
	step = 0;
	step += OPC_LEN;
	step += cursor->op->args_type_code;
	while (i < cursor->op->args_num)
	{
		step += get_step(cursor->op, cursor->args_type[i]);
		i++;
	}
	return (step);
}

void	move_cursor(t_cursor *cursor)
{
	cursor->pc += cursor->step;
	cursor->pc = MODA(cursor->pc);
	cursor->step = 0;
}
