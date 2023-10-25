/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:21:17 by arincon           #+#    #+#             */
/*   Updated: 2023/10/25 17:00:00 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo_option(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[i + 1])
	{
		i++;
		while (str[i] && str[i] == 'n')
			i++;
		if (!str[i])
			return (1);
	}
	return (0);
}

void	ft_echo(char **argv)
{
	int	i;

	i = 1;
	if (!argv[1])
	{
		printf("\n");
		g_last_status = 0;
		return ;
	}
	while (argv[i] && ft_echo_option(argv[i]))
		i++;
	while (argv[i] && argv)
	{
		if (argv[i][0] != '\0')
		{
			printf("%s", argv[i]);
			if (argv[i + 1])
				printf(" ");
		}
		i++;
	}
	if (!ft_echo_option(argv[1]))
		printf("\n");
	g_last_status = 0;
}
