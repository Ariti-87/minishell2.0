/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:38:44 by arincon           #+#    #+#             */
/*   Updated: 2023/10/19 17:15:55 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_cmds(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->cmds_nb)
	{
		if (data->cmds[i]->heredoc_path)
		{
			free(data->cmds[i]->heredoc_path);
			data->cmds[i]->heredoc_path = NULL;
			unlink(data->cmds[i]->heredoc_path);
		}
		free(data->cmds[i]);
		data->cmds[i] = NULL;
	}
}

void	ft_free_unlink_cmds(t_data *data)
{
	if (data->cmds)
	{
		ft_free_cmds(data);
		free(data->cmds);
		data->cmds = NULL;
	}
	if (data->pid)
		free(data->pid);
}

int	ft_cmd_count(t_data *data)
{
	int		i;
	t_token	*current;

	i = 1;
	current = data->token;
	while (current)
	{
		if (current->type == PIPE)
			i++;
		current = current->next;
	}
	return (i);
}
