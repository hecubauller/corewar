/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:17:00 by lelida            #+#    #+#             */
/*   Updated: 2020/10/24 13:17:02 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	unsigned_nbr(t_param *param, va_list args)
{
	int len;

	if (param->modifier & H)
		len = print_unsigned((unsigned short)va_arg(args, unsigned int), param);
	else if (param->modifier & HH)
		len = print_unsigned((unsigned char)va_arg(args, unsigned int), param);
	else if (param->modifier & L)
		len = print_unsigned(va_arg(args, unsigned long), param);
	else if (param->modifier & LL)
		len = print_unsigned(va_arg(args, unsigned long long), param);
	else
		len = print_unsigned(va_arg(args, unsigned int), param);
	return (len);
}

static int	signed_nbr(t_param *param, va_list args)
{
	int len;

	len = 0;
	if (param->modifier & H)
		len = print_signed((short)va_arg(args, int), param);
	else if (param->modifier & HH)
		len = print_signed((char)va_arg(args, int), param);
	else if (param->modifier & L)
		len = print_signed(va_arg(args, long), param);
	else if (param->modifier & LL)
		len = print_signed(va_arg(args, long long), param);
	else
		len = print_signed(va_arg(args, int), param);
	return (len);
}

int			print_decimal(t_param *param, va_list args)
{
	int len;

	len = 0;
	if (param->specifier == 'd' || param->specifier == 'i')
		len = signed_nbr(param, args);
	else if (param->specifier == 'u')
		len = unsigned_nbr(param, args);
	return (len);
}
