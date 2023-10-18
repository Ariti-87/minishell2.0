/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:28:51 by arincon           #+#    #+#             */
/*   Updated: 2023/10/18 17:12:46 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	ft_strlen_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab && tab[i])
// 		i++;
// 	return (i);
// }

int	ft_cmd_count(t_data *data)
{
	int		i;
	t_token	*current;

	i = 1;
	current = data->token;
	while (current)
	{
		if (current->type == PIPE)
			i++;
		current = current->next;
	}
	return (i);
}
