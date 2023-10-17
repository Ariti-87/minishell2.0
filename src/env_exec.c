/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:53:42 by arincon           #+#    #+#             */
/*   Updated: 2023/10/06 11:06:56 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_env_exec(t_data *data)
{
	char	**envp;
	t_env	*current;
	int		env_size;
	int		i;

	current = data->env;
	env_size = 0;
	i = -1;
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
		envp[++i] = ft_strjoin_gnl(current->name, "=");
		envp[i] = ft_strjoin_gnl(envp[i], current->var);
		current = current->next;
	}
	envp[i] = NULL;
	return (envp);
}