/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:20:25 by arincon           #+#    #+#             */
/*   Updated: 2023/10/23 13:27:55 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_builtins(t_data *data, char *str)
{
	data->builtins_tab = ft_split(str, ' ');
	if (!ft_strcmp(data->builtins_tab[0], "echo"))
		ft_echo(data->builtins_tab);
	else if (!ft_strcmp(data->builtins_tab[0], "pwd"))
		ft_pwd();
	else if (!ft_strcmp(data->builtins_tab[0], "exit"))
		ft_exit(data, data->builtins_tab);
	else if (!ft_strcmp(data->builtins_tab[0], "env"))
		ft_env(data->env, data->builtins_tab);
	else if (!ft_strcmp(data->builtins_tab[0], "cd"))
		ft_cd(data, data->builtins_tab);
	else if (!ft_strcmp(data->builtins_tab[0], "unset"))
		ft_unset(&data->env, &data->export, data->builtins_tab);
	else if (!ft_strcmp(data->builtins_tab[0], "export"))
		ft_export(data, data->builtins_tab);
	ft_free_tab(data->builtins_tab);
}
