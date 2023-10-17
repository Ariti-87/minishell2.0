/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:32:02 by arincon           #+#    #+#             */
/*   Updated: 2023/10/11 11:23:51 by arincon          ###   ########.fr       */
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
	if (data->builtins_tab)
		ft_free_tab(data->builtins_tab);
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
	if (data->cmds)
		ft_free_unlink_cmds(data);
	if (data->tlist)
		ft_free_list_lexer(&data->tlist);
	if (data->plist)
		ft_free_list_lexer(&data->plist);
}

// Waits for child processes to finish.
void	ft_waitpid(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->cmds_nb && data->pid[i])
		waitpid(data->pid[i], NULL, 0);
}
/* // Extracts the PATH variable from the environment.
// Copy PATH string without "PATH="
char	*ft_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
} */
