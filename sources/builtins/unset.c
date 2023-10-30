/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:23:19 by arincon           #+#    #+#             */
/*   Updated: 2023/10/30 12:28:09 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Attention avec unset PATH;
void	ft_unset(t_env **env, t_env **export, char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		ft_erase_list_node(env, argv);
		ft_erase_list_node(export, argv);
	}
	g_last_status = 0;
}

void	ft_erase_list_node(t_env **env, char **argv)
{
	t_env	*current;
	t_env	*previous;

	current = *env;
	previous = NULL;
	while (current)
	{
		if (!ft_strcmp(current->name, argv[1]))
		{
			if (!previous)
				*env = current->next;
			else
				previous->next = current->next;
			free(current->name);
			free(current->var);
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}
