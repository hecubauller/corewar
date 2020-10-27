/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:37:07 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:37:14 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	ft_zjmp(t_vm *vm, t_cursor *cursor)
{
	int addres;

	addres = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
	if (cursor->carry == 1)
	{
		addres = MODX(addres);
		cursor->pc = MODA((cursor->pc + addres));
		cursor->step = 0;
	}
}
