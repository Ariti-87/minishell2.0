/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:44:43 by ddania-c          #+#    #+#             */
/*   Updated: 2023/10/19 17:05:09 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	ft_update_quote(char c, int qoute)
{
	if (c == '\'' && qoute == N_QUOTE)
		qoute = S_QUOTE;
	else if (c == '\"' && qoute == N_QUOTE)
		qoute = D_QUOTES;
	else if (c == '\'' && qoute == S_QUOTE)
		qoute = N_QUOTE;
	else if (c == '\"' && qoute == D_QUOTES)
		qoute = N_QUOTE;
	return (qoute);
}

bool	ft_next_sep(char c)
{
	if (c == '$' || c == ' ' || c == '=' || c == '\0')
		return (true);
	else
		return (false);
}

bool	ft_between_quotes(char *str, int i)
{
	if (i > 0)
	{
		if (str[i - 1] == '\"' && str[i + 1] == '\"')
			return (true);
		else
			return (false);
	}
	return (false);
}
