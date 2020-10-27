/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:33:01 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:33:03 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int		parse_id_champ(t_vm *vm, char *av)
{
	int id;

	id = 0;
	if (!is_number(av))
		ft_exit(vm, 0);
	id = ft_atoi(av);
	if (!(id > 0 && id < 5) || vm->id & FT_BIT(id))
		ft_exit(vm, 0);
	vm->id |= FT_BIT(id);
	return (id);
}

void	parse_dump(t_vm *vm, char ***av)
{
	int res;

	res = 0;
	if (vm->flags & DUMP_32 || vm->flags & DUMP_64)
		ft_exit(vm, 6);
	if (!is_number((*av)[1]))
		ft_exit(vm, 0);
	if (!(res = ft_atoi((*av)[1])) && ft_strlen((*av)[1]) > 1)
		ft_exit(vm, 5);
	vm->flags |= (!ft_strcmp("-dump", (*av)[0]) ? DUMP_32 : DUMP_64);
	vm->dump = res;
	(*av) += 2;
}

void	parse_aff(t_vm *vm, char ***av)
{
	if (vm->flags & AFF)
		ft_exit(vm, 6);
	vm->flags |= AFF;
	(*av) += 1;
}
