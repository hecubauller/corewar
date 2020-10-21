/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:39:20 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/07 20:39:22 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	print_winner(t_vm *vm)
{
	if (vm->last_alive)
	{
		ft_printf("Contestant %d, \"%s\", has won !\n", \
		vm->last_alive->id, vm->last_alive->name);
	}
}

void	print_arena(t_vm *vm)
{
	int	octets;
	int	line;
	int	i;

	i = 0;
	line = 0;
	octets = (vm->flags & DUMP_32 ? 32 : 64);
	ft_printf("0x%.4x : ", 0);
	while (i < MEM_SIZE)
	{
		ft_printf("%.2x ", vm->arena[i]);
		if (!(++i % octets) && i != MEM_SIZE)
			ft_printf("\n%#.4x : ", (line += octets));
	}
	ft_printf("\n");
	ft_free(vm);
	exit(0);
}

void	intro_player(t_vm *vm)
{
	int i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < vm->players_num)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", \
		vm->players[i]->id, vm->players[i]->isntr_size, \
		vm->players[i]->name, vm->players[i]->comment);
		i++;
	}
}

void	print_usage(void)
{
	ft_printf("USAGE: ./corewar [options] <input champion*.cor>\n\n");
	ft_printf("OPTIONS:\n");
	ft_printf("%7s\t\t%s\n", "-a  ", "- Prints output from \"aff\"");
	ft_printf("%7s\t\t%s\n", "-n N", "- Set champion id number");
	ft_printf("%7s\t\t%s\n", "-v  ", "- Use visualization");
	ft_printf("%7s\t\t%s\n", "-d N", \
	"- Dumps memory (64 octets) after N cycles then exits");
	ft_printf("%10s\t%s\n", "-dump N", \
	"- Dumps memory (32 octets) after N cycles then exits");
}
