/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:00:31 by arincon           #+#    #+#             */
/*   Updated: 2023/10/30 17:22:30 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	signal_handler(int signal)
// {
// 	if (signal == SIGINT)
// 	{
// 		ft_putchar_fd('\n', STDOUT_FILENO);
// 		rl_on_new_line();
// 		rl_replace_line("", 0);
// 		rl_redisplay();
// 		g_last_status = 130;
// 	}
// 	else if (signal == SIGQUIT)
// 	{
// 		ft_putstr_fd("\b\b  \b\b", 0);
// 		g_last_status = 131;
// 	}
// }
// void	ft_signal_interactive()
// {
// 	struct sigaction	signal;

// 	sigemptyset(&signal.sa_mask);
// 	signal.sa_flags = SA_RESTART;
// 	signal.sa_handler = &signal_handler;
// 	if (sigaction(SIGINT, &signal, NULL) == -1 || \
// 	sigaction(SIGQUIT, &signal, NULL) == -1)
// 		g_last_status = 2;
// }

// void	signal_print_newline(int signal)
// {
// 	(void)signal;
// 	printf("\n");
// 	rl_on_new_line();
// }

// void	ft_siganl_noninteractive()
// {
// 	struct sigaction	act;

// 	// ft_memset(&act, 0, sizeof(act));
// 	act.sa_handler = &signal_print_newline;
// 	sigaction(SIGINT, &act, NULL);
// 	sigaction(SIGQUIT, &act, NULL);
// }


/* ignore_sigquit:
*	Replaces SIGQUIT signals (ctrl-\) with SIG_IGN to ignore
*	the signal.
*/
void	ignore_sigquit(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act, NULL);
}
void	signal_reset_prompt(int signo)
{
	(void)signo;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

/* set_signals_interactive:
*	Sets the behavior in response to SIGINT (ctrl-c) and SIGQUIT (ctrl-\).
*	SIGINT resets the user input prompt to a new blank line.
*	SIGQUIT is ignored.
*	Used when minishell is in interactive mode, meaning it is awaiting
*	user input.
*/
void	ft_signal_interactive(void)
{
	struct sigaction	act;

	ignore_sigquit();
	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_reset_prompt;
	sigaction(SIGINT, &act, NULL);
}

/* signal_print_newline:
*	Prints a newline for noninteractive signal handling.
*/
void	signal_print_newline(int signal)
{
	(void)signal;
	printf("\n");
	rl_on_new_line();
}

/* set_signals_noninteractive:
*	Sets the behavior in response to SIGINT (ctrl -c) and SIGQUIT (ctrl -\).
*	Used when minishell is in noninteractive mode, meaning it is not awaiting
*	user input. For example, when a command is running (i.e. cat), minishell
*	should not react to SIGINT and SIGQUIT because only the running process (cat)
*	needs to react to those signals.
*/
void	ft_siganl_noninteractive(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_print_newline;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}
