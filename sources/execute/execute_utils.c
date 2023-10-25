/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:38:44 by arincon           #+#    #+#             */
/*   Updated: 2023/10/25 14:16:53 by arincon          ###   ########.fr       */
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
			unlink(data->cmds[i]->heredoc_path);
			free(data->cmds[i]->heredoc_path);
			data->cmds[i]->heredoc_path = NULL;
		}
		if (data->cmds[i]->cmd)
			ft_free_tab(data->cmds[i]->cmd);
		if (data->cmds[i]->builtins)
			ft_free_tab(data->cmds[i]->builtins);
		if (data->cmds[i]->input_redirec)
			free(data->cmds[i]->input_redirec);
		if (data->cmds[i]->output_redirec)
			free(data->cmds[i]->output_redirec);
		if (data->cmds[i]->eof)
			free(data->cmds[i]->eof);
		if (data->cmds[i])
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
