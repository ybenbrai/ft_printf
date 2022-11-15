/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:25:32 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/15 16:07:41 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int ft_putnbr(int n)
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
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		i++;
	}
	return (i);
}

int    ft_putHex(unsigned int n)
{
    char *hexa;

    hexa = "0123456789abcdef";
    if (n >= 16)
    {
        ft_putHex(n / 16);
        ft_putHex(n % 16);
    }
    else
        ft_putchar(hexa[n]);
        return(1);
}

int     ft_putDec(int n)
{

    if (n == -2147483648)
    {
        ft_putstr("-2147483648");
        return (1);
    }
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
    {
        ft_putDec(n / 10);
        ft_putDec(n % 10);
    }
    else
    {
        ft_putchar(n + '0');
  
    }
    return (1);
}
