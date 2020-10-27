/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 20:33:38 by huller            #+#    #+#             */
/*   Updated: 2020/10/09 20:34:50 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static int		get_speed(t_vm *vm)
{
	if (vm->speed == MIN_SPEED)
		return (1);
	else if (vm->speed == MIN_SPEED / 10)
		return (2);
	else if (vm->speed == MIN_SPEED / 100)
		return (3);
	return (4);
}

static void		print_static_info(t_vm *vm, const t_vs *vs)
{
	int	i;

	i = 2;
	wattron(vs->bar, COLOR_PAIR(DEFAULT_TEXT));
	mvwprintw(vs->bar, i, 0, "%s %d", "Cycle:        	 ", vm->total_cycles);
	mvwprintw(vs->bar, ++i, 0, "%s %d", "Cursors:         ", vm->cursors_num);
	mvwprintw(vs->bar, ++i, 0, "%s %d", "Speed:           ", get_speed(vm));
	mvwprintw(vs->bar, ++i, 0, "%s %d %s", "Cycles to die:   ",
			vm->cycles_to_die, "       ");
	mvwprintw(vs->bar, ++i, 0, "%s %d %s", "Cycles to check: ",
			vm->cycles_to_check, "       ");
	wattroff(vs->bar, COLOR_PAIR(DEFAULT_TEXT));
}

void			print_last_live(const t_vm *vm, const t_vs *vs, int i, int cnt)
{
	static t_player *last_live_name;

	if (vm->total_cycles == 0)
		mvwprintw(vs->bar, cnt + 9, 12, "%d", vm->total_cycles);
	if (vm->last_alive->name == vm->players[i]->name &&\
		vm->last_alive != last_live_name)
	{
		mvwprintw(vs->bar, cnt + 9, 12, "%d", vm->total_cycles);
		last_live_name = vm->last_alive;
	}
}

void			print_bar(t_vm *vm, t_vs *vs)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	print_intro(vs);
	while (vm->players[i] && i < 4)
	{
		wattron(vs->bar, COLOR_PAIR(DEFAULT_TEXT));
		mvwprintw(vs->bar, cnt + 8, 0, "%s %d%c", "Player",\
				vm->players[i]->id, ':');
		mvwprintw(vs->bar, cnt + 9, 0, "%s", "Last live:");
		wattroff(vs->bar, COLOR_PAIR(DEFAULT_TEXT));
		wattron(vs->bar, COLOR_PAIR(vm->players[i]->id));
		mvwprintw(vs->bar, cnt + 8, 10, "%s", vm->players[i]->name);
		print_last_live(vm, vs, i, cnt);
		wattroff(vs->bar, COLOR_PAIR(vm->players[i]->id));
		cnt += 3;
		++i;
	}
	print_static_info(vm, vs);
}

void			print_help(t_vs *vs)
{
	int	i;

	i = 20;
	wattron(vs->bar, COLOR_PAIR(CRWR));
	mvwprintw(vs->bar, i, 0, "HELP");
	wattroff(vs->bar, COLOR_PAIR(CRWR));
	wattron(vs->bar, COLOR_PAIR(DEFAULT_TEXT));
	mvwprintw(vs->bar, ++i, 0, "............................");
	mvwprintw(vs->bar, ++i, 0, "Play/Pause:   'Space'");
	mvwprintw(vs->bar, ++i, 0, "Change Speed: 'S'");
	mvwprintw(vs->bar, ++i, 0, "MAX Speed:    'M'");
	mvwprintw(vs->bar, ++i, 0, "............................");
	wattroff(vs->bar, COLOR_PAIR(DEFAULT_TEXT));
	wattron(vs->bar, COLOR_PAIR(EXIT));
	mvwprintw(vs->bar, ++i, 0, "Exit:         'Ctrl + C'");
	wattroff(vs->bar, COLOR_PAIR(EXIT));
}
