/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:24:03 by arincon           #+#    #+#             */
/*   Updated: 2023/09/26 17:13:26 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_env *env, char **argv)
{
	t_env	*tmp;

	tmp = env;
	while (tmp && !argv[1])
	{
		if (tmp->name && tmp->var)
			printf("%s=%s\n", tmp->name, tmp->var);
		else if (tmp->name && !tmp->var)
			printf("%s=\n", tmp->name);
		tmp = tmp->next;
	}
	if (argv[1])
		ft_putstr_fd("minishell: env: too many arguments\n", 2);
}
