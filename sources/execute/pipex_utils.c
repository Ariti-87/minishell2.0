/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:32:02 by arincon           #+#    #+#             */
/*   Updated: 2023/11/01 15:01:47 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Extracts the PATH variable from the environment.
// Copy PATH string without "PATH="
char	*ft_env_path(t_data *data)
{
	t_env	*current;

	current = data->env;
	while (current)
	{
		if (!ft_strncmp(current->name, "PATH", ft_strlen("PATH") + 1))
			return (current->var);
		current = current->next;
	}
	return (NULL);
}

// Searches for a command in the specified paths.
// Return null if the command was not found
char	*ft_find_cmd(t_data *data, char *cmd)
{
	int		i;
	char	*find_cmd;
	char	*v_cmd;

	if (cmd[0] == '\0')
		return (NULL);
	i = 0;
	v_cmd = ft_strjoin_gnl("/", cmd);
	if (!v_cmd)
		ft_error_msn("Problem with strjoin\n", data);
	while (data->paths[i])
	{
		find_cmd = ft_strjoin_gnl(data->paths[i], v_cmd);
		if (!find_cmd)
			ft_error_msn("Problem with strjoin\n", data);
		if (access(find_cmd, 0) == 0)
			return (free(v_cmd), find_cmd);
		free(find_cmd);
		i++;
	}
	free(v_cmd);
	return (NULL);
}

// closes pipe file descriptors if exist
void	ft_close_pipes(t_data *data)
{
	if (data->pipes[0][0])
		close(data->pipes[0][0]);
	if (data->pipes[0][1])
		close(data->pipes[0][1]);
	if (data->pipes[1][0])
		close(data->pipes[1][0]);
	if (data->pipes[1][1])
		close(data->pipes[1][1]);
}

// Closes pipes, frees allocated memory
void	ft_close_and_free(t_data *data)
{
	if (data->paths)
		ft_free_tab(data->paths);
	if (data->pipes)
	{
		ft_close_pipes(data);
		free(data->pipes[0]);
		free(data->pipes[1]);
		free(data->pipes);
	}
	if (data->env)
		ft_free_list_env(data->env);
	if (data->export)
		ft_free_list_env(data->export);
	if (data->token)
		ft_free_list_lexer(&data->token);
	if (data->cmds)
		ft_free_unlink_cmds(data);
}

// Waits for child processes to finish.
void	ft_waitpid(t_data *data)
{
	int	i;
	int	status;
	int	save_status;

	save_status = 0;
	i = 0;
	while (i < data->cmds_nb && data->pid[i])
	{
		waitpid(data->pid[i], &status, 0);
		i++;
	}
	save_status = status;
	if (WIFSIGNALED(save_status))
		status = 128 + WTERMSIG(save_status);
	else if (WIFEXITED(save_status))
		status = WEXITSTATUS(save_status);
	else
		status = save_status;
	g_last_status = status;
}
