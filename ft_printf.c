/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:13:56 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/15 16:48:36 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// function to check if the argument contain errors in format



int   ft_printf(char *str, ...)
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
                return (0);
            }
            if (str[i + 1] == 'c')
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
                count += ft_putHex(va_arg(args, unsigned int));
                i++;
            }
            else if (str[i + 1] == 'd')
            {
                count += ft_putnbr(va_arg(args, int));
                i++;
            }
            else if(str[i + 1] == 'i')
            {
                count += ft_putDec(va_arg(args, int));
                i++;
            }
            else if(str[i + 1] == 'u')
            {
                count += ft_putnbr(va_arg(args, unsigned int));
                i++;
            }
            else if(str[i + 1] == 'x')
            {
                ft_putstr("0x");
                count += ft_putHex(va_arg(args, unsigned int));
                i++;
            }
            else if(str[i + 1] == 'X')
            {
                ft_putstr("0X");
                count += ft_putHex(va_arg(args, unsigned int));
                i++;
            }
        }
        else
            count += ft_putchar(str[i]);
        i++;
    }
    write(1,"\n",1);
    va_end(args);
    return (count);
}