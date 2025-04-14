/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:49:00 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 13:27:39 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & 1 << i) == 0)
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				ft_printf("Error in sending SIGUSR1\n");
				exit(1);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_printf("Error in sending SIGUSR2\n");
				exit(1);
			}
		}
		i++;
		usleep(50000);
	}
}

void	handler_sigusr(int signum)
{
	if (signum == SIGUSR1)
	{
		return ;
	}
	if (signum == SIGUSR2)
	{
		ft_printf(ANSI_COLOR_GREEN "Server got the message!\n" ANSI_MODE_RESET);
	}
}

void	install_hanlder(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handler_sigusr;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf(ANSI_COLOR_RED "Error handling SIGUSR1\n" ANSI_MODE_RESET);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf(ANSI_COLOR_RED "Error handling SIGUS2\n" ANSI_MODE_RESET);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	int	server_pid;
	int	i;

	install_hanlder();
	if (argc != 3)
	{
		ft_printf("Insert only Server PID and String to send ppplease\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0 || kill(server_pid, 0) == -1)
	{
		ft_printf("Insert a valid PID\n");
		return (1);
	}
	i = 0;
	while (argv[2][i] != 0)
	{
		send_char(argv[2][i], server_pid);
		i++;
	}
	send_char(EOT, server_pid);
	return (0);
}
