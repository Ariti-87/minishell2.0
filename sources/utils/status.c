/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:06:32 by arincon           #+#    #+#             */
/*   Updated: 2023/10/23 17:43:08 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_set_last_status(t_data *data, int status)
{
	g_last_status = status;
	free(data->env->var);
	data->env->var = ft_itoa(g_last_status);
	return (status);
}
