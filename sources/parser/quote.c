/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:03:34 by arincon           #+#    #+#             */
/*   Updated: 2023/10/25 16:12:29 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Make a new str without the quotes
static char	*ft_remove_quotes(char *line, int to_remove, int quote)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * ((ft_strlen(line) - to_remove) + 1));
	if (!str)
	{
		ft_putstr_fd("error: malloc\n", 2);
		return (NULL);
	}
	while (*line)
	{
		quote = ft_update_quote(*line, quote);
		if ((*line == '\'' && quote == S_QUOTE) || (*line == '\"'
				&& quote == D_QUOTES) || (*line == '\'' && quote == N_QUOTE)
			|| (*line == '\"' && quote == N_QUOTE))
			line++;
		else
		{
			str[i] = *line++;
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

// Count the quantity of quote that should be delete
static void	ft_quote_counter(char *str, int *quote, int *count)
{
	while (*str)
	{
		if (*str == '\'' && *quote == N_QUOTE)
		{
			*quote = S_QUOTE;
			(*count)++;
		}
		else if (*str == '\"' && *quote == N_QUOTE)
		{
			*quote = D_QUOTES;
			(*count)++;
		}
		else if ((*str == '\'' && *quote == S_QUOTE)
			|| (*str == '\"' && *quote == D_QUOTES))
		{
			*quote = N_QUOTE;
			(*count)++;
		}
		str++;
	}
}

// Clear quotes and variables in a list of tokens.
void	ft_clear_quotes(t_data *data)
{
	t_token	*current;
	int		quote;
	int		quote_count;
	char	*new_str;

	current = data->token;
	while (current && current->type != END)
	{
		quote = N_QUOTE;
		quote_count = 0;
		ft_quote_counter(current->str, &quote, &quote_count);
		if (quote_count > 0)
		{
			new_str = ft_remove_quotes(current->str, quote_count, quote);
			free(current->str);
			current->str = new_str;
		}
		current = current->next;
	}
}
