/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:16:05 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/07 19:37:05 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static char	*g_error[] = {
	[0] = "ERROR: Invalid number argument",
	[1] = "ERROR: Invalid file champion",
	[2] = "ERROR: No null control bytes",
	[3] = "ERROR: Wrong instruction size",
	[4] = "ERROR: Too many champions",
	[5] = "ERROR: Too large integer",
	[6] = "ERROR: Duplicate flag"
};

void		ft_exit(t_vm *vm, int code)
{
	ft_free(vm);
	if (code == USAGE)
		print_usage();
	else if (errno == 0)
		ft_putendl_fd(g_error[code], STDERR_FILENO);
	else
		perror("ERROR");
	exit(0);
}
