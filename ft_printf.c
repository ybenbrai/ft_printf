/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:13:56 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/15 18:37:42 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// function ft_strlen() returns the length of the string s.
int     ft_putnbrDec(int n)
{
    int i;

    i = 0;
    if (n == -2147483648)
    {
        ft_putstr("-2147483648");
        return (11);
    }
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
        i++;
    }
    if (n >= 10)
    {
        i += ft_putnbrDec(n / 10);
        i += ft_putnbrDec(n % 10);
    }
    else
    {
        ft_putchar(n + '0');
        i++;
    }
    return (i);
}

int     ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int     ft_putnbr_base(unsigned long long int n, char *base)
{
    int                     i;
    unsigned long long     len;
    int                     count;

    i = 0;
    count = 0;
    len = ft_strlen(base);
    if (n >= len)
    {
        count += ft_putnbr_base(n / len, base);
        count += ft_putnbr_base(n % len, base);
    }
    else
    {
        write(1, &base[n], 1);
        count++;
    }
    return (count);
}

int   ft_printf(const char *str, ...)
{
    va_list args;
    int     i;
    int     count;

    i = 0;
    count = 0;
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            if(str[i + 1] == '%')
            {
                ft_putchar('%');
                i++;
            }
            else if (str[i + 1] == 'c')
            {
                count += ft_putchar(va_arg(args, int));
                i++;
            }
            else if (str[i + 1] == 's')
            {
                count += ft_putstr(va_arg(args, char *));
                i++;
            }
            else if (str[i + 1] == 'p')
            {
                ft_putstr("0x");
                count += ft_putnbr_base(va_arg(args, unsigned long), "0123456789abcdef");
                // count += ft_putHex(va_arg(args, unsigned int));
                i++;
            }
            else if (str[i + 1] == 'd' || str[i+1] == 'i')
            {
                count += ft_putnbr(va_arg(args, int));
                i++;
            }
            else if(str[i + 1] == 'u')
            {
                // %u Prints an unsigned decimal (base 10) number
                count += ft_putnbrDec(va_arg(args, unsigned int));
                i++;
            }
            else if(str[i + 1] == 'x')
            {
                count += ft_putHexLow(va_arg(args, unsigned int));
                i++;
            }
            else if(str[i + 1] == 'X')
            {
                count += ft_putHexUp(va_arg(args, unsigned int));
                i++;
            }
        }
        else
            count += ft_putchar(str[i]);
        i++;
    }
    va_end(args);
    return (count);
}