/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:30:20 by arincon           #+#    #+#             */
/*   Updated: 2023/10/23 12:45:45 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data				data;
	struct sigaction	signal;

	(void)argv;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_RESTART;
	signal.sa_handler = &signal_handler;
	if (sigaction(SIGINT, &signal, NULL) == -1 || \
	sigaction(SIGQUIT, &signal, NULL) == -1)
		return (EXIT_FAILURE);
	if (argc != 1)
		return (1 && printf("this program works without arguments\n"));
	ft_init(&data, envp);
	ft_minishell(&data);
	ft_close_and_free(&data);
	return (0);
}

// parser quitar las " " ' '
// parser no debe haber error " | > " o " | < "

// signal
// Arreglar el ft_split, los espacios
// cerar los fd cuando hay varios
// varios heredoc en la misma cmd
// $? con status
// exit | ? gerer les leaks

// LEAKS


// ec'ho'