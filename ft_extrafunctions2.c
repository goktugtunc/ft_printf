/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yardimcifonksiyon2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 06:27:44 by gotunc            #+#    #+#             */
/*   Updated: 2023/07/17 08:46:32 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	decimallen(unsigned long long d)
{
	int	i;

	i = 0;
	if (d == 0)
		return (1);
	while (d != 0)
	{
		d /= 16;
		i++;
	}
	return (i);
}

int	hextodecimal(unsigned long long d, char x, char *y, int w)
{
	unsigned long long	c;
	int					i;
	char				*t;

	i = decimallen(d);
	c = 0;
	t = malloc(sizeof(char) * i + 1);
	if (!t)
		return (0);
	t[i] = 0;
	if (d == 0)
		t[0] = '0';
	while (i > 0)
	{
		c = d % 16;
		d /= 16;
		t[i - 1] = y[c];
		i--;
	}
	if (x == 'p')
		write(1, "0x", 2);
	write(1, t, ft_strlen(t));
	c = ft_strlen(t);
	free(t);
	return (c + w);
}
