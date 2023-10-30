/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:30:20 by arincon           #+#    #+#             */
/*   Updated: 2023/10/30 16:38:23 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_last_status;

int	main(int argc, char **argv, char **envp)
{
	t_data				data;

	(void)argv;
	if (argc != 1)
		return (1 && printf("this program works without arguments\n"));
	ft_init(&data, envp);
	ft_minishell(&data);
	ft_close_and_free(&data);
	return (0);
}
// signal
// tab ?
// cat + ctrl c
