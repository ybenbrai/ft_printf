/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:13:24 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/15 23:57:30 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_puthex(unsigned int n);
int		ft_puthexlow(unsigned int n);
int		ft_puthexup(unsigned int n);
int		ft_putnbr_base_p(unsigned long long n, char *base);
int		ft_nbrlen(int n);
int		ft_putdec(int n);
char	*ft_strdup(const char *s);
char	*ft_strrev(char *str);
int		ft_putnbrdec(unsigned int n);
int		ft_strlen(const char *s);
char	*ft_itoa(int n);
#endif