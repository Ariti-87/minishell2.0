/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:01:46 by arincon           #+#    #+#             */
/*   Updated: 2023/10/18 16:10:16 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			(ft_builtins(data, data->cmds[cmd_index]->builtins), exit(0));
		if (data->cmds[cmd_index]->cmd)
			ft_exec(data, cmd_index);
	}
	if (cmd_index)
	{
		close(data->pipes[(cmd_index + 1) % 2][0]);
		close(data->pipes[(cmd_index + 1) % 2][1]);
	}
	return (pid);
}

void	ft_exec(t_data *data, int cmd_index)
{
	char	**cmds;
	char	*cmd_final;
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
	{
		cmd_final = ft_find_cmd(data, cmds[0]);
		if (cmd_final == NULL)
		{
			ft_free_tab(cmds);
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(data->cmds[cmd_index]->cmd, 2);
			ft_putstr_fd(": command not found\n", 2);
			exit(1);
		}
		execve(cmd_final, cmds, envp);
	}
	else
	{
		if (access(cmds[0], F_OK | X_OK | R_OK))
			ft_error_msn("Invalid access without PATH\n", data);
		execve(cmds[0], cmds, 0);
	}
	ft_error_msn("Error : execve\n", data);
}

void	ft_dup2_first(t_data *data, int cmd_index, int fd_stdin, int fd_stdout)
{
	if (dup2(fd_stdin, STDIN_FILENO) == -1)
		ft_error_msn("Error with dup2 stdin first cmd\n", data);
	if (data->cmds[cmd_index]->output_redirec)
	{
		if (dup2(fd_stdout, STDOUT_FILENO) == -1)
			ft_error_msn("Error dup2/stdout/first/redir\n", data);
	}
	else
	{
		if (cmd_index + 1 == data->cmds_nb)
		{
			if (dup2(fd_stdout, STDOUT_FILENO) == -1)
				ft_error_msn("Error dup2/stdout/firstc/-redir\n", data);
		}
		else
		{
			if (dup2(data->pipes[cmd_index % 2][1], STDOUT_FILENO) == -1)
				ft_error_msn("Error dup2/stdout/first/pipe/-redir\n", data);
		}
	}
}

void	ft_dup2_n(t_data *data, int cmd_index, int fd_stdin, int fd_stdout)
{
	if (data->cmds[cmd_index]->eof)
		if (dup2(fd_stdin, STDIN_FILENO) == -1)
			ft_error_msn("Error with dup2 stdin n cmd\n", data);
	if (data->cmds[cmd_index]->input_redirec)
		if (dup2(fd_stdin, STDIN_FILENO) == -1)
			ft_error_msn("Error with dup2 stdin n cmd\n", data);
	if (!data->cmds[cmd_index]->input_redirec && !data->cmds[cmd_index]->eof)
		if (dup2(data->pipes[(cmd_index + 1) % 2][0], STDIN_FILENO) == -1)
			ft_error_msn("Error with dup2 stdin n cmd with redir\n", data);
	if (data->cmds[cmd_index]->output_redirec)
	{
		if (dup2(fd_stdout, STDOUT_FILENO) == -1)
			ft_error_msn("Error with dup2 stdout n cmd with redir\n", data);
	}
	else
	{
		if (cmd_index == data->cmds_nb - 1)
			if (dup2(fd_stdout, STDOUT_FILENO) == -1)
				ft_error_msn("Error dup2/stdout/n cmd/-redir\n", data);
		if (cmd_index != data->cmds_nb - 1)
			if (dup2(data->pipes[cmd_index % 2][1], STDOUT_FILENO) == -1)
				ft_error_msn("Error dup2/stdout/n cmd/pipe/-redir\n", data);
	}
}

void	ft_dup2(t_data *data, int cmd_index)
{
	int	fd_stdin;
	int	fd_stdout;

	fd_stdin = ft_open_stdin(data, cmd_index);
	fd_stdout = ft_open_stdout(data, cmd_index);
	if (cmd_index == 0)
		ft_dup2_first(data, cmd_index, fd_stdin, fd_stdout);
	else
		ft_dup2_n(data, cmd_index, fd_stdin, fd_stdout);
	ft_close_pipes(data);
	// close(fd_stdin);
	// close(fd_stdout);
}
