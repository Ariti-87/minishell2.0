/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:02:46 by ddania-c          #+#    #+#             */
/*   Updated: 2023/11/01 15:24:39 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_minishell(t_data *data)
{
	while (1)
	{
		ft_signal_interactive();
		data->line = readline("minishell$ ");
		ft_signal_noninteractive();
		if (!data->line)
		{
			write(1, "exit\n", 5);
			break ;
		}
		if (data->line && data->line[0])
		{
			add_history(data->line);
			ft_execute_minishell(data);
		}
		free(data->line);
	}
}

void	ft_execute_minishell(t_data *data)
{
	if (ft_parser(data) != 0)
	{
		ft_free_parsing(data);
		g_last_status = 2;
		return ;
	}
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
