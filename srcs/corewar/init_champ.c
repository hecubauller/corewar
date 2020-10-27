/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:31:06 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:31:08 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static void	swap_champion(t_player **p1, t_player **p2)
{
	t_player *tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void		update_champion_id(t_vm *vm)
{
	int max_id;
	int i;

	i = -1;
	max_id = 0;
	while (++i < vm->players_num)
		if (max_id < vm->players[i]->id)
			max_id = vm->players[i]->id;
	if (max_id > vm->players_num)
		ft_exit(vm, 0);
	i = -1;
	while (++i < vm->players_num)
		if (vm->players[i]->id > 0 && vm->players[i]->id != i + 1)
			swap_champion(&vm->players[i], \
					&vm->players[vm->players[i]->id - 1]);
	i = -1;
	while (++i < vm->players_num)
		if (vm->players[i]->id == 0)
			vm->players[i]->id = i + 1;
	vm->last_alive = vm->players[vm->players_num - 1];
}

void		add_champion(t_vm *vm, t_player *player)
{
	int i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (vm->players[i] == NULL)
		{
			vm->players[i] = player;
			break ;
		}
		i++;
	}
	if (++vm->players_num > MAX_PLAYERS)
		ft_exit(vm, 4);
}

t_player	*creat_champion(int id)
{
	t_player *player;

	if (!(player = malloc(sizeof(t_player))))
		return (NULL);
	player->id = id;
	player->isntr_size = 0;
	ft_bzero(player->name, sizeof(char) * PROG_NAME_LENGTH);
	ft_bzero(player->comment, sizeof(char) * COMMENT_LENGTH);
	ft_bzero(player->instr, sizeof(char) * CHAMP_MAX_SIZE);
	player->next = NULL;
	return (player);
}
