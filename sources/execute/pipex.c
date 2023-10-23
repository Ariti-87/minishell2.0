/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:01:46 by arincon           #+#    #+#             */
/*   Updated: 2023/10/23 16:39:50 by ddania-c         ###   ########.fr       */
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
			ft_builtins(data, data->cmds[cmd_index]->builtins);
			ft_free_tab(data->builtins_tab);
			ft_close_and_free(data);
			exit(67);
		}
		if (data->cmds[cmd_index]->cmd)
			ft_execve(data, cmd_index);
		exit(0);
	}
	if (cmd_index)
		ft_pipe_close(data, cmd_index);
	return (pid);
}


static void	ft_execve_no_cmd(t_data *data, char **cmds, char **envp, int cmd_index)
{
	char	*cmd_final;

	cmd_final = ft_find_cmd(data, cmds[0]);
	if (cmd_final == NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(data->cmds[cmd_index]->cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_close_and_free(data);
		ft_free_tab(cmds);
		ft_free_tab(envp);
		exit (127);
	}
	execve(cmd_final, cmds, envp);
}


static void	ft_execve_no_path(t_data *data, char **cmds, char **envp, int cmd_index)
{
	if (access(cmds[0], F_OK | X_OK | R_OK))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(data->cmds[cmd_index]->cmd, 2);
		ft_putstr_fd(": Invalid access\n", 2);
		ft_close_and_free(data);
		ft_free_tab(cmds);
		ft_free_tab(envp);
		exit(126);
	}
	execve(cmds[0], cmds, 0);
}


void	ft_execve(t_data *data, int cmd_index)
{
	char	**cmds;
	char	**envp;

	if (data->cmds[cmd_index]->cmd[0] == ' '
		|| data->cmds[cmd_index]->cmd[0] == '\0')
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(data->cmds[cmd_index]->cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(1);
	}
	envp = ft_env_exec(data);
	cmds = ft_split(data->cmds[cmd_index]->cmd, ' ');
	if (!cmds)
		ft_error_msn("problem with split in ft_exec\n", data);
	if (data->path && !ft_strchr(cmds[0], '/'))
		ft_execve_no_cmd(data, cmds, envp, cmd_index);
	else
		ft_execve_no_path(data, cmds, envp, cmd_index);
	ft_free_tab(cmds);
	ft_free_tab(envp);
	ft_error_msn("Error : execve\n", data);
}

// void	ft_execve(t_data *data, int cmd_index)
// {
// 	char	**cmds;
// 	char	*cmd_final;
// 	char	**envp;

// 	if (data->cmds[cmd_index]->cmd[0] == ' '
// 		|| data->cmds[cmd_index]->cmd[0] == '\0')
// 	{
// 		ft_putstr_fd("minishell: ", 2);
// 		ft_putstr_fd(data->cmds[cmd_index]->cmd, 2);
// 		ft_putstr_fd(": command not found\n", 2);
// 		exit(1);
// 	}
// 	envp = ft_env_exec(data);
// 	cmds = ft_split(data->cmds[cmd_index]->cmd, ' ');
// 	if (!cmds)
// 		ft_error_msn("problem with split in ft_exec\n", data);
// 	if (data->path && !ft_strchr(cmds[0], '/'))
// 	{
// 		cmd_final = ft_find_cmd(data, cmds[0]);
// 		if (cmd_final == NULL)
// 		{
// 			ft_putstr_fd("minishell: ", 2);
// 			ft_putstr_fd(data->cmds[cmd_index]->cmd, 2);
// 			ft_putstr_fd(": command not found\n", 2);
// 			ft_close_and_free(data);
// 			ft_free_tab(cmds);
// 			ft_free_tab(envp);
// 			exit(1);
// 		}
// 		execve(cmd_final, cmds, envp);
// 	}
// 	else
// 	{
// 		if (access(cmds[0], F_OK | X_OK | R_OK))
// 			ft_error_msn("Invalid access without PATH\n", data);
// 		execve(cmds[0], cmds, 0);
// 	}
// 	ft_error_msn("Error : execve\n", data);
// }
