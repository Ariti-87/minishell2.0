/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:44:43 by ddania-c          #+#    #+#             */
/*   Updated: 2023/10/19 17:05:05 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_expansion_var(t_data *data)
{
	t_token	*temp;
	int		i;
	int		quote;

	quote = N_QUOTE;
	temp = data->token;
	while (temp)
	{
		i = 0;
		while (temp->str[i])
		{
			quote = ft_update_quote(temp->str[i], quote);
			if (temp->str[i] == '$'
				&& ft_next_sep(temp->str[i + 1] == false)
				&& ft_between_quotes(temp->str, i) == false
				&& (quote == N_QUOTE || quote == D_QUOTES))
				temp->str[i] = '1';
			i++;
		}
		temp = temp->next;
	}
}
