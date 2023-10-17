/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:51:26 by arincon           #+#    #+#             */
/*   Updated: 2023/10/06 10:40:43 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//perror("Error: cd: "); verifier l influence avec echo $?
void	ft_cd(t_data *data, char **argv)
{
	t_env	*current;
	char	*pwd;
	char	*oldpwd;
	char	buffer[PATH_MAX + 1];

	pwd = NULL;
	oldpwd = NULL;
	current = NULL;
	if (getcwd(buffer, PATH_MAX))
	{
		if (!argv[1])
			ft_cd_home(data, pwd, oldpwd, current);
		else if (argv[2])
			ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		else
		{
			if ((!chdir(argv[1])) == 0)
				ft_putstr_fd("minishell: cd: No such file or directory\n", 2);
			ft_update_pwd(&data->env, pwd, oldpwd, current);
			ft_update_pwd(&data->export, pwd, oldpwd, current);
		}
	}
	else
		ft_putstr_fd("Error: cd: \n", 2);
}

void	ft_cd_home(t_data *data, char *pwd, char *oldpwd, t_env *current)
{
	t_env	*tmp;

	tmp = data->env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, "HOME", 5))
		{
			if ((!chdir(tmp->var)) == 0)
				ft_putstr_fd("minishell: cd: No such file or directory\n", 2);
			ft_update_pwd(&data->env, pwd, oldpwd, current);
			ft_update_pwd(&data->export, pwd, oldpwd, current);
			break ;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		ft_putstr_fd("Minishell: cd: HOME not set\n", 2);
}

void	ft_update_pwd(t_env **env, char *pwd, char *oldpwd, t_env *current)
{
	char	buffer[PATH_MAX + 1];

	pwd = (getcwd(buffer, PATH_MAX));
	current = *env;
	while (current)
	{
		if (!ft_strncmp(current->name, "PWD", 4))
		{
			oldpwd = ft_strdup(current->var);
			free(current->var);
			current->var = ft_strdup(pwd);
		}
		current = current->next;
	}
	current = *env;
	while (current)
	{
		if (!ft_strncmp(current->name, "OLDPWD", 7))
		{
			free(current->var);
			current->var = ft_strdup(oldpwd);
			free(oldpwd);
		}
		current = current->next;
	}
}
