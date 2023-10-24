/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:25:05 by arincon           #+#    #+#             */
/*   Updated: 2023/10/23 15:50:40 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_open_stdin(t_data *data, int cmd_index)
{
	int	fd_stdin;

	fd_stdin = 0;
	if (data->cmds[cmd_index]->input_redirec)
	{
		fd_stdin = open(data->cmds[cmd_index]->input_redirec, O_RDONLY);
		if (fd_stdin < 0)
			ft_error_msn("File descriptor error, stdin\n", data);
	}
	if (data->cmds[cmd_index]->eof)
	{
		fd_stdin = open(data->cmds[cmd_index]->heredoc_path, O_RDONLY);
		if (fd_stdin < 0)
			ft_error_msn("File descriptor error, stdin\n", data);
	}
	return (fd_stdin);
}

int	ft_open_stdout(t_data *data, int cmd_index)
{
	int	fd_stdout;

	fd_stdout = 1;
	if (data->cmds[cmd_index]->output_redirec)
	{
		if (data->cmds[cmd_index]->append == 1)
		{
			fd_stdout = open(data->cmds[cmd_index]->output_redirec,
					O_RDWR | O_APPEND | O_CREAT, 0644);
			if (fd_stdout < 0)
				ft_error_msn("File descriptor error, stdout\n", data);
		}
		else
		{
			fd_stdout = open(data->cmds[cmd_index]->output_redirec,
					O_RDWR | O_TRUNC | O_CREAT, 0644);
			if (fd_stdout < 0)
				ft_error_msn("File descriptor error, stdout\n", data);
		}
	}
	return (fd_stdout);
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
	if (fd_stdin != 0)
		close(fd_stdin);
	if (fd_stdout != 1)
		close(fd_stdout);
}
