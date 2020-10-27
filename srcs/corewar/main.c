/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:31:55 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:31:57 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int	main(int argc, char **argv)
{
	t_vm vm;

	if (argc < 2)
		ft_exit(&vm, USAGE);
	init_vm(&vm);
	set_op_tab(&vm);
	ft_parse_args(&vm, argv);
	init_arena(&vm);
	init_cursor(&vm);
	intro_player(&vm);
	play_corewar(&vm);
	endwin();
	print_winner(&vm);
	ft_free(&vm);
	return (EXIT_SUCCESS);
}
