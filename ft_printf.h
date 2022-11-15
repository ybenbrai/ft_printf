/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:13:24 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/15 16:43:55 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

int   ft_printf(char *str, ...);
int     ft_putnbr(int n);
int     ft_putstr(char *str);
int    ft_putchar(char c);
int    ft_putHex(unsigned int n);
int     ft_putDec(int n);

#endif