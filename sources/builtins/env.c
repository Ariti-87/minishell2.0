/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:24:03 by arincon           #+#    #+#             */
/*   Updated: 2023/10/25 15:34:20 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_data *data, char **argv)
{
	t_env	*tmp;

	tmp = data->env;
	while (tmp && !argv[1])
	{
		if (tmp->name && tmp->var)
			printf("%s=%s\n", tmp->name, tmp->var);
		else if (tmp->name && !tmp->var)
			printf("%s=\n", tmp->name);
		tmp = tmp->next;
	}
	if (argv[1])
	{
		ft_putstr_fd("minishell: env: too many arguments\n", 2);
		g_last_status = 127;
		return ;
	}
	g_last_status = 0;
}
