/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:14:46 by arincon           #+#    #+#             */
/*   Updated: 2023/10/18 18:41:07 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isbuiltins(char *str)
{
	if (!ft_strncmp(str, "echo", 5))
		return (1);
	if (!ft_strncmp(str, "exit", 5))
		return (1);
	if (!ft_strncmp(str, "export", 7))
		return (1);
	if (!ft_strncmp(str, "env", 4))
		return (1);
	if (!ft_strncmp(str, "cd", 3))
		return (1);
	if (!ft_strncmp(str, "pwd", 4))
		return (1);
	if (!ft_strncmp(str, "unset", 6))
		return (1);
	return (0);
}

static void	ft_link_sep(t_data *data, t_token *current, int cmd_index)
{
	if (current->type == LESS)
		data->cmds[cmd_index]->input_redirec = ft_strdup(current->next->str);
	else if (current->type == LESS_LESS)
		data->cmds[cmd_index]->eof = ft_strdup(current->next->str);
	else if (current->type == GREAT || current->type == GREAT_GREAT)
	{
		data->cmds[cmd_index]->output_redirec = ft_strdup(current->next->str);
		if (current->type == GREAT_GREAT)
			data->cmds[cmd_index]->append = 1;
	}
}

void	ft_link_cmd(t_data *data)
{
	t_token	*current;
	int		cmd_index;

	cmd_index = 0;
	current = data->token;
	while (current)
	{
		while (current && current->type != PIPE)
		{
			if (current->type == WORD)
			{
				if (ft_isbuiltins(current->str))
				{
					data->cmds[cmd_index]->builtins = ft_strjoin(current->str, current->next->str);
					current = current->next;
				}
				else
					data->cmds[cmd_index]->cmd = ft_strdup(current->str);
				current = current->next;
			}
			if (current && (current->type == LESS || current->type == LESS_LESS
				|| current->type == GREAT || current->type == GREAT_GREAT))
			{

				ft_link_sep(data, current, cmd_index);
				current = current->next;
				current = current->next;
			}
		}
		cmd_index++;
	}
}
