/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:25:05 by arincon           #+#    #+#             */
/*   Updated: 2023/10/06 11:25:33 by arincon          ###   ########.fr       */
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
					O_RDWR | O_APPEND | O_CREAT, 00777);
			if (fd_stdout < 0)
				ft_error_msn("File descriptor error, stdout\n", data);
		}
		else
		{
			fd_stdout = open(data->cmds[cmd_index]->output_redirec,
					O_RDWR | O_TRUNC | O_CREAT, 00777);
			if (fd_stdout < 0)
				ft_error_msn("File descriptor error, stdout\n", data);
		}
	}
	return (fd_stdout);
}
