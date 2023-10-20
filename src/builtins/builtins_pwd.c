/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:21:28 by arincon           #+#    #+#             */
/*   Updated: 2023/10/13 15:23:05 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(void)
{
	char	buffer[PATH_MAX + 1];

	if (getcwd(buffer, PATH_MAX))
		printf("%s\n", buffer);
	else
		ft_putstr_fd("Error: pwd: \n", 2);
}
