/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:23:19 by arincon           #+#    #+#             */
/*   Updated: 2023/09/27 11:12:46 by arincon          ###   ########.fr       */
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
		if (ft_check_arg_env(argv[i], 0) == 1)
		{
			ft_putstr_fd("minishell: unset: ", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd(": not a valid indentifier\n", 2);
		}
		else
		{
			ft_erase_list_node(env, argv);
			ft_erase_list_node(export, argv);
		}
	}
}

void	ft_erase_list_node(t_env **env, char **argv)
{
	t_env	*current;
	t_env	*previous;

	current = *env;
	previous = NULL;
	while (current)
	{
		if (!ft_strncmp(current->name, argv[1], ft_strlen(argv[1]) + 1))
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
