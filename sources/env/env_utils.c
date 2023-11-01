/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:27:56 by arincon           #+#    #+#             */
/*   Updated: 2023/11/01 12:32:45 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_last_env_node(t_env *env)
{
	while (env && env->next)
		env = env->next;
	return (env);
}

void	ft_free_list_env(t_env	*env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		if (tmp->name)
			free(tmp->name);
		if (tmp->var)
			free(tmp->var);
		env = env->next;
		free(tmp);
	}
}

int	ft_check_arg_env(char *str, int export)
{
	int	i;

	i = 1;
	if (!str[0])
		return (2);
	if (str[0] == '_' && !ft_isalnum(str[1]) && str[1] != '_')
		return (2);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (1);
	while (str[i])
	{
		if (export)
		{
			if (str[i] == '=' || (str[i] == '+' && str[i + 1] == '='))
				return (0);
		}
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	ft_insert_sorted(t_env **env, t_env *new_node)
{
	t_env	*current;

	if (*env == NULL || ft_strcmp((*env)->name, new_node->name) > 0)
	{
		new_node->next = *env;
		*env = new_node;
	}
	else
	{
		current = *env;
		while (current->next != NULL
			&& ft_strcmp(current->next->name, new_node->name) <= 0)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}

void	ft_sort_env_list(t_env **env)
{
	t_env	*sorted;
	t_env	*current;
	t_env	*next;

	sorted = NULL;
	current = *env;
	while (current != NULL)
	{
		next = current->next;
		ft_insert_sorted(&sorted, current);
		current = next;
	}
	*env = sorted;
}
