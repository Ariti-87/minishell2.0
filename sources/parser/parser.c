/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:12:28 by ddania-c          #+#    #+#             */
/*   Updated: 2023/11/01 15:05:29 by ddania-c         ###   ########.fr       */
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

static bool	ft_check_ampersand(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] == c)
			return (true);
		i++;
	}
	return (false);
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
	else if (ft_check_ampersand(token->str, '&') == true
		|| ft_check_ampersand(token->str, ';') == true)
		return (true);
	return (false);
}

static bool	ft_parser_error(t_token *token)
{
	t_token	*temp;

	temp = token;
	if (temp->type == PIPE)
	{
		ft_putstr_fd("syntax error near unexpected token\n", 2);
		return (true);
	}
	while (temp)
	{
		if (ft_check_sep_parser(temp) == true)
		{
			ft_putstr_fd("syntax error near unexpected token\n", 2);
			return (true);
		}
		ft_set_io(temp);
		temp = temp->next;
	}
	return (false);
}

int	ft_parser(t_data *data)
{
	ft_expansion_var(data);
	if (ft_lexer(data, data->line) != 0)
		return (1);
	if (ft_parser_error(data->token) != 0)
		return (2);
	ft_clear_quotes(data);
	return (0);
}
