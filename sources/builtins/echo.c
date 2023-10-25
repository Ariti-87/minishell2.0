/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:21:17 by arincon           #+#    #+#             */
/*   Updated: 2023/10/25 11:55:46 by arincon          ###   ########.fr       */
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

void	ft_echo(t_data *data, char **argv)
{
	int	i;
	int	option;

	i = 1;
	if (!argv[1])
	{
		printf("\n");
		ft_set_last_status(data, 0);
		return ;
	}
	option = ft_echo_option(argv[i]);
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
	if (!option)
		printf("\n");
	ft_set_last_status(data, 0);
}
