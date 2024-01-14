/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:49:51 by midbella          #+#    #+#             */
/*   Updated: 2024/01/14 23:21:57 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sender(char c, int pid)
{
	int		i;
	char	s;

	i = 7;
	while (i >= 0)
	{
		s = c >> i & 1;
		if (s == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(50);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
	{
		ft_printf("PLEASE ENTER THE SERVER PID AND THE MESSAGE TO SEND\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	while (av[2][i])
		sender(av[2][i++], pid);
}
