/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:07:11 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/07 20:07:15 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static void	parse_filename(t_vm *vm, char ***av)
{
	int id;

	id = 0;
	if (!ft_strcmp("-n", (*av)[0]))
	{
		if ((id = parse_id_champ(vm, (*av)[1])) && is_extension((*av)[2], EXT))
			parse_champion(vm, (*av)[2], id);
		else
			ft_exit(vm, 1);
		(*av) += 3;
		return ;
	}
	else
		parse_champion(vm, (*av)[0], id);
	(*av) += 1;
}

void		ft_parse_args(t_vm *vm, char **av)
{
	av++;
	while (*av)
	{
		if (!ft_strcmp("-dump", av[0]) && av[1])
			parse_dump(vm, &av);
		else if (!ft_strcmp("-d", av[0]) && av[1])
			parse_dump(vm, &av);
		else if (!ft_strcmp("-a", av[0]))
			parse_aff(vm, &av);
		else if (!ft_strcmp("-n", av[0]) && av[1] && av[2])
			parse_filename(vm, &av);
		else if (!ft_strcmp("-v", av[0]) && av[1])
		{
			vm->flag_vs = 1;
			av += 1;
			printf("hui");
		}
		else if (is_extension(av[0], EXT))
			parse_filename(vm, &av);
		else
			ft_exit(vm, USAGE);
	}
	update_champion_id(vm);
}
