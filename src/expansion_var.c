/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:44:43 by ddania-c          #+#    #+#             */
/*   Updated: 2023/10/19 13:16:46 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_expansion_var(t_token **token_list)
{
	t_token	*temp;
	int		i;

	temp = *token_list;
	while (temp)
	{
		i = 0;
		while (temp->str[i])
		{
			if (temp->str[i] == '$')
			{
				temp->type = END;
				return ;
			}
			i++;
		}
		temp = temp->next;
	}
	return ;
}
