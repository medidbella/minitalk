/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:14:47 by midbella          #+#    #+#             */
/*   Updated: 2024/01/14 23:26:46 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct s_tab	g_block;

void	handel_sig1(int sig)
{
	sig = 0;
	g_block.c = g_block.c << 1 | 1;
	g_block.counter++;
	if (g_block.counter == 8)
	{
		ft_printf("%c", g_block.c);
		g_block.counter = 0;
	}
}

void	handel_sig2(int sig)
{
	sig = 0;
	g_block.c = g_block.c << 1;
	g_block.counter++;
	if (g_block.counter == 8)
	{
		ft_printf("%c", g_block.c);
		g_block.counter = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, handel_sig1);
	signal(SIGUSR2, handel_sig2);
	ft_printf("THE PROCESS ID OF THE SERVER => %d <=\n", getpid());
	while (1)
	{
	}
}
