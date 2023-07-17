/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:21:01 by gotunc            #+#    #+#             */
/*   Updated: 2023/07/17 08:56:52 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define SHEX "0123456789abcdef"
# define BHEX "0123456789ABCDEF"

int		ft_printf(const char *s, ...);
char	*ft_itoa(long n);
int		stringyazdir(char *d, char c, char m);
int		doubleyazdir(double d);
int		yuzdeyazdir(void);
int		numberlen(long n);
int		ft_strlen(char *s);
int		intlen(long d);
void	putstring(char *string, long a, int numlen);
int		unsignedyazdir(unsigned int d);
int		hextodecimal(unsigned long long d, char x, char *y, int w);
int		adresyazdir(unsigned long long d, char x, char *y, int w);

#endif
