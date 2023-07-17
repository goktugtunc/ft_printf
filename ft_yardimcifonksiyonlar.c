/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yardimcifonksiyonlar.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:05:08 by gotunc            #+#    #+#             */
/*   Updated: 2023/07/17 06:58:10 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	intlen(long d)
{
	int	i;

	i = 0;
	if (d == 0)
		return (1);
	if (d < 0)
		i++;
	while (d != 0)
	{
		d /= 10;
		i++;
	}
	return (i);
}

int	numberlen(long n)
{
	long	a;
	int		i;

	i = 0;
	a = n;
	if (a == 0)
		return (1);
	if (a < 0)
	{
		a *= -1;
		i++;
	}
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

void	putstring(char *string, long a, int numlen)
{
	long	n;

	n = a;
	if (n < 0)
	{
		string[0] = '-';
		n *= -1;
	}
	if (n >= 10)
	{
		putstring(string, n / 10, numlen - 1);
		putstring(string, n % 10, numlen);
	}
	if (n < 10)
		string[numlen] = n + 48;
}

char	*ft_itoa(long n)
{
	int		numlen;
	char	*string;

	numlen = numberlen(n);
	string = malloc((sizeof(char) * numlen) + 1);
	if (!string)
		return (0);
	putstring(string, n, numlen - 1);
	string[numlen] = '\0';
	return (string);
}
