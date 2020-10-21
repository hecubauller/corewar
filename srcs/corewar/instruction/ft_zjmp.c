/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:04:03 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/07 21:04:08 by gartanis         ###   ########.fr       */
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
