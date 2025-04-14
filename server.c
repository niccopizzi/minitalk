/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:37:14 by npizzi            #+#    #+#             */
/*   Updated: 2024/11/01 17:44:33 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr(int signum, siginfo_t *act, void *ucontext)
{
	static char	c;
	static int	calls;

	if (signum == SIGUSR2 && calls < 8)
		c |= 1 << calls;
	calls++;
	if (calls == 8)
	{
		if (c == EOT)
		{
			write(1, "\n\n", 2);
			kill(act->si_pid, SIGUSR2);
			c = 0;
			calls = 0;
			return ;
		}
		write(1, &c, 1);
		calls = 0;
		c = 0;
	}
	kill(act->si_pid, SIGUSR1);
	(void)ucontext;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler_sigusr;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf(ANSI_COLOR_RED "Error handling SIGUSR1\n" ANSI_MODE_RESET);
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf(ANSI_COLOR_RED "Error handling SIGUSR2\n" ANSI_MODE_RESET);
		return (1);
	}
	ft_printf("\n\t");
	ft_printf(ANSI_COLOR_CYAN MODE_BOLD WELCOME_MESSAGE ANSI_MODE_RESET);
	ft_printf("\n\n\t");
	ft_printf(MODE_BOLD ANSI_COLOR_CYAN "SERVER PID : %d\n\n" ANSI_MODE_RESET,
		getpid());
	while (1)
		pause();
	return (0);
}
