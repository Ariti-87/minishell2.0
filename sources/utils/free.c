/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:30:29 by arincon           #+#    #+#             */
/*   Updated: 2023/10/24 17:48:51 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Frees memory allocated for a string array
void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}


void	ft_free_list_lexer(t_token **list)
{
	int		i;
	t_token	*tmp;

	i = 0;
	while (*list)
	{
		if ((*list)->str)
			free((*list)->str);
		i++;
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
	*list = NULL;
}

void	ft_free_parsing(t_data *data)
{
	if (data->token)
		ft_free_list_lexer(&data->token);
}
