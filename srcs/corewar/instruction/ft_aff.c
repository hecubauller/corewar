/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:47:22 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/07 20:47:27 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	ft_aff(t_vm *vm, t_cursor *cursor)
{
	char	ch;
	int		id;

	ch = 0;
	id = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
	if (is_register(id) && vm->flags & AFF)
	{
		ch = (char)(cursor->reg[id - 1]);
		if (ft_isascii(ch))
			ft_printf("Aff: %c\n", ch);
	}
}
