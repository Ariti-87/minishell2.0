/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:14:46 by arincon           #+#    #+#             */
/*   Updated: 2023/11/01 15:08:53 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_link_in_out(t_data *data, t_token *current, int i)
{
	if (data->cmds[i]->output_redirec)
		free(data->cmds[i]->output_redirec);
	data->cmds[i]->output_redirec = ft_strdup(current->next->str);
	if (current->type == GREAT_GREAT)
		data->cmds[i]->append = 1;
	if (current->type == GREAT)
		data->cmds[i]->append = 0;
	if (data->cmds[i]->append == 0)
		data->cmds[i]->fd_out
			= open(data->cmds[i]->output_redirec,
				O_RDWR | O_TRUNC | O_CREAT, 0644);
	else
		data->cmds[i]->fd_out
			= open(data->cmds[i]->output_redirec,
				O_RDWR | O_APPEND | O_CREAT, 0644);
	close(data->cmds[i]->fd_out);
}

static void	ft_link_sep(t_data *data, t_token *current, int i)
{
	int	fd;

	fd = 0;
	if (current->type == LESS)
	{
		if (data->cmds[i]->input_redirec)
			free(data->cmds[i]->input_redirec);
		data->cmds[i]->input_redirec = ft_strdup(current->next->str);
	}
	else if (current->type == LESS_LESS)
	{
		if (data->cmds[i]->eof)
		{
			free(data->cmds[i]->eof);
			free(data->cmds[i]->heredoc_path);
		}
		data->cmds[i]->eof = ft_strdup(current->next->str);
		ft_heredoc_path(data, i);
		ft_heredoc_create(data, i, data->cmds[i]->heredoc_path, fd);
	}
	else
		ft_link_in_out(data, current, i);
}

static void	ft_link_built_cmd(t_data *data, t_token *head, int index, int flag)
{
	t_token	*current;
	int		tab_index;

	tab_index = 0;
	current = head;
	while (current && (current->type != END && current->type != PIPE))
	{
		if (current->type == WORD)
		{
			if (flag == 0)
				data->cmds[index]->builtins[tab_index]
					= ft_strdup(current->str);
			else
				data->cmds[index]->cmd[tab_index] = ft_strdup(current->str);
			tab_index++;
		}
		current = current->next;
	}
	if (flag == 0)
		data->cmds[index]->builtins[tab_index] = 0;
	else
		data->cmds[index]->cmd[tab_index] = 0;
}

static void	ft_link_cmds(t_data *data, t_token *head, int i, int word_count)
{
	if (ft_isbuiltins(head->str))
	{
		data->cmds[i]->builtins
			= malloc(sizeof(char *) * (word_count + 1));
		ft_link_built_cmd(data, head, i, 0);
	}
	else
	{
		data->cmds[i]->cmd
			= malloc(sizeof(char *) * (word_count + 1));
		ft_link_built_cmd(data, head, i, 1);
	}
}

void	ft_link(t_data *data)
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
		ft_link_cmds(data, head, cmd_index, word_count);
		if (current && current->type == PIPE)
			current = current->next;
		cmd_index++;
	}
}
