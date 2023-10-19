/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/10/19 11:58:05 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	ft_minishell(t_data *data)
{
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			write(1, "exit\n", 5);
			break ;
		}
		if (line && line[0])
		{
			add_history(line);
			ft_execute_minishell(data, line);
		}
		free(line);
		line = NULL;
	}
}

void	ft_execute_minishell(t_data *data, char *line)
{
	ft_lexer(data, line);
	ft_lexer_error(data->token);


	// data->cmds_exec = line;
	print_lexer(&data->token);
	ft_execute_init(data);
	ft_link_cmd(data);
	ft_heredoc_path(data);
	ft_execute(data);
	ft_free_parsing(data);
}

void	ft_execute_init(t_data *data)
{
	int	i;

	i = -1;
	data->cmds_nb = ft_cmd_count(data);
	data->cmds = malloc(sizeof(t_cmd *) * (data->cmds_nb));
	if (!data->cmds)
		ft_error_msn("Invalid Malloc struct cmds\n", data);
	while (++i < data->cmds_nb)
	{
		data->cmds[i] = malloc(sizeof(t_cmd));
		if (!data->cmds[i])
			ft_error_msn("Invalid Malloc struct cmds\n", data);
	}
	i = -1;
	while (++i < data->cmds_nb)
		*data->cmds[i] = (t_cmd){i, 0, 0, 0, 0, 0, 0, 0};
}
	// data->cmds[0]->builtins = data->cmds_exec;
	// data->cmds[0]->cmd = data->cmds_exec;
	// data->cmds[1]->builtins = "echo $?";
	// data->cmds[1]->cmd = "echo hola";
	// data->cmds[1]->output_redirec = "file";
	/* i = -1;
	while (++i < data->cmds_nb)
		if (data->cmds[i]->cmd[0] == '\0')
			data->cmds[i]->cmd = " "; */

void	ft_execute(t_data *data)
{
	int		i;
	pid_t	pid_insert;

	ft_pid_init(data);
	i = -1;
	if (data->cmds_nb == 1 && data->cmds[0]->builtins)
		ft_builtins(data, data->cmds[0]->builtins);
	else
	{
		while (++i < data->cmds_nb)
		{
			if (data->cmds[i]->eof)
				ft_heredoc_create(data, i, data->cmds[i]->heredoc_path);
			pid_insert = ft_fork(data, i);
			data->pid[i] = pid_insert;
		}
	}
	ft_waitpid(data);
	ft_free_unlink_cmds(data);
}
