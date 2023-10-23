/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:06:32 by arincon           #+#    #+#             */
/*   Updated: 2023/10/13 15:53:34 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	*ft_last_status(void)
{
	static int	last_s = 0;

	return (&last_s);
}

int	ft_get_last_status(void)
{
	return (*ft_last_status());
}

void	ft_set_last_status(int status)
{
	*ft_last_status() = status;
}

void	ft_return_status(t_data *data, int status)
{
	if (data->cmds_nb > 1)
	{
		ft_close_and_free(data);
		exit(status);
	}
	else
		ft_set_last_status(status);
}
