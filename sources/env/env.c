/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:04:26 by arincon           #+#    #+#             */
/*   Updated: 2023/10/30 12:12:17 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_env(t_data *data, char **envp)
{
	int		i;
	char	*equal;
	char	*name;
	char	*var;

	i = -1;
	while (envp[++i])
	{
		equal = ft_strchr(envp[i], '=');
		if (equal)
		{
			*equal = '\0';
			name = envp[i];
			var = equal + 1;
			ft_add_env_node(data, name, var);
			ft_add_export_node(data, name, var);
		}
	}
}

void	ft_add_env_node(t_data *data, char *name, char *var)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		ft_error_msn("Invalid Malloc env\n", data);
	new_node->name = ft_strdup(name);
	new_node->var = ft_strdup(var);
	new_node->next = NULL;
	if (!data->env)
		data->env = new_node;
	else
		ft_last_env_node(data->env)->next = new_node;
}

void	ft_add_export_node(t_data *data, char *name, char *var)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		ft_error_msn("Invalid Malloc env\n", data);
	new_node->name = ft_strdup(name);
	new_node->var = ft_strdup(var);
	new_node->next = NULL;
	if (!data->export)
		data->export = new_node;
	else
		ft_last_env_node(data->export)->next = new_node;
}
