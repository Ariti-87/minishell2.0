/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:21:23 by arincon           #+#    #+#             */
/*   Updated: 2023/10/17 11:55:50 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Count the number of tokens of a specific type in a token list.
int	ft_token_type_nb(t_token *list, enum e_type type)
{
	int		i;
	t_token	*tmp;

	i = 0;
	tmp = list;
	while (list)
	{
		if (list->type == type)
			i++;
		list = list->next;
	}
	list = tmp;
	return (i);
}

// Count the number of consecutive tokens of a specific type in a token list.
int	ft_type_nb(t_token *nlist, enum e_type type)
{
	int		i;
	t_token	*current;

	i = 0;
	current = nlist;
	while (current && current->type == type)
	{
		i++;
		current = current->next;
	}
	return (i);
}

// Tokenize the next group tokens from the token list.
t_token	*ft_tokenize(int next_gr, t_token *nlist)
{
	t_token	*t;
	t_token	*current;

	current = nlist;
	t = ft_calloc(1, sizeof(t_token));
	if (!t)
		return (NULL);
	t->str = NULL;
	while (next_gr > 0 && current)
	{
		t->str = ft_strjoin_free(t->str, current->str, 1, 0);
		current = current->next;
		next_gr--;
	}
	t->type = ft_type_token(*t->str);
	t->next = NULL;
	return (t);
}

// Parse the token list and tokenize it
// based on consecutive tokens of the same type
void	ft_parser_list(t_data *data)
{
	int		i;
	t_token	*current;

	i = 0;
	current = data->tlist;
	while (current)
	{
		if (current->type == SEPARATOR && *current->str == '|')
		{
			ft_lstadd_back_token(&data->plist, ft_tokenize(1, current));
			current = current->next;
		}
		else
		{
			i = ft_type_nb(current, current->type);
			ft_lstadd_back_token(&data->plist, ft_tokenize(i, current));
			while (i > 0 && current)
			{
				current = current->next;
				i--;
			}
		}
	}
}

// Main parser function that processes the token list.
void	ft_parser(t_data *data)
{
	ft_parser_list(data);
	ft_clear_space(data, data->plist);
	print_lexer(&data->plist);
	//ft_parser_redirec(data, data->plist);
	//ft_clear_quote(data);
	// print_lexer(&data->plist);
	return ;
}
