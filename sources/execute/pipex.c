/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:01:46 by arincon           #+#    #+#             */
/*   Updated: 2023/11/02 11:32:54 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void static	ft_pipe_close(t_data *data, int cmd_index)
{
	close(data->pipes[(cmd_index + 1) % 2][0]);
	close(data->pipes[(cmd_index + 1) % 2][1]);
}

pid_t	ft_fork(t_data *data, int cmd_index)
{
	pid_t	pid;

	if (cmd_index < data->cmds_nb - 1)
		if (pipe(data->pipes[cmd_index % 2]) == -1)
			ft_error_msn("An error occurred with the pipe\n", data);
	pid = fork();
	if (pid == -1)
		ft_error_msn("An error occurred with the fork\n", data);
	if (pid == 0)
	{
		ft_dup2(data, cmd_index);
		if (data->cmds[cmd_index]->builtins)
		{
			ft_builtins(data, cmd_index);
			ft_close_and_free(data);
			exit(0);
		}
		if (data->cmds[cmd_index]->cmd[0])
			ft_execve(data, cmd_index);
		ft_close_and_free(data);
		exit(0);
	}
	if (cmd_index)
		ft_pipe_close(data, cmd_index);
	return (pid);
}

static void	ft_execve_cmd(t_data *data, char **cmds, char **envp, int cmd_index)
{
	char	*cmd_final;

	cmd_final = ft_find_cmd(data, cmds[0]);
	if (cmd_final == NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(data->cmds[cmd_index]->cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_close_and_free(data);
		ft_free_tab(envp);
		exit (127);
	}
	execve(cmd_final, cmds, envp);
}

static void	ft_execve_nopath(t_data *data, char **cmds, char **envp, int index)
{
	if (access(cmds[0], F_OK | X_OK | R_OK))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(data->cmds[index]->cmd[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		ft_close_and_free(data);
		ft_free_tab(envp);
		exit(127);
	}
	execve(cmds[0], cmds, envp);
}

void	ft_execve(t_data *data, int cmd_index)
{
	char	**envp;
	int		i;

	i = 0;
	data->path = ft_env_path(data);
	if (data->path)
	{
		data->paths = ft_split(data->path, ':');
		if (!data->paths)
			ft_error_msn("split doesnt work with **paths\n", data);
	}
	envp = ft_env_exec(data, i);
	if (data->path && !ft_strchr(data->cmds[cmd_index]->cmd[0], '/'))
		ft_execve_cmd(data, data->cmds[cmd_index]->cmd, envp, cmd_index);
	else
		ft_execve_nopath(data, data->cmds[cmd_index]->cmd, envp, cmd_index);
	ft_free_tab(envp);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(data->cmds[cmd_index]->cmd[0], 2);
	ft_putstr_fd(": Is a directory\n", 2);
	ft_close_and_free(data);
	exit(g_last_status = 126);
}
