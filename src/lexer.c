/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:14:20 by arincon           #+#    #+#             */
/*   Updated: 2023/10/13 15:26:15 by arincon          ###   ########.fr       */
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
t_token	*ft_token(char *str, char quote)
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
	return (token);
}

// Tokenize an input line and add tokens to a token list, considering quotes.
void	ft_lexer(t_data *data, char *line)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (line && line[i])
	{
		if (quote && quote == line[i] && ft_belong("'\"", line[i]))
			quote = 0;
		else if (!quote && ft_belong("'\"", line[i]))
			quote = line[i];
		ft_lstadd_back_token(&data->tlist, ft_token(&line[i], quote));
		i++;
	}
}
