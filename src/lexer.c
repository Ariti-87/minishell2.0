/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/10/18 18:48:50 by ddania-c         ###   ########.fr       */
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
		printf("[%u__%s__]\n", current->type, current->str);
		current = current->next;
	}
	printf("\n");
}

static int	ft_set_sep_type(char *line, int i)
{
	if (((line[i] > 8 && line[i] < 14) || line[i] == 32))
		return (SPACES);
	else if (line[i] == '|')
		return (PIPE);
	else if (line[i] == '<' && line[i + 1] == '<')
		return (LESS_LESS);
	else if (line[i] == '>' && line[i + 1] == '>')
		return (GREAT_GREAT);
	else if (line[i] == '<')
		return (LESS);
	else if (line[i] == '>')
		return (GREAT);
	else if (line[i] == '\0')
		return (END);
	return (0);
}
//
static int	ft_token(int *i, char *line, int start, t_data *data)
{
	int	sep_type;

	sep_type = ft_set_sep_type(line, (*i));
	if (sep_type)
	{
		if ((*i) != 0 && ft_set_sep_type(line, (*i) - 1) == 0)
			ft_add_word(&data->token, line, (*i), start);
		if (sep_type == PIPE || sep_type == LESS || sep_type == GREAT
			|| sep_type == END)
			ft_add_sep(&data->token, line, (*i), 2,sep_type);
		else if (sep_type == LESS_LESS || sep_type == GREAT_GREAT)
		{
			ft_add_sep(&data->token, line, (*i), 3,sep_type);
			(*i)++;
		}
		start = 1 + (*i);
	}
	return (start);
}

int	ft_lexer(t_data *data, char *line)
{
	int	i;
	int	quote;
	int	start;
	int	end;

	end = ft_strlen(line);
	start = 0;
	i = 0;
	quote = N_QUOTE;
	while (i <= end)
	{
		quote = ft_set_status_quote(quote, line, i);
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
	if (quote != N_QUOTE)
	{
		ft_putstr_fd("error: unclosed quotes\n", 2);
		return (1);
	}
	return (0);
}
