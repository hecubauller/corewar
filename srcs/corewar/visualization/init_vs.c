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

#include "../../../includes/corewar.h"

void		play_visual(t_vm *vm)
{
	int ch;

	while (vm->cursors_num > 0)
	{
		initscr();
		nodelay(stdscr, TRUE);
		ch = getch();
		if (ch == SPACE)
			++vm->pause;
		else if (ch == SPEED_BUTTON)
		{
			if (vm->speed == MAX_SPEED)
				vm->speed = MIN_SPEED;
			else
				vm->speed /= 10;
		}
		else if (ch == MAX_SPEED_BTN)
			vm->speed = MAX_SPEED;
		if (!(vm->pause % 2))
			play_cycle(vm);
		else
			mvwprintw(stdscr, 3, 210, "%s", "Paused ");
	}
}

void		play_cycle(t_vm *vm)
{
	if (vm->dump == vm->total_cycles && \
				(vm->flags & DUMP_32 || vm->flags & DUMP_64))
		print_arena(vm);
	if (vm->flag_vs)
		viz_main(vm);
	execute_cursors(vm);
	if (is_check_cycle(vm))
		check_ctd_and_cursor(vm);
}

void		set_frame(t_vs *vs)
{
	noecho();
	curs_set(0);
	refresh();
	vs->a_frame = newwin(66, 195, 2, 5);
	wattron(vs->a_frame, A_BOLD | A_BLINK);
	box(vs->a_frame, 0, 0);
	wrefresh(vs->a_frame);
}

void		init_pairs(void)
{
	start_color();
	init_pair(CRWR, COLOR_YELLOW, COLOR_BLACK);
	init_pair(ARENA, COLOR_BRIGHT_BLACK, COLOR_BLACK);
	init_pair(DEFAULT_CURSOR, COLOR_BLACK, COLOR_BRIGHT_BLACK);
	init_pair(F_P, COLOR_PINK, COLOR_BLACK);
	init_pair(S_P, COLOR_CYAN, COLOR_BLACK);
	init_pair(T_P, COLOR_GREEN, COLOR_BLACK);
	init_pair(FO_P, COLOR_YELLOW, COLOR_BLACK);
	init_pair(F_P_C, COLOR_BLACK, COLOR_PINK);
	init_pair(S_P_C, COLOR_BLACK, COLOR_CYAN);
	init_pair(T_P_C, COLOR_BLACK, COLOR_GREEN);
	init_pair(FO_P_C, COLOR_BLACK, COLOR_YELLOW);
	init_pair(DEFAULT_TEXT, COLOR_BRIGHT_WHITE, COLOR_BLACK);
	init_pair(EXIT, COLOR_RED, COLOR_BLACK);
}
