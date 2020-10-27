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

void			print_intro(t_vs *vs)
{
	mvwprintw(vs->bar, 0, 0, "%s", "Playing ");
	wattron(vs->bar, COLOR_PAIR(CRWR));
	mvwprintw(vs->bar, 0, 8, "%s", "COREWAR");
	wattroff(vs->bar, COLOR_PAIR(CRWR));
}

static void		refresh_w(t_vs *vs)
{
	wrefresh(vs->arena);
	wrefresh(vs->bar);
}

void			viz_main(t_vm *vm)
{
	static t_vs	vs;

	if (vm->is_init_viz == 0)
	{
		vs.x = 0;
		vs.y = 0;
		vs.a_frame = NULL;
		vs.arena = NULL;
		vs.bar = NULL;
		set_frame(&vs);
		init_pairs();
		vs.arena = newwin(64, 192, 3, 7);
		vs.bar = newwin(64, 47, 3, 210);
		print_help(&vs);
		init_clr_aren(vm);
		vm->is_init_viz = 1;
	}
	refresh_w(&vs);
	print_aren(vm, &vs);
	print_bar(vm, &vs);
	refresh_w(&vs);
	usleep(vm->speed);
}
