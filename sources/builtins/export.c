/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:21:44 by arincon           #+#    #+#             */
/*   Updated: 2023/10/30 12:15:19 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_data *data, char **argv)
{
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (!ft_check_arg_env(argv[i], 1))
			ft_export_for_norm(data, argv, i);
		else
		{
			ft_putstr_fd("minishell: export: ", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd(": not a valid indentifier\n", 2);
			g_last_status = 1;
			return ;
		}
	}
	if (!argv[1])
		ft_env_alpha_order(&data->export);
	g_last_status = 0;
}

void	ft_export_for_norm(t_data *data, char **argv, int i)
{
	char	*equal;
	char	*name;
	char	*var;
	t_env	*env;
	t_env	*export;

	export = data->export;
	env = data->env;
	equal = ft_strchr(argv[i], '=');
	if (equal)
	{
		*equal = '\0';
		name = argv[i];
		var = equal + 1;
		ft_update_list_node(data, 0, name, var);
	}
	else
	{
		name = argv[i];
		var = "";
	}
	ft_update_list_node(data, 1, name, var);
}

void	ft_update_list_node(t_data *data, int i, char *name, char *var)
{
	t_env	*current;

	if (i == 0)
		current = data->env;
	if (i == 1)
		current = data->export;
	while (current)
	{
		if (!ft_strncmp(current->name, name, ft_strlen(name) + 1))
		{
			free(current->var);
			if (var)
				current->var = ft_strdup(var);
			else
				current->var = ft_strdup("");
			return ;
		}
		current = current->next;
	}
	if (i == 0)
		ft_add_env_node(data, name, var);
	if (i == 1)
		ft_add_export_node(data, name, var);
}

void	ft_env_alpha_order(t_env **env)
{
	t_env	*tmp;
	t_env	*min;

	min = *env;
	tmp = *env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, min->name) < 0)
			min = tmp;
		tmp = tmp->next;
	}
	tmp = *env;
	ft_sort_env_list(&tmp);
	while (tmp)
	{
		if (tmp->name && tmp->var)
			printf("%s=%s\n", tmp->name, tmp->var);
		else if (tmp->name && !tmp->var)
			printf("%s=\n", tmp->name);
		tmp = tmp->next;
	}
	*env = min;
}
