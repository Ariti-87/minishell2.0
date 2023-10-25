/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:20:25 by arincon           #+#    #+#             */
/*   Updated: 2023/10/25 14:12:56 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_builtins(t_data *data, int cmd_index)
{
	if (!ft_strncmp(data->cmds[cmd_index]->builtins[0], "echo", 5))
		ft_echo(data->cmds[cmd_index]->builtins);
	else if (!ft_strncmp(data->cmds[cmd_index]->builtins[0], "pwd", 4))
		ft_pwd();
	else if (!ft_strncmp(data->cmds[cmd_index]->builtins[0], "exit", 5))
		ft_exit(data, data->cmds[cmd_index]->builtins);
	else if (!ft_strncmp(data->cmds[cmd_index]->builtins[0], "env", 4))
		ft_env(data, data->cmds[cmd_index]->builtins);
	else if (!ft_strncmp(data->cmds[cmd_index]->builtins[0], "cd", 3))
		ft_cd(data, data->cmds[cmd_index]->builtins);
	else if (!ft_strncmp(data->cmds[cmd_index]->builtins[0], "unset", 6))
		ft_unset(&data->env, &data->export, data->cmds[cmd_index]->builtins);
	else if (!ft_strncmp(data->cmds[cmd_index]->builtins[0], "export", 7))
		ft_export(data, data->cmds[cmd_index]->builtins);
}
