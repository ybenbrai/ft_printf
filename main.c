/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:30:05 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/15 23:58:51 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_printf("Hello ft%d_printf :)\n", 8000);
	printf("Hello ft%d_printf :)\n", 8000);
	return (1);
}
