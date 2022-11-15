/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:13:56 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/15 23:40:52 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_checker(va_list args, char flag, int count)
{
	if (flag == '%')
	{
		ft_putchar('%');
		count++;
	}
	else if (flag == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (flag == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (flag == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putnbr_base_p(va_arg(args, unsigned long long),
				"0123456789abcdef");
	}
	else if (flag == 'd' || flag == 'i'){
		count += ft_putnbr(va_arg(args, int));
	}
	else if (flag == 'u')
		count += ft_putnbrdec(va_arg(args, unsigned long int));
	else if (flag == 'x')
		count += ft_puthexlow(va_arg(args, unsigned int));
	else if (flag == 'X')
		count += ft_puthexup(va_arg(args, unsigned int));
	return (count);
}

int		ft_printf(const char *str, ...)
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
			count = flag_checker(args,str[i + 1], count);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
