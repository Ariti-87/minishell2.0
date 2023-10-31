/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:30:20 by arincon           #+#    #+#             */
/*   Updated: 2023/10/31 15:54:27 by arincon          ###   ########.fr       */
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
// nm -Dgu ./minishell
// check here doc singal
