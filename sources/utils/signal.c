/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:00:31 by arincon           #+#    #+#             */
/*   Updated: 2023/11/01 12:01:07 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_last_status = 130;
	}
	else if (signal == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", 0);
}

void	ft_signal_interactive(void)
{
	struct sigaction	signal;

	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_RESTART;
	signal.sa_handler = &signal_handler;
	sigaction(SIGINT, &signal, NULL);
	sigaction(SIGQUIT, &signal, NULL);
}

void	signal_print_newline(int signal)
{
	(void)signal;
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_on_new_line();
}

void	ft_signal_noninteractive(void)
{
	struct sigaction	signal;

	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_RESTART;
	signal.sa_handler = &signal_print_newline;
	sigaction(SIGINT, &signal, NULL);
	sigaction(SIGQUIT, &signal, NULL);
}
