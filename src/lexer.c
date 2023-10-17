/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:14:20 by arincon           #+#    #+#             */
/*   Updated: 2023/10/17 17:54:59 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Print the contents of a token list.
void	print_lexer(t_token **list)
{
	t_token	*current;

	current = *list;
	while (current)
	{
		printf("[%u__%s__]", current->type, current->str);
		current = current->next;
	}
	printf("\n");
}

// Determine the type of a token based on a character.
int	ft_type_token(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (SEPARATOR);
	return (ALPHANUM);
}

// Add a token to the end of a token list.
void	ft_lstadd_back_token(t_token **lst, t_token *n)
{
	t_token	*r;

	if (!n)
		return ;
	if (!lst || !*lst)
		*lst = n;
	else
	{
		r = *lst;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = n;
		*lst = r;
	}
}

// Create a token structure based on a string and a quote character.
int	*ft_token(char *str, char quote)
{
	t_token	*token;

	if (!str)
		return (NULL);
	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	if (quote)
		token->type = ALPHANUM;
	else
		token->type = ft_type_token(*str);
	token->str = ft_calloc(2, sizeof(char));
	if (!token->str)
		return (NULL);
	*(token->str) = *str;
	token->next = NULL;
	return (start);
}

int	set_status_quote(int quote, char *line, int i)
{
	if (line[i] == '\'' && quote == N_QUOTE)
		quote = S_QUOTE;
	else if (line[i] == '\"' && quote == N_QUOTE)
		quote = D_QUOTES;
	else if (line[i] == '\'' && quote == S_QUOTE)
		quote = N_QUOTE;
	else if (line[i] == '\"' && quote == D_QUOTES)
		quote = D_QUOTES;
	// ft_lstadd_back_token(&data->tlist, ft_token(&line[i], quote));
	return (quote);
}

// Tokenize an input line and add tokens to a token list, considering quotes.
int	ft_lexer(t_data *data, char *line)
{
	int	i;
	int	quote;
	int	start;

	start = 0;
	i = 0;
	quote = N_QUOTE;
	while (line && line[i])
	{
		quote = set_status_quote(quote, line, i);
		if (quote == N_QUOTE)
			start = ft_token(&i, line, start, data);
		i++;
	}
	if (quote != N_QUOTE)
	{
		ft_putstr_fd("error: unclosed quotes\n", 2);
		return (1);
	}
	return (0);
}
