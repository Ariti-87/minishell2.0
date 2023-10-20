/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:14:46 by arincon           #+#    #+#             */
/*   Updated: 2023/10/19 16:33:51 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isbuiltins(char *str)
{
	if (!ft_strncmp(str, "echo", 5) || !ft_strncmp(str, "echo ", 5))
		return (1);
	if (!ft_strncmp(str, "exit", 5) || !ft_strncmp(str, "exit ", 5))
		return (1);
	if (!ft_strncmp(str, "export", 7) || !ft_strncmp(str, "export ", 7))
		return (1);
	if (!ft_strncmp(str, "env", 4) || !ft_strncmp(str, "env ", 4))
		return (1);
	if (!ft_strncmp(str, "cd", 3) || !ft_strncmp(str, "cd ", 3))
		return (1);
	if (!ft_strncmp(str, "pwd", 4) || !ft_strncmp(str, "pwd ", 4))
		return (1);
	if (!ft_strncmp(str, "unset", 6) || !ft_strncmp(str, "unset ", 6))
		return (1);
	return (0);
}

static void	ft_link_sep(t_data *data, t_token *current, int cmd_index)
{
	if (current->type == LESS)
	{
		if (data->cmds[cmd_index]->input_redirec)
			free(data->cmds[cmd_index]->input_redirec);
		data->cmds[cmd_index]->input_redirec = ft_strdup(current->next->str);
	}
	else if (current->type == LESS_LESS)
		data->cmds[cmd_index]->eof = ft_strdup(current->next->str);
	else
	{
		if (data->cmds[cmd_index]->output_redirec)
		{
			if (data->cmds[cmd_index]->append == 0)
				open(data->cmds[cmd_index]->output_redirec, O_RDWR | O_TRUNC | O_CREAT, 00777);
			else
				open(data->cmds[cmd_index]->output_redirec, O_RDWR | O_APPEND | O_CREAT, 00777);
			free(data->cmds[cmd_index]->output_redirec);
		}
		data->cmds[cmd_index]->output_redirec = ft_strdup(current->next->str);
		if (current->type == GREAT_GREAT)
			data->cmds[cmd_index]->append = 1;
		if (current->type == GREAT)
			data->cmds[cmd_index]->append = 0;
	}
}

void	ft_link_cmd(t_data *data)
{
	t_token	*current;
	int		cmd_index;

	cmd_index = 0;
	current = data->token;
	while (current && current->type)
	{
		while (current && current->type != PIPE)
		{
			if (current && current->type == WORD)
			{
				if (ft_isbuiltins(current->str))
					data->cmds[cmd_index]->builtins = ft_strdup(current->str);
				else
					data->cmds[cmd_index]->cmd = ft_strdup(current->str);
			}
			if (current && (current->type == LESS || current->type == LESS_LESS
					|| current->type == GREAT || current->type == GREAT_GREAT))
				ft_link_sep(data, current, cmd_index);
			current = current->next;
		}
		if (current && current->type == PIPE)
			current = current->next;
		cmd_index++;
	}
}
