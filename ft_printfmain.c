
#include "library.h"
#include "libft.h"
/*
int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}*/
int stringyazdir(char *d)
{
    write(1, d, ft_strlen(d));
    return (ft_strlen(d));
}

int charyazdir(int d)
{
    char c;

    c = d;
    write(1, &c, 1);
    return (1);
}

int intlen(long d)
{
    int i;

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
/*
int adresyazdir(void *d)
{
    write(1, &d, intlen(d));
    return (intlen(d));
}
*/
int doubleyazdir(double d)
{
    char *c;
    c = ft_itoa(d);
    write(1, c, ft_strlen(c));
    return (ft_strlen(c));
}
/*
int unsignedyazdir(unsigned long int d)
{
    write(1, &d, intlen(d));
    return (intlen(d));
}

int yuzdeyazdir()
{
    write(1, "%", 1);
    return (1);
}

int integeryazdir(int d)
{
    write(1, &d, intlen(d));
    return (intlen(d));
}
*/
int ft_printf(const char *s, ...)
{
    va_list d;
    int     i;
    int     len;

    i = 0;
    len = 0;
    va_start(d, s);
    while (s[i])
    {
        if (s[i] == '%' && s[i+1])
        {
            if (s[i+1] == 's')
                len += stringyazdir(va_arg(d, char *));
            else if (s[i+1] == 'c')
                len += charyazdir(va_arg(d, int));
            //else if (s[i+1] == 'p')
            //    len += adresyazdir(va_arg(d, void *));
            else if (s[i+1] == 'd')
                len += doubleyazdir(va_arg(d, double));
            //else if (s[i+1] == 'i')
            //    len += integeryazdir(va_arg(d, int));
            //else if (s[i+1] == 'u')
            //    len += unsignedyazdir(va_arg(d, unsigned long int));
            //else if (s[i+1] == 'x')
            //    len += kucukxyazdir();
            //else if (s[i+1] == 'X')
            //    len += buyukxyazdir();
            //else if (s[i+1] == '%')
            //    len += yuzdeyazdir();
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