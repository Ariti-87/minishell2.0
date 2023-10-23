/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:21:17 by arincon           #+#    #+#             */
/*   Updated: 2023/10/23 12:16:50 by ddania-c         ###   ########.fr       */
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
	int option;

	if (argv[1] && !ft_strncmp("$?", argv[1], 2))
	{
		printf("%d\n", ft_get_last_status());
		return ;
	}
	i = 1;
	if (!argv[1])
	{
		printf("\n");
		return ;
	}
	option = ft_echo_option(argv[i]);
	while (argv[i] && ft_echo_option(argv[i]))
		i++;
	while (argv[i])
	{
		printf("%s", argv[i++]);
		if (argv[i])
			printf(" ");
	}
	if (!option)
		printf("\n");
	ft_return_status(data, EXIT_SUCCESS);
}
