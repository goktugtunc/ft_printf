/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfmain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:23:19 by gotunc            #+#    #+#             */
/*   Updated: 2023/07/17 09:26:47 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	kararmekanizmasi(char s, va_list c)
{
	int	len;

	len = 0;
	if (s == 's')
		len += stringyazdir(va_arg(c, char *), 's', 's');
	else if (s == 'c')
		len += stringyazdir("", (char)va_arg(c, int), 'c');
	else if (s == 'p')
		len += adresyazdir((unsigned long long)va_arg(c, void *), 'p', SHEX, 2);
	else if (s == 'i' || s == 'd')
		len += doubleyazdir(va_arg(c, int));
	else if (s == 'u')
		len += unsignedyazdir(va_arg(c, unsigned int));
	else if (s == 'x')
		len += adresyazdir((unsigned int)va_arg(c, void *), 'x', SHEX, 0);
	else if (s == 'X')
		len += adresyazdir((unsigned int)va_arg(c, void *), 'X', BHEX, 0);
	else if (s == '%')
		len += yuzdeyazdir();
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	d;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(d, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			len += kararmekanizmasi(s[i + 1], d);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}
