/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:12:11 by arincon           #+#    #+#             */
/*   Updated: 2023/10/25 12:12:33 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isbuiltins(char *str)
{
	if (!ft_strncmp(str, "echo", 5))
		return (1);
	if (!ft_strncmp(str, "exit", 5))
		return (1);
	if (!ft_strncmp(str, "export", 7))
		return (1);
	if (!ft_strncmp(str, "env", 4))
		return (1);
	if (!ft_strncmp(str, "cd", 3))
		return (1);
	if (!ft_strncmp(str, "pwd", 4))
		return (1);
	if (!ft_strncmp(str, "unset", 6))
		return (1);
	return (0);
}
