/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:21:28 by arincon           #+#    #+#             */
/*   Updated: 2023/10/30 12:17:31 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(void)
{
	char	buffer[PATH_MAX + 1];

	if (getcwd(buffer, PATH_MAX))
		printf("%s\n", buffer);
	else
	{
		ft_putstr_fd("Error: pwd: \n", 2);
		g_last_status = 127;
	}
	g_last_status = 0;
}
