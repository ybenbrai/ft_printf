/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_printers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:18:17 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/16 00:00:46 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long int n, char *base)
{
	unsigned long long	len;
	int					i;
	int					count;

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

int	ft_putnbr_base_p(unsigned long long int n, char *base)
{
	unsigned long long	len;
	int					count;
	int					i;

	i = 0;
	count = 0;
	len = ft_strlen(base);
	if (n >= len)
	{
		count += ft_putnbr_base_p(n / len, base);
		count += ft_putnbr_base_p(n % len, base);
	}
	else
	{
		write(1, &base[n], 1);
		count++;
	}
	return (count);
}
