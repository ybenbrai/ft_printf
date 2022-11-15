/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:16:49 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/15 22:23:21 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int    ft_nbrlen(int n)
{
    int    i;

    i = 0;
    if (n == -2147483648)
        return (11);
    if (n < 0)
    {
        n = -n;
        i++;
    }
    if (n >= 10)
        i += ft_nbrlen(n / 10);
    else
        i++;
    return (i);
}

char    *ft_strdup(const char *s)
{
    char    *str;
    int     i;

    i = 0;
    str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (str == NULL)
        return (NULL);
    while (s[i])
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    *ft_strrev(char *str)
{
    int     i;
    int     j;
    char    tmp;

    i = 0;
    j = ft_strlen(str) - 1;
    while (i < j)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return (str);
}

char    *ft_itoa(int n)
{
    int     i;
    int     sign;
    char    *str;

    i = 0;
    sign = 1;
    if (n == -2147483648)
        return (ft_strdup("-2147483648"));
    if (n < 0)
    {
        sign = -1;
        n = -n;
    }
    str = (char *)malloc(sizeof(char) * (ft_nbrlen(n) + 1));
    if (str == NULL)
        return (NULL);
    while (n > 0)
    {
        str[i++] = (n % 10) + '0';
        n = n / 10;
    }
    if (sign == -1)
        str[i++] = '-';
    str[i] = '\0';
    return (ft_strrev(str));
}