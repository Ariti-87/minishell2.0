/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:05:22 by ddania-c          #+#    #+#             */
/*   Updated: 2023/10/18 17:05:24 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_check_sep_lexer(t_token *token)
{
	if (token->type == PIPE && (token->next->type == END
		|| token->next->type == PIPE || token->next->type != WORD))
		return (true);
	else if (token->type == GREAT && (token->next->type == END
		|| token->next->type == PIPE || token->next->type != WORD))
		return (true);
	else if (token->type == LESS && (token->next->type == END
		|| token->next->type == PIPE || token->next->type != WORD))
		return (true);
	else if (token->type == GREAT_GREAT && (token->next->type == END
		|| token->next->type == PIPE || token->next->type != WORD))
		return (true);
	else if (token->type == LESS_LESS && (token->next->type == END
		|| token->next->type == PIPE || token->next->type != WORD))
		return (true);
	return (false);
}

void	ft_lexer_error(t_token *token)
{
	t_token	*temp;

	temp = token;
	if (temp->type == PIPE)
	{
			ft_putstr_fd("syntax error near unexpected token\n", 2);
			return ;
	}
	while (temp)
	{
		if (ft_check_sep_lexer(temp) == true)
		{
			ft_putstr_fd("syntax error near unexpected token\n", 2);
			return ;
		}
		temp = temp->next;
	}
	return ;
}
