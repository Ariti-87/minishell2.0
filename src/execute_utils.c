/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:38:44 by arincon           #+#    #+#             */
/*   Updated: 2023/10/19 11:55:11 by arincon          ###   ########.fr       */
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
		if (data->cmds[i]->cmd)
			free(data->cmds[i]->cmd);
		if (data->cmds[i]->builtins)
			free(data->cmds[i]->builtins);
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
