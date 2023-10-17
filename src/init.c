/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:50:45 by arincon           #+#    #+#             */
/*   Updated: 2023/10/16 14:47:03 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Initializes the structure,
// Extracts the PATH environment variable,
// and splits it into individual paths.
// It also allocates memory for pipes.
void	ft_init(t_data *data, char **envp)
{
	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO)
		||!isatty(STDERR_FILENO))
	{
		ft_putstr_fd("Invalid tty stdin/stdout\n", 2);
		exit(0);
	}
	ft_set_last_status(0);
	*data = (t_data){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	ft_get_env(data, envp);
	data->path = ft_env_path(data);
	if (data->path)
	{
		data->paths = ft_split(data->path, ':');
		if (!data->paths)
			ft_error_msn("split doesnt work with **paths\n", data);
	}
	ft_init_pipe(data);
}

void	ft_init_pipe(t_data *data)
{
	data->pipes = malloc(sizeof(int *) * 2);
	if (!data->pipes)
		ft_error_msn("Invalid Malloc pipes\n", data);
	data->pipes[0] = malloc(sizeof(int) * 2);
	if (!data->pipes[0])
		ft_error_msn("Invalid Malloc pipe 0\n", data);
	data->pipes[1] = malloc(sizeof(int) * 2);
	if (!data->pipes[0])
		ft_error_msn("Invalid Malloc pipe 1\n", data);
	data->pipes[0][0] = 0;
	data->pipes[0][1] = 0;
	data->pipes[1][0] = 0;
	data->pipes[1][1] = 0;
}

// initializes an array to store child process IDs.
void	ft_pid_init(t_data *data)
{
	int	i;

	i = -1;
	data->pid = malloc(sizeof(pid_t) * (data->cmds_nb + 1));
	if (!data->pid)
		ft_error_msn ("Invalid Malloc\n", data);
	while (++i < data->cmds_nb)
		data->pid[i] = 0;
	data->pid[i] = 0;
}
