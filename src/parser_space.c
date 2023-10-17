/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:36:39 by arincon           #+#    #+#             */
/*   Updated: 2023/10/16 11:16:34 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Check if a string consists of only white spaces (spaces or tabs).
static int	ft_is_space(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

// Move a token from one list to another and update the pointers.
static void	ft_list_space(t_token **list, t_token **plist, t_token **nlist)
{
	*plist = *list;
	*list = (*list)->next;
	if (*list)
		*nlist = (*list)->next;
}

// Remove tokens containing only white spaces from the token list
void	ft_clear_space(t_data *data, t_token *list)
{
	t_token	*nlist;
	t_token	*plist;
	t_token	*token;
	t_token	*tmp;

	plist = NULL;
	tmp = list;
	while (list)
	{
		token = NULL;
		if (list->type == ALPHANUM)
		{
			if (ft_is_space(list->str))
			{
				token = list;
				if (!plist)
					data->plist = list->next;
				else
					plist->next = list->next;
			}
		}
		ft_list_space(&list, &plist, &nlist);
		ft_free_token(&token);
	}
	list = tmp;
}
