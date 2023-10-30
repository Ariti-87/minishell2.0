/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:02:46 by ddania-c          #+#    #+#             */
/*   Updated: 2023/10/30 17:05:29 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_minishell(t_data *data)
{
	char	*line;

	while (1)
	{
		ft_signal_interactive();
		line = readline("minishell$ ");
		ft_siganl_noninteractive();
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
	if (ft_parser(data) != 0 || data->token->type == END)
	{
		ft_free_parsing(data);
		g_last_status = 2;
		return ;
	}
	print_lexer(&data->token);
	ft_execute_init(data);
	ft_link(data);
	ft_free_parsing(data);
	ft_execute(data);
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
		*data->cmds[i] = (t_cmd){i, 0, 0, 0, 0, 0, 0, 0, 0};
}

void	ft_execute(t_data *data)
{
	int		i;
	pid_t	pid_insert;

	ft_pid_init(data);
	i = -1;
	if (data->cmds_nb == 1 && data->cmds[0]->builtins
		&& !data->cmds[0]->input_redirec
		&& !data->cmds[0]->output_redirec && !data->cmds[0]->eof)
		ft_builtins(data, 0);
	else
	{
		while (++i < data->cmds_nb)
		{
			pid_insert = ft_fork(data, i);
			data->pid[i] = pid_insert;
		}
		ft_waitpid(data);
	}
	ft_free_unlink_cmds(data);
}
