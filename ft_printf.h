/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:21:01 by gotunc            #+#    #+#             */
/*   Updated: 2023/08/15 23:50:47 by gotunc           ###   ########.fr       */
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
int		printstring(char *d, char c, char m);
int		printdecimal(double d);
int		printpercent(void);
int		numberlen(long n);
int		ft_strlen(char *s);
int		intlen(long d);
void	putstring(char *string, long a, int numlen);
int		printunsigned(unsigned int d);
int		hextodecimal(unsigned long long d, char x, char *y, int w);
int		printadress(unsigned long long d, char x, char *y, int w);

#endif
