/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:53:42 by arincon           #+#    #+#             */
/*   Updated: 2023/11/01 15:19:55 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_env_exec(t_data *data, int i)
{
	char	**envp;
	t_env	*current;
	int		env_size;

	current = data->env;
	env_size = 0;
	while (current)
	{
		env_size++;
		current = current->next;
	}
	envp = malloc(sizeof(char *) * (env_size + 1));
	if (!envp)
		ft_error_msn("Invalid Malloc env tab\n", data);
	current = data->env;
	while (current)
	{
		envp[i] = ft_strjoin_gnl(current->name, "=");
		envp[i] = ft_strjoin_free(envp[i], current->var, 1, 0);
		current = current->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
