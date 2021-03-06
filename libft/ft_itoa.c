/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:30:27 by lelida            #+#    #+#             */
/*   Updated: 2020/10/24 13:30:29 by lelida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	size_t	ft_nbrlen(int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < i)
		i++;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t	i;
	size_t	n_size;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_size = ft_nbrlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (n_size + 1))))
		return (NULL);
	str[n_size] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i += 1;
	}
	while (i < n_size--)
	{
		str[n_size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
