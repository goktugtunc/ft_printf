/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:15:26 by gotunc            #+#    #+#             */
/*   Updated: 2023/07/17 08:55:53 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	adresyazdir(unsigned long long d, char x, char *y, int w)
{
	int	i;

	i = hextodecimal(d, x, y, w);
	return (i);
}

int	unsignedyazdir(unsigned int d)
{
	char	*c;
	int		len;

	c = ft_itoa(d);
	len = ft_strlen(c);
	write(1, c, len);
	free(c);
	return (len);
}

int	doubleyazdir(double d)
{
	char	*c;
	int		m;

	m = 0;
	c = ft_itoa(d);
	m = ft_strlen(c);
	write(1, c, m);
	free(c);
	return (m);
}

int	stringyazdir(char *d, char c, char m)
{
	if (m == 's')
	{
		if (d == NULL)
		{
			write(1, "(null)", 6);
			return (6);
		}
		write(1, d, ft_strlen(d));
		return (ft_strlen(d));
	}
	else
		write(1, &c, 1);
	return (1);
}

int	yuzdeyazdir(void)
{
	char	d;

	d = '%';
	write(1, &d, 1);
	return (1);
}
