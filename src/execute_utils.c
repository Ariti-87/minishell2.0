/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:38:44 by arincon           #+#    #+#             */
/*   Updated: 2023/10/06 11:09:25 by arincon          ###   ########.fr       */
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
