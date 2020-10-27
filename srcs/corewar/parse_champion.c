/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:32:50 by lelida            #+#    #+#             */
/*   Updated: 2020/10/22 13:32:52 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static int	bytecode_to_int(uint8_t *buffer, int size)
{
	int result;
	int sign;
	int i;

	i = 0;
	result = 0;
	sign = buffer[0] & 0x80;
	while (i < size)
		result = result * 256 + (sign ? buffer[i++] ^ 0xff : buffer[i++]);
	return (sign ? ~result : result);
}

static void	parse_instr(t_vm *vm, uint8_t *dst, int fd, int size)
{
	int		ret;
	uint8_t	byte;

	if ((ret = read(fd, dst, size)) == -1)
		ft_exit(vm, errno);
	if (ret < size)
		ft_exit(vm, 1);
	else if (read(fd, &byte, 1) != 0)
		ft_exit(vm, 1);
}

static void	parse_string(t_vm *vm, char *dst, int fd, int size)
{
	int ret;

	if ((ret = read(fd, dst, size)) == -1)
		ft_exit(vm, errno);
	if (ret < size)
		ft_exit(vm, 1);
	dst[ret] = '\0';
}

static int	parse_4byte(t_vm *vm, int fd)
{
	uint8_t	buffer[4];
	int		ret;

	if ((ret = read(fd, buffer, 4)) == -1)
		ft_exit(vm, errno);
	if (ret < 4)
		ft_exit(vm, 1);
	return (bytecode_to_int(buffer, 4));
}

void		parse_champion(t_vm *vm, char *file, int id)
{
	t_player	*player;
	int			fd;

	if (!(player = creat_champion(id)))
		ft_exit(vm, 0);
	add_champion(vm, player);
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit(vm, errno);
	if (parse_4byte(vm, fd) != COREWAR_EXEC_MAGIC)
		ft_exit(vm, 1);
	parse_string(vm, player->name, fd, PROG_NAME_LENGTH);
	if (parse_4byte(vm, fd) != 0)
		ft_exit(vm, 2);
	if ((player->isntr_size = parse_4byte(vm, fd)) > CHAMP_MAX_SIZE)
		ft_exit(vm, 1);
	if (player->isntr_size < 0 || player->isntr_size > CHAMP_MAX_SIZE)
		ft_exit(vm, 3);
	parse_string(vm, player->comment, fd, COMMENT_LENGTH);
	if (parse_4byte(vm, fd) != 0)
		ft_exit(vm, 2);
	parse_instr(vm, player->instr, fd, player->isntr_size);
}
