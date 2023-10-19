/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:05:22 by ddania-c          #+#    #+#             */
/*   Updated: 2023/10/19 18:26:04 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_set_io(t_token *token)
{
	if (token->type == LESS)
		token->next->type = INPUT;
	else if (token->type == LESS_LESS)
		token->next->type = HEREDOC;
	else if (token->type == GREAT || token->type == GREAT_GREAT)
		token->next->type = OUTPUT;
}

static bool	ft_check_sep_parser(t_token *token)
{
	if (token->type == PIPE && (token->next->type == END
		|| token->next->type == PIPE))
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

int	ft_parser_error(t_token *token)
{
	t_token	*temp;

	temp = token;
	if (temp->type == PIPE)
	{
			ft_putstr_fd("syntax error near unexpected token\n", 2);
			return (2);
	}
	while (temp)
	{
		if (ft_check_sep_parser(temp) == true)
		{
			ft_putstr_fd("syntax error near unexpected token\n", 2);
			return (2);
		}
		ft_set_io(temp);
		temp = temp->next;
	}
	return (0);
}
