/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:15:10 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/15 23:55:06 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexup(unsigned int n)
{
	char	*hexa;
	int		i;

	hexa = "0123456789ABCDEF";
	i = 0;
	if (n >= 16)
	{
		i += ft_puthexup(n / 16);
		i += ft_puthexup(n % 16);
	}
	else
	{
		ft_putchar(hexa[n]);
		i++;
	}
	return (i);
}

int	ft_puthexlow(unsigned int n)
{
	char		*hexa;
	int			i;

	hexa = "0123456789abcdef";
	i = 0;
	if (n >= 16)
	{
		i += ft_puthexlow(n / 16);
		i += ft_puthexlow(n % 16);
	}
	else
	{
		ft_putchar(hexa[n]);
		i++;
	}
	return (i);
}
