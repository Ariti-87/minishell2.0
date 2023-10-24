/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:14:46 by arincon           #+#    #+#             */
/*   Updated: 2023/10/24 15:35:59 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* static void	ft_link_builtins_cmd(t_data *data, t_token *head, int cmd_index)
{
	data->cmds[cmd_index]->builtins = malloc(sizeof(char *) * (word_count + 1));
	while (current && (current->type != END && current->type != PIPE))
	{
		if (current->type == WORD)
		{
			data->cmds[cmd_index]->builtins[tab_index] = ft_strdup(current->str);
			tab_index++;
		}
		current = current->next;
	}
	data->cmds[cmd_index]->builtins[tab_index] = 0;
} */
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
			free(data->cmds[cmd_index]->output_redirec);
		}
		data->cmds[cmd_index]->output_redirec = ft_strdup(current->next->str);
		if (data->cmds[cmd_index]->append == 0)
			data->cmds[cmd_index]->fd_out = open(data->cmds[cmd_index]->output_redirec, O_RDWR | O_TRUNC | O_CREAT, 0644);
		else
			data->cmds[cmd_index]->fd_out = open(data->cmds[cmd_index]->output_redirec, O_RDWR | O_APPEND | O_CREAT, 0644);
		if (current->type == GREAT_GREAT)
			data->cmds[cmd_index]->append = 1;
		if (current->type == GREAT)
			data->cmds[cmd_index]->append = 0;
		close(data->cmds[cmd_index]->fd_out);
	}
}



static void	ft_link(t_data *data, t_token *head, int cmd_index, int word_count)
{
	int		tab_index;
	t_token	*current;

	current = head;
	tab_index = 0;
	if (ft_isbuiltins(current->str))
	{
		data->cmds[cmd_index]->builtins = malloc(sizeof(char *) * (word_count + 1));
		while (current && (current->type != END && current->type != PIPE))
		{
			if (current->type == WORD)
			{
				data->cmds[cmd_index]->builtins[tab_index] = ft_strdup(current->str);
				tab_index++;
			}
			current = current->next;
		}
		data->cmds[cmd_index]->builtins[tab_index] = 0;
	}
	else
	{
		data->cmds[cmd_index]->cmd = malloc(sizeof(char *) * (word_count + 1));
		while (current && (current->type != END && current->type != PIPE))
		{
			if (current->type == WORD)
			{
				data->cmds[cmd_index]->cmd[tab_index] = ft_strdup(current->str);
				tab_index++;
			}
			current = current->next;
		}
		data->cmds[cmd_index]->cmd[tab_index] = 0;
	}
}


void	ft_link_cmds(t_data *data)
{
	t_token	*current;
	t_token	*head;
	int		cmd_index;
	int		word_count;

	cmd_index = 0;
	current = data->token;
	while (current && current->type)
	{
		word_count = 0;
		head = current;
		while (current && current->type != PIPE)
		{
			if (current && current->type == WORD)
				word_count++;
			if (current && (current->type == LESS || current->type == LESS_LESS
					|| current->type == GREAT || current->type == GREAT_GREAT))
				ft_link_sep(data, current, cmd_index);
			current = current->next;
		}
		ft_link(data, head, cmd_index, word_count);
		if (current && current->type == PIPE)
			current = current->next;
		cmd_index++;
	}
}
