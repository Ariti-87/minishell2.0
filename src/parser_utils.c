/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:28:51 by arincon           #+#    #+#             */
/*   Updated: 2023/10/16 13:28:43 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

int	ft_cmd_count(t_data *data)
{
	int		i;
	t_token	*current;

	i = 1;
	current = data->plist;
	while (current)
	{
		if (current->type == SEPARATOR)
		{
			if (*current->str == '|')
				i++;
		}
		current = current->next;
	}
	return (i);
}
